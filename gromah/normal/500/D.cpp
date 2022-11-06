#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef long double LD;
#define N 100000 + 5

int n, tot = 1, Head[N], Size[N], E[N], W[N];
LD ans;
LL A_n_3;

struct Edge
{
    int next, node, w;
}h[N << 1];

inline void addedge(int u, int v, int w)
{
    h[++ tot].next = Head[u], Head[u] = tot;
    h[tot].node = v, h[tot].w = w;
    h[++ tot].next = Head[v], Head[v] = tot;
    h[tot].node = u, h[tot].w = w;
}

inline void dfs(int z, int fa)
{
    Size[z] = 1;
    for (int i = Head[z]; i; i = h[i].next)
    {
        int d = h[i].node;
        if (d == fa) continue ;
        dfs(d, z);
        Size[z] += Size[d];
        W[i >> 1] = Size[d];
    }
}

inline LD Calc(int pos, int delta)
{
    LL t_1 = (LL) W[pos] * (W[pos] - 1) * (n - W[pos]) * 6;
    LL t_2 = (LL) W[pos] * (n - W[pos]) * (n - W[pos] - 1) * 6;
    LD t = (LD) (t_1 + t_2) / A_n_3;
    return t * delta;
}

int main()
{
    scanf("%d", &n);
    A_n_3 = (LL) n * (n - 1) * (n - 2);
    for (int i = 1; i < n; i ++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        addedge(u, v, w);
        E[i] = w;
    }
    dfs(1, 0);
    for (int i = 1; i < n; i ++)
        ans += Calc(i, E[i]);
    int q;
    scanf("%d", &q);
    while (q --)
    {
        int pos, num;
        scanf("%d%d", &pos, &num);
        ans -= Calc(pos, E[pos]);
        ans += Calc(pos, num);
        E[pos] = num;
        printf("%.7lf\n", (double) ans);
    }

    
    return 0;
}