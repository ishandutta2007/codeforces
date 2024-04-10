#include<cstdio>
#include<algorithm>
#define MAXN 60
char s[MAXN][MAXN];
int c[4];
int main(){
    for(int i = 0; i < 4; i += 1) scanf("%d", c + i);
    for(int i = 0; i < c[0] - 1; i += 1)
        s[i / 25 * 2][i % 25 * 2] = 'A';
    for(int i = 0; i < 10; i += 1)
        for(int j = 0; j < 50; j += 1)
            if(s[i][j] == 0) s[i][j] = 'B';
    c[1] -= 1;
    for(int i = 10; i < 50; i += 1)
        for(int j = 0; j < 50; j += 1){
            s[i][j] = 'A';
            if(i % 2 == 1 && j % 2 == 1)for(int k = 1; k < 4; k += 1) if(c[k]){
                c[k] -= 1;
                s[i][j] = 'A' + k;
                break;
            }
        }
    printf("50 50\n");
    for(int i = 0; i < 50; i += 1)
        printf("%s\n", s[i]);
}