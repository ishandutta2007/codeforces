#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define N 100020
#define M 320
#define K 17
#define MOD 1000000007
using namespace std;

int n, a[N], b[N];
vector<int> e[N];
int l[N], r[N], d[N];
int f[N], g[K][N], h[N][M];

inline int Lowbit(int x)
{
    return x & -x;
}

void AddFenwick(int p, int v)
{
    for(; p <= n; p += Lowbit(p))
        f[p] += v;

    return;
}

int SumFenwick(int p)
{
    int o;

    for(o = 0; p; p -= Lowbit(p))
        o += f[p];

    return o;
}

void AddPoint(int x, int v)
{
    AddFenwick(l[x]    ,  1 * v);
    AddFenwick(r[x] + 1, -1 * v);

    return;
}

int GetLCA(int u, int v)
{
    int i, t;

    if(d[u] < d[v])
        swap(u, v);
    t = d[u] - d[v];

    for(i = 0; i < K; i ++)
        if(t & (1 << i))
            u = g[i][u];
    if(u == v)
        return u;

    for(i = K - 1; i > -1; i --)
        if(g[i][u] != g[i][v])
        {
            u = g[i][u];
            v = g[i][v];
        }

    return g[0][u];
}

int SumChain(int u, int v)
{
    int t;

    t = GetLCA(u, v);

    return SumFenwick(l[u]) + SumFenwick(l[v]) - SumFenwick(l[t]) - (t != 1 ? SumFenwick(l[g[0][t]]) : 0);
}

void DFS(int x, int p)
{
    static int k;
    int i;

    for(i = 1, g[0][x] = p; i < K; i ++)
        g[i][x] = g[i - 1][g[i - 1][x]];

    l[x] = ++ k;
    for(i = 0; i < (signed)e[x].size(); i ++)
        if(e[x].at(i) != p)
        {
            d[e[x].at(i)] = d[x] + 1;
            DFS(e[x].at(i), x);
        }
    r[x] = k;

    return;
}

int main(void)
{
    int q, k, m, r, u, v;
    int i, j, o;

    scanf("%d %d", &n, &q);
    for(i = 1; i < n; i ++)
    {
        scanf("%d %d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    DFS(1, 1);

    while(q --)
    {
        scanf("%d %d %d", &k, &m, &r);
        for(i = 1; i <= k; i ++)
        {
            scanf("%d", &a[i]);
            AddPoint(a[i], 1);
        }
        for(i = 1; i <= k; i ++)
            b[i] = SumChain(a[i], r);
        for(i = 1; i <= k; i ++)
            AddPoint(a[i], -1);
        sort(b + 1, b + k + 1);

        h[0][0] = 1;
        for(i = 1; i <= k; i ++)
            for(j = 1; j <= m; j ++)
                h[i][j] = (h[i - 1][j - 1] + (j >= b[i] - 1 ? (long long)(j - b[i] + 1) * h[i - 1][j] : 0)) % MOD;
        for(i = o = 0; i <= m; i ++)
            o = (o + h[k][i]) % MOD;
        printf("%d\n", o);
    }

    return 0;
}