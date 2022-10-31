#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define N 100020
#define M 40
#define K 197
#define MOD 998244357
using namespace std;

int n, m;
char a[N], b[N];
int g[N], h[N], p[N];
int f[N][M];

inline int Hash(int *f, int l, int r)
{
    return ((f[r] - (long long)f[l - 1] * p[r - l + 1]) % MOD + MOD) % MOD;
}

int LCP(int x, int y)
{
    int l, m, r;

    for(l = 0, r = min(n - x + 1, ::m - y + 1) + 1; l + 1 < r; )
    {
        m = (l + r) >> 1;
        if(Hash(g, x, x + m - 1) == Hash(h, y, y + m - 1))
            l = m;
        else
            r = m;
    }

    return l;
}

int main(void)
{
    int k;
    int i, j, t;

    scanf("%d %s %d %s %d", &n, a + 1, &m, b + 1, &k);
    for(i = 1; i <= n; i ++)
        g[i] = ((long long)g[i - 1] * K + a[i]) % MOD;
    for(i = 1; i <= m; i ++)
        h[i] = ((long long)h[i - 1] * K + b[i]) % MOD;
    for(i = p[0] = 1; i < N; i ++)
        p[i] = (long long)p[i - 1] * K % MOD;

    for(i = 0; i <= n; i ++)
        for(j = 0; j <= k; j ++)
        {
            f[i + 1][j] = max(f[i + 1][j], f[i][j]);
            t = LCP(i + 1, f[i][j] + 1);
            f[i + t][j + 1] = max(f[i + t][j + 1], f[i][j] + t);
        }
    printf("%s\n", f[n][k] == m ? "YES" : "NO");

    return 0;
}