#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 100 + 5
#define M 10000 + 5
#define INF 1000000007

int n, m, S, T, tot = 1, ans, Dis[N], Inq[N], f[N], In[N], Head[N], q[M];

struct Edge
{
	int next, node, flow, w;
}h[M];

inline void addedge(int u, int v, int fl, int w)
{
	h[++ tot].next = Head[u], Head[u] = tot;
	h[tot].node = v, h[tot].flow = fl, h[tot].w = w;
	h[++ tot].next = Head[v], Head[v] = tot;
	h[tot].node = u, h[tot].flow = 0, h[tot].w = -w;
}

inline bool SPFA(int s)
{
    for (int i = S; i <= T; i ++)
        Dis[i] = INF, Inq[i] = 0, f[i] = 0;
    int l = 1, r = 0;
    q[++ r] = s, Inq[s] = r, Dis[s] = 0;
    while (l <= r)
    {
        int z = q[l ++];
        Inq[z] = 0;
        for (int i = Head[z]; i; i = h[i].next)
        {
            int d = h[i].node, p = h[i].flow, w = h[i].w;
            if (!p || Dis[d] <= Dis[z] + w) continue ;
            Dis[d] = Dis[z] + w;
            f[d] = i;
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
    return Dis[T] != INF;
}

inline int Calc()
{
	int res = 0;
    while (SPFA(S))
    {
        int flow = INF;
        for (int x = T; x != S; x = h[f[x] ^ 1].node)
            flow = min(flow, h[f[x]].flow);
        for (int x = T; x != S; x = h[f[x] ^ 1].node)
        {
            h[f[x]].flow -= flow;
            h[f[x] ^ 1].flow += flow;
            res += 1LL * h[f[x]].w * flow;
        }
    }
    return res;
}

int main()
{
	scanf("%d%d", &n, &m);
	S = 0, T = n + 1;
	for (int i = 1; i <= m; i ++)
	{
		int u, v, f, c;
		scanf("%d%d%d%d", &u, &v, &c, &f);
		In[u] -= f, In[v] += f;
		if (f > c)
		{
			ans += f - c;
			addedge(u, v, INF, 2);
			addedge(v, u, f - c, 0);
			addedge(v, u, c, 1);
		}
		else
		{
			addedge(u, v, c - f, 1);
			addedge(u, v, INF, 2);
			addedge(v, u, f, 1);
		}
	}
	addedge(n, 1, INF, 0);
	for (int i = 1; i <= n; i ++)
	{
		if (In[i] > 0)
			addedge(S, i, In[i], 0);
		else addedge(i, T, -In[i], 0);
	}
	while (SPFA(S)) ans += Calc();
	printf("%d\n", ans);
	return 0;
}