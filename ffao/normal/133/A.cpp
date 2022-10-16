#include <string.h>
#include <stdio.h>

char inst[110];

int main () {
    gets(inst);
    
    int prod = 0;
    int len = strlen(inst);
    for (int i = 0; i < len; i++) {
        if (inst[i] == 'H' || inst[i] == 'Q' || inst[i] == '9') prod = 1;
    }
    
    if (prod) printf("YES\n");
    else printf("NO\n");
}