#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 5000 + 5
#define INF 0x7fffffff
int n, m, ans, tot, w[N], head[N];
bool ok[N];
struct EDGE
{
    int next, node;
}h[N];
void addedge(int u, int v)
{
    h[++ tot].next = head[u], head[u] = tot;
    h[tot].node = v;
    h[++ tot].next = head[v], head[v] = tot;
    h[tot].node = u;
}
void begin()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++)
        scanf("%d", w + i);
    for (int i = 1; i <= m; i ++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        addedge(u, v);
    }
}
void work()
{
    for (int i = 1; i <= n; i ++)
    {
        int maxx = -INF, p;
        for (int j = 1; j <= n; j ++)
            if (!ok[j] && w[j] > maxx)
                maxx = w[j], p = j;
        ok[p] = 1;
        for (int j = head[p]; j; j = h[j].next)
        {
            int d = h[j].node;
            if (!ok[d]) ans += w[d];
        }
    }
}
void end()
{
    printf("%d\n", ans);
}
int main()
{
    begin();
    work();
    end();
    return 0;
}