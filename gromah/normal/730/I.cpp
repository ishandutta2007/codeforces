#include <cstdio>
#include <algorithm>
using namespace std;
#define N 3000 + 5
#define M 1000000 + 5
#define INF 1234567890

int n, p, s, tot = 1, S, ans, T_a, T_b, T, A[N], B[N], Head[N], Dis[N], f[N], Inq[N], q[M];

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
        Dis[i] = -INF, Inq[i] = 0, f[i] = 0;
    int l = 1, r = 0;
    q[++ r] = s, Inq[s] = r, Dis[s] = 0;
    while (l <= r)
    {
        int z = q[l ++];
        Inq[z] = 0;
        for (int i = Head[z]; i; i = h[i].next)
        {
            int d = h[i].node, p = h[i].flow, w = h[i].w;
            if (!p || Dis[d] >= Dis[z] + w) continue ;
            Dis[d] = Dis[z] + w;
            f[d] = i;
            if (!Inq[d])
            {
                q[++ r] = d;
                Inq[d] = r;
            }
            if (r > l && Dis[q[l]] < Dis[q[r]])
            {
                int u = q[r];
                q[r] = q[l], q[l] = u;
                Inq[u] = l, Inq[q[r]] = r;
            }
        }
    }
    return Dis[T] != -INF;
}

inline int Calc()
{
    int res = 0, Flow = 0;
    while (SPFA(S))
    {
        int flow = INF;
        for (int x = T; x != S; x = h[f[x] ^ 1].node)
            flow = min(flow, h[f[x]].flow);
        Flow += flow;
        for (int x = T; x != S; x = h[f[x] ^ 1].node)
        {
            h[f[x]].flow -= flow;
            h[f[x] ^ 1].flow += flow;
            res += h[f[x]].w * flow;
        }
    }
    return res;
}

int main()
{
	scanf("%d%d%d", &n, &p, &s);
	S = 0, T_a = n + 1, T_b = n + 2, T = n + 3;
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", A + i);
		addedge(S, i, 1, 0);
		addedge(i, T_a, 1, A[i]);
	}
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", B + i);
		addedge(i, T_b, 1, B[i]);
	}
	addedge(T_a, T, p, 0);
	addedge(T_b, T, s, 0);
	ans = Calc();
	printf("%d\n", ans);
	for (int i = Head[T_a]; i; i = h[i].next)
	{
		int d = h[i].node, p = h[i].flow;
		if (d <= n && p) printf("%d ", d);
	}
	puts("");
	for (int i = Head[T_b]; i; i = h[i].next)
	{
		int d = h[i].node, p = h[i].flow;
		if (d <= n && p) printf("%d ", d);
	}
	puts("");
	return 0;
}