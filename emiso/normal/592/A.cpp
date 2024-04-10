#include <stdio.h>

char table[9][9],lixo;

int main() {
    for(int r=1;r<=8;r++) {
        for(int c=1;c<=8;c++) {
            scanf("%c",&table[r][c]);
        }
        scanf("%c",&lixo);
    }

    int menorA = 9, menorB = 9;

    for(int c=1;c<=8;c++) {
        int flagA = 0, flagB = 0;
        for(int r=1;r<=8;r++) {

            if(table[r][c] == 'W' && flagA == 0) {
                if(menorA > r-1) menorA = r-1;
            }
            if(table[r][c] == 'B') {
                flagA = 1;
            }
        }

        for(int r=8;r>=1;r--) {

            if(table[r][c] == 'B' && flagB == 0) {
                if(menorB > 8-r) menorB = 8-r;
            }

            if(table[r][c] == 'W') {
                flagB = 1;
            }
        }
    }
    if(menorA <= menorB) printf("A\n");
    else printf("B\n");

    return 0;
}