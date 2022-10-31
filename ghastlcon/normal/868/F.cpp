#include <iostream>
#include <algorithm>
#include <cstdio>
#include <climits>
#define N 100020
#define M 30
using namespace std;

int n, a[N];
long long f[M][N];
int l, r, g[N];
long long s;

void Addsum(int x, int v)
{
    s += (long long)x * (x - 1) * v;

    return;
}

long long SumChunk(int s, int t)
{
    while(l > s)
    {
        l --;
        Addsum(g[a[l]], -1);
        g[a[l]] ++;
        Addsum(g[a[l]],  1);
    }
    while(r < t)
    {
        r ++;
        Addsum(g[a[r]], -1);
        g[a[r]] ++;
        Addsum(g[a[r]],  1);
    }
    while(l < s)
    {
        Addsum(g[a[l]], -1);
        g[a[l]] --;
        Addsum(g[a[l]],  1);
        l ++;
    }
    while(r > t)
    {
        Addsum(g[a[r]], -1);
        g[a[r]] --;
        Addsum(g[a[r]],  1);
        r --;
    }

    return ::s;
}

void CDQ(int x, int l, int r, int s, int t)
{
    int i, m;
    long long p, q;

    if(l > r)
        return;

    m = (l + r) >> 1;
    for(i = s, p = LLONG_MAX, q = -1; i <= min(t, m); i ++)
        if(p > f[x - 1][i - 1] + SumChunk(i, m))
        {
            p = f[x - 1][i - 1] + SumChunk(i, m);
            q = i;
        }

    f[x][m] = p;
    CDQ(x, l    , m - 1, s, q);
    CDQ(x, m + 1, r    , q, t);

    return;
}

int main(void)
{
    int m;
    int i;

    scanf("%d %d", &n, &m);
    for(i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    l = 1;
    r = 0;

    for(i = 1; i <= n; i ++)
        f[1][i] = SumChunk(1, i);
    // for(i=1;i<=n;i++)cout<<f[1][i]<<' ';cout<<endl;
    for(i = 2; i <= m; i ++)
        CDQ(i, 1, n, 1, n);
    printf("%I64d\n", f[m][n] / 2);

    return 0;
}