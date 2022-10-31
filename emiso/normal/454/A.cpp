#include <stdio.h>

int n, i, j;

int main() {
    scanf("%d", &n);
    for(i = 0; i < n / 2; i++) {
        for(j = 0; j < n / 2 - i; j++) printf("*");
        for(j = 0; j < 2*i+1; j++)     printf("D");
        for(j = 0; j < n / 2 - i; j++) printf("*");
        puts("");
    }

    for(i = n / 2; i >= 0; i--) {
        for(j = 0; j < n / 2 - i; j++) printf("*");
        for(j = 0; j < 2*i+1; j++)     printf("D");
        for(j = 0; j < n / 2 - i; j++) printf("*");
        puts("");
    }

    return 0;
}