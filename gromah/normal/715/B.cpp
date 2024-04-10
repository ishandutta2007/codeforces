#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 1000000 + 5
#define M 20000 + 5
#define INF 1234567890987654321LL

int n, m, L, s, t, tot = 1, Head[N], Fa[N], f[N], T[N], E[M][3];
LL Dis[N];

struct Edge
{
	int next, node, w, id;
}h[M];

struct Node
{
	int node;
	LL dis;
	Node (int _node = 0, int _dis = 0) {node = _node, dis = _dis;}
	bool operator < (const Node a) const
	{
		return make_pair(dis, 1LL * node) > make_pair(a.dis, 1LL * a.node);
	}
};

priority_queue <Node> Q;

inline int Find(int x)
{
	return Fa[x] == x ? x : Fa[x] = Find(Fa[x]);
}

inline void addedge(int u, int v, int w, int id)
{
	h[++ tot].next = Head[u], Head[u] = tot;
	h[tot].node = v, h[tot].w = w, h[tot].id = id;
	h[++ tot].next = Head[v], Head[v] = tot;
	h[tot].node = u, h[tot].w = w, h[tot].id = id;
}

inline void SPFA(int st)
{
	for (int i = 0; i < n * n; i ++)
		Dis[i] = INF;
	Dis[st] = 0;
	Q.push(Node(st, 0));
	while (!Q.empty())
	{
		Node x;
		while (!Q.empty())
		{
			x = Q.top();
			Q.pop();
			if (Dis[x.node] == x.dis) break ;
		}
		if (Q.empty() && Dis[x.node] != x.dis) break ;
		int cur = x.node, z = cur % n, t = cur / n;
		for (int i = Head[z]; i; i = h[i].next)
		{
			int d = h[i].node, w = h[i].w;
			if (!w) d += (t + 1) * n;
				else d += t * n;
			if (Dis[d] <= Dis[cur] + w) continue ;
			Dis[d] = Dis[cur] + w;
			f[d] = i, T[d] = t;
			if (t + (!w ? 1 : 0) < n - 1) Q.push(Node(d, Dis[d]));
		}
	}
}

int main()
{
	scanf("%d%d%d%d%d", &n, &m, &L, &s, &t);
	for (int i = 1; i <= n; i ++)
		Fa[i] = i;
	for (int i = 1; i <= m; i ++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		E[i][0] = u, E[i][1] = v, E[i][2] = w;
		addedge(u, v, w, i);
		if (Find(u) != Find(v))
			Fa[Find(u)] = Find(v);
	}
	if (Find(s) != Find(t))
	{
		puts("NO");
		return 0;
	}
	SPFA(s);
	if (Dis[t] < L) puts("NO");
	else if (Dis[t] == L)
	{
		puts("YES");
		for (int i = 1; i <= m; i ++)
			printf("%d %d %d\n", E[i][0], E[i][1], E[i][2] ? E[i][2] : L);
	}
	else
	{
		int id;
		for (id = 1; id < n; id ++)
			if (Dis[t + id * n] <= L && L - Dis[t + id * n] >= id) break ;
		if (id == n) puts("NO");
		else
		{
			int ret = (L - Dis[t + id * n]) % id;
			for (int x = t + id * n; x != s; x = h[f[x] ^ 1].node + T[x] * n)
			{
				if (!h[f[x]].w)
				{
					E[h[f[x]].id][2] = (L - Dis[t + id * n]) / id + (ret > 0 ? 1 : 0);
					if (ret) ret --;
				}
			}
			puts("YES");
			for (int i = 1; i <= m; i ++)
			{
				int w = E[i][2];
				if (E[i][2] == -1) w = 0;
				else if (!E[i][2]) w = L;
				printf("%d %d %d\n", E[i][0], E[i][1], w);
			}
		}
	}
	return 0;
}