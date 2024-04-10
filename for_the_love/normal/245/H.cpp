#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int f[5002][5002];
int g[5002][5002];
char s[5002];
int n, i, j, l, r, q;
int main(){
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (i = 1; i <= n; i++)
    for (j = 1; j <= n - i + 1; j++){
        if (i == 1) f[j][j] = 1;
        else
        if (i == 2 && s[j] == s[j + 1]) f[j][j + 1] = 1;
        else f[j][j + i - 1] = (s[j] == s[j + i - 1]) & f[j + 1][j + i - 2];
    }
    for (i = 1; i <= n; i++)
    for (j = 1; j <= n - i + 1; j++)
        g[j][j + i - 1] += g[j + 1][j + i - 1] + g[j][j + i -2] - g[j + 1][j + i - 2] + f[j][j + i - 1];
    scanf("%d", &q);
    for (i = 0; i < q; i++){
        scanf("%d%d", &l, &r);
        printf("%d\n", g[l][r]);
    }
}