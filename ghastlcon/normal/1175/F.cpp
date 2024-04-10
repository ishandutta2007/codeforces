#include <iostream>
#include <algorithm>
#include <cstdio>
#include <random>
#define N 300020
#pragma GCC optimize("O3")
using namespace std;

int n, a[N];
unsigned long long f[N], g[N], h[N];

int Solve(int x)
{
    int i, p, o;

    for(i = x + 1, p = x, o = 0; i <= n && a[i] != 1; i ++)
    {
        if(a[i] > a[p])
            p = i;
        if(i - a[p] > -1 && h[a[p]] == (g[i] ^ g[i - a[p]]))
            o ++;
    }

    return o;
}

int main(void)
{
    int i, o;
    mt19937 k;

    scanf("%d", &n);
    for(i = 1; i <= n; i ++)
    {
        scanf("%d", &a[i]);
        f[i] = (unsigned long long)k() << (unsigned long long)32 | (unsigned long long)k();
        h[i] = h[i - 1] ^ f[i];
    }
    for(i = 1; i <= n; i ++)
        g[i] = g[i - 1] ^ f[a[i]];

    for(i = 1, o = 0; i <= n; i ++)
        if(a[i] == 1)
            o += Solve(i) + 1;
    reverse(a + 1, a + n + 1);
    for(i = 1; i <= n; i ++)
        g[i] = g[i - 1] ^ f[a[i]];
    for(i = 1; i <= n; i ++)
        if(a[i] == 1)
            o += Solve(i);
    printf("%d\n", o);

    return 0;
}