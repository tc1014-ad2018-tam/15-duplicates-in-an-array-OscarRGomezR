/*
Write nana program that inputs n number of integer values and return how many of that numbers are duplicate.

Name: Óscar Rubén Gómez Ríos
Correo:A01411750@itesm.mx
Matricule Number: A01411750

 */

#include <stdio.h>
#include <stdlib.h>

int nana(const void *a, const void *b) {
    return ( *(int*)a - *(int*)b );
}

int main() {

    int c;
    int d;
    int counter = 0;
    int duplicates = 0;
    int repetition;

    printf("How many numbers would you like?\n");
    scanf("%i", &d);

    int arr[d];

    printf("Give me %i numbers:\n", d);

    for (int i = 0; i < d; i++) {
        printf("Give me number %i:\n", i + 1);
        scanf("%i", &c);
        arr[i] = c;
    }

    qsort(arr, d, sizeof(int), nana);

    for (int i = 0; i < d; i += counter+1) {

        counter = 0;

        do {
            if (arr[i] == arr[i+counter+1]) {
                counter++;
                repetition = 1;
            } else {
                repetition = 0;
            }
        } while (repetition == 1);

        if (counter > 0) {
            duplicates++;
        }

    }

    printf("The amount of duplicated numbers is %i.", duplicates);

    return 0;

}