#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <climits>
#define N 500020
using namespace std;

int a[N], c[N];
int b[N], r[N];
long long f[N], g[N], h[N];

inline int Lowbit(int x)
{
    return x & -x;
}

void AddFenwick(int p, int v, int n)
{
    for(; p <= n; p += Lowbit(p))
        f[p] += v;

    return;
}

long long SumFenwick(int p)
{
    long long o;

    for(o = 0; p; p -= Lowbit(p))
        o += f[p];

    return o;
}

int main(void)
{
    int n, m;
    int i;

    scanf("%d", &n);
    for(i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    for(i = 1; i <= n; i ++)
        scanf("%d", &c[i]);
    scanf("%d", &m);
    for(i = 1; i <= m; i ++)
    {
        scanf("%d", &b[i]);
        r[b[i]] = i;
    }

    fill(h + 1, h + n + 1, LLONG_MIN >> 2);
    for(i = 1; i <= n; i ++)
    {
        if(c[i] > 0)
            AddFenwick(a[i], c[i], n);
        if(r[a[i]])
        {
            if(r[a[i]] == 1)
                g[i] = c[i];
            else
            {
                // printf("at %d : presum %lld, premax %lld\n", i, SumFenwick(b[r[a[i]] - 1]), h[r[a[i]] - 1]);
                g[i] = c[i] + SumFenwick(b[r[a[i]] - 1]) + h[r[a[i]] - 1];
            }
            // printf("%d:%lld, ins %lld\n", i, g[i], g[i] - SumFenwick(a[i]));
            h[r[a[i]]] = max(h[r[a[i]]], g[i] - SumFenwick(a[i]));
        }
    }

    if(h[m] < LLONG_MIN >> 4)
        printf("NO\n");
    else
    {
        // printf("val %lld\n", h[m]);
        h[m] += SumFenwick(b[m]);
        for(i = 1, h[m] = -h[m]; i <= n; i ++)
            h[m] += c[i];
        printf("YES\n%lld\n", h[m]);
    }

    return 0;
}