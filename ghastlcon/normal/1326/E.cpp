#pragma GCC optimize("inline")
#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 300020
using namespace std;

int a[N], b[N], c[N];
int f[N << 2], g[N << 2];

void MaintainSegment(int x)
{
    g[x << 1] += g[x];
    g[x << 1 | 1] += g[x];
    f[x << 1] += g[x];
    f[x << 1 | 1] += g[x];
    g[x] = 0;

    return;
}

void AddSegment(int x, int l, int r, int s, int t, int v)
{
    int m;

    if(l > t || r < s)
        return;
    if(l >= s && r <= t)
    {
        g[x] += v;
        f[x] += v;

        return;
    }
    if(g[x])
        MaintainSegment(x);

    m = (l + r) >> 1;
    AddSegment(x << 1    , l    , m, s, t, v);
    AddSegment(x << 1 | 1, m + 1, r, s, t, v);
    f[x] = max(f[x << 1], f[x << 1 | 1]);

    return;
}

int main(void)
{
    int n;
    int i, o;

    scanf("%d", &n);
    for(i = 0; i < n; i ++)
    {
        scanf("%d", &a[i]);
        c[-- a[i]] = i;
    }
    for(i = 0; i < n; i ++)
    {
        scanf("%d", &b[i]);
        b[i] --;
    }

    AddSegment(1, 0, n - 1, 0, c[n - 1], 1);
    for(i = 0, o = n - 1; i < n; i ++)
    {
        for(; f[1] <= 0; o --)
            AddSegment(1, 0, n - 1, 0, c[o - 1], 1);
        printf("%d%c", o + 1, " \n"[i == n - 1]);
        AddSegment(1, 0, n - 1, 0, b[i], -1);
    }

    return 0;
}