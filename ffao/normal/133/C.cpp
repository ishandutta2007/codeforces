#include <string.h>
#include <stdio.h>

int mod = 1000003;

int map[1000];
char inst[110];

int inverse(int a) {
    int b = 0;
    for (int i = 0; i < 8; i++) {
        b = b*2 + a%2;
        a /= 2;
    }
    return b;
}

int main () {
    gets(inst);
    
    int prev = 0;
    int len = strlen(inst);
    for (int i = 0; i < len; i++) {
        int rev = inverse(prev);
        int res = inverse(inst[i]);
        
        printf("%d\n", (rev-res+256)%256);
        
        prev = inst[i]; 
    }
}