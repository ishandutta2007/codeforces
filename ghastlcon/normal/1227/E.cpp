// #pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define N 1000020
using namespace std;

int n, m;
char *a[N];
int *f[N], *g[N];
bool *o[N];

bool Check(int l)
{
    int i, j;

    for(i = 0; i <= n; i ++)
        for(j = 0; j <= m; j ++)
            g[i][j] = o[i][j] = 0;

    l = l << 1 | 1;
    for(i = 1; i <= n - l + 1; i ++)
        for(j = 1; j <= m - l + 1; j ++)
            if(f[i + l - 1][j + l - 1] - f[i + l - 1][j - 1] - f[i - 1][j + l - 1] + f[i - 1][j - 1] == l * l)
            {
                o[i + (l >> 1)][j + (l >> 1)] = true;
                g[i][j] ++;
                g[i + l][j] --;
                g[i][j + l] --;
                g[i + l][j + l] ++;
            }

    for(i = 1; i <= n; i ++)
        for(j = 1; j <= m; j ++)
        {
            g[i][j] += g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1];
            if(!g[i][j] && a[i][j] == 'X')
                return false;
        }

    return true;
}

int main(void)
{
    int i, j, l, r;

    scanf("%d %d", &n, &m);
    for(i = 0; i <= n + 1; i ++)
    {
        f[i] = new int[m + 2];
        g[i] = new int[m + 2];
        o[i] = new bool[m + 2];
    }
    for(i = 1; i <= n; i ++)
    {
        a[i] = new char[m + 2];
        scanf("%s", a[i] + 1);
        for(j = 1; j <= m; j ++)
            f[i][j] = (a[i][j] == 'X') + f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
    }

    for(l = 0, r = min(n, m) + 1; l + 1 < r; )
        if(Check((l + r) >> 1))
            l = (l + r) >> 1;
        else
            r = (l + r) >> 1;
    printf("%d\n", l);

    Check(l);
    for(i = 1; i <= n; i ++)
    {
        for(j = 1; j <= m; j ++)
            putchar(o[i][j] ? 'X' : '.');
        putchar('\n');
    }

    return 0;
}