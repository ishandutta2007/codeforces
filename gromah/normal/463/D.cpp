#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 1000 + 5
#define M 1000000 + 5

int n, k, ans = 1, tot, A[N], Map[N][N], Head[N], Con[N];
bool In[N], Out[N];

struct Edge
{
    int next, node;
}h[M];

inline void addedge(int u, int v)
{
    h[++ tot].next = Head[u];
    Head[u] = tot;
    h[tot].node = v;
    In[v] = Out[u] = 1;
}

inline void dfs(int z)
{
    if (Con[z]) return ;
    int maxn = 0;
    for (int i = Head[z]; i; i = h[i].next)
    {
        int d = h[i].node;
        dfs(d);
        maxn = max(maxn, Con[d]);
    }
    Con[z] = maxn + 1;
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k; i ++)
    {
        for (int j = 1; j <= n; j ++)
            scanf("%d", A + j);
        for (int u = 1; u < n; u ++)
            for (int v = u + 1; v <= n; v ++)
                Map[A[u]][A[v]] ++;
    }
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            if (Map[i][j] == k)
                addedge(i, j);
    for (int i = 1; i <= n; i ++)
        if (Out[i] && !In[i])
        {
            dfs(i);
            ans = max(ans, Con[i]);
        }
    printf("%d\n", ans);
    return 0;
}