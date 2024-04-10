#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 200020
#define K 97
#define P 998244353
using namespace std;

char a[N];
int f[2][N], k[N], c[N];

int Hash(int *f, int l, int r)
{
    return (f[r] - (long long)f[l - 1] * k[c[r] - c[l - 1]] % P + P) % P;
}

int main(void)
{
    int n, q, x, y, l;
    int i;

    scanf("%d %s", &n, a + 1);
    for(i = k[0] = 1; i <= n; i ++)
    {
        k[i] = (long long)k[i - 1] * K % P;
        c[i] = c[i - 1];
        f[0][i] = f[0][i - 1];
        f[1][i] = f[1][i - 1];
        if(a[i] == '0')
        {
            c[i] ++;
            f[0][i] = ((long long)f[0][i] * K + ( i & 1)) % P;
            f[1][i] = ((long long)f[1][i] * K + (~i & 1)) % P;
        }
    }

    scanf("%d", &q);
    while(q --)
    {
        scanf("%d %d %d", &x, &y, &l);
        printf("%s\n", c[x + l - 1] - c[x - 1] == c[y + l - 1] - c[y - 1] && Hash(f[x & 1], x, x + l - 1) == Hash(f[y & 1], y, y + l - 1) ? "Yes" : "No");
    }

    return 0;
}