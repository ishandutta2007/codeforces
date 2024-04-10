#include <string.h>
#include <stdio.h>

int mod = 1000003;

int map[1000];
char inst[110];

int main () {
    map['>']=8;
    map['<']=9;
    map['+']=10;
    map['-']=11;
    map['.']=12;
    map[',']=13;
    map['[']=14;
    map[']']=15;
    
    gets(inst);
    
    int prod = 0;
    int len = strlen(inst);
    for (int i = 0; i < len; i++) {
        int val = map[inst[i]];
        prod = (prod * 16) + val;
        prod = prod % mod; 
    }
    
    printf("%d\n", prod);
}