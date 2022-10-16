#include <stdio.h>
#include <cstring>

int a;
int pref = 22;
char s[100];
char prev[100];

int main() {
    scanf("%d", &a); gets(prev);
    gets(prev);
    pref = strlen(prev);
    
    for (int i = 1; i < a; i++) {
        gets(s);
        int j = 0;
        for (j = 0; s[j] != '\0' && j != pref; j++) {
            if (s[j] != prev[j]) break;
        }
        pref = j;
        strcpy(prev,s);
    }
    
    printf("%d\n",pref);
}