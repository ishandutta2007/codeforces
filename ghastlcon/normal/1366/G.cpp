#pragma GCC optimize("O3,inline,unroll-loops")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <climits>
#define N 10020
using namespace std;

char a[N], b[N];
int f[N][N], g[N], h[N];

int main(void)
{
    int n, m;
    int i, j;

    scanf("%s %s", a + 1, b + 1);
    n = (int)strlen(a + 1);
    m = (int)strlen(b + 1);

    for(i = 1; i <= n; i ++)
        g[i] = g[i - 1] + (a[i] == '.' ? -1 : 1);
    for(i = n; i >= 0; i --)
        for(j = i + 1; j <= n && g[j] >= g[i]; j ++)
            if(g[j] == g[i])
            {
                h[i] = j;
                break;
            }

    for(i = 0; i <= n; i ++)
        fill(f[i], f[i] + m + 1, INT_MIN);
    f[0][0] = 0;
    for(i = 0; i <= n; i ++)
        for(j = 0; j <= m; j ++)
        {
            f[i + 1][j] = max(f[i + 1][j], f[i][j]);
            if(i < n && j < m && a[i + 1] == b[j + 1])
                f[i + 1][j + 1] = max(f[i + 1][j + 1], f[i][j] + 1);
            if(h[i])
                f[h[i]][j] = max(f[h[i]][j], f[i][j] + h[i] - i);
        }
    printf("%d\n", n - f[n][m]);

    return 0;
}