#pragma GCC optimize("O3,inline,unroll-loops")
#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 2020
#define S 26
using namespace std;

char a[N], b[N];
int f[N][N], s[2][N][S];

int main(void)
{
    int t, n;
    int i, j;

    scanf("%d", &t);
    while(t --)
    {
        scanf("%d %s %s", &n, a + 1, b + 1);
        fill(s[0][n + 1], s[0][n + 1] + S, 0);
        fill(s[1][n + 1], s[1][n + 1] + S, 0);
        for(i = n; i >= 1; i --)
        {
            copy(s[0][i + 1], s[0][i + 1] + S, s[0][i]);
            copy(s[1][i + 1], s[1][i + 1] + S, s[1][i]);
            s[0][i][a[i] - 97] ++;
            s[1][i][b[i] - 97] ++;
        }

        for(i = 0; i < S; i ++)
            if(s[0][1][i] != s[1][1][i])
                break;
        if(i < S)
        {
            printf("-1\n");
            continue;
        }

        for(i = 1; i <= n; i ++)
            for(j = i; j <= n; j ++)
            {
                f[i][j] = f[i - 1][j] + 1;
                if(a[i] == b[j])
                    f[i][j] = min(f[i][j], f[i - 1][j - 1]);
                if(s[0][i + 1][b[j] - 97] > s[1][j + 1][b[j] - 97])
                    f[i][j] = min(f[i][j], f[i][j - 1]);
            }
        printf("%d\n", f[n][n]);
    }

    return 0;
}