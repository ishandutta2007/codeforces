#include <cstdio>
using namespace std;
#define N 100000 + 5
#define M 10000000 + 5
#define INF 1000000007

int n, m, k, l, r, tot, Dis[N], Head[N], q[M];
bool Inq[N];

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

inline void SPFA()
{
	for (int i = 1; i <= n; i ++)
		Dis[i] = INF, Inq[i] = 0;
	l = 1, r = 0;
	for (int i = 1; i <= k; i ++)
	{
		int u;
		scanf("%d", &u);
		q[++ r] = u, Dis[u] = 0, Inq[u] = r;
	}
    while (l <= r)
    {
        int z = q[l ++];
        Inq[z] = 0;
        for (int i = Head[z]; i; i = h[i].next)
        {
            int d = h[i].node, w = h[i].w;
            if (Dis[d] <= Dis[z] + w) continue ;
            Dis[d] = Dis[z] + w;
            if (!Inq[d])
            {
                q[++ r] = d;
                Inq[d] = r;
            }
            if (r > l && Dis[q[l]] > Dis[q[r]])
            {
                int u = q[r];
                q[r] = q[l], q[l] = u;
                Inq[u] = l, Inq[q[r]] = r;
            }
        }
    }
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i ++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		addedge(u, v, w);
	}
	SPFA();
	int Min = INF;
	for (int i = 1; i <= n; i ++)
	{
		if (Dis[i] == 0) continue ;
		Min = Min < Dis[i] ? Min : Dis[i];
	}
	if (Min == INF) puts("-1");
		else printf("%d\n", Min);
	return 0;
}