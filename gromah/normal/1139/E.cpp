#include <cstdio>
#include <algorithm>
using namespace std;
#define N 20000 + 5
#define M 200000 + 5
#define INF 0x3f3f3f3f

int n, m, k, S, T, V[N], C[N], Head[N], Dfn[N], q[N], Del[N], f[N], Ans[N];
bool Flag[N];

struct Edge
{
	int next, node, flow;
}h[M];

inline void addedge(int u, int v, int fl)
{
	static int tot = 1;
	h[++ tot].next = Head[u], Head[u] = tot;
	h[tot].node = v, h[tot].flow = fl;
	h[++ tot].next = Head[v], Head[v] = tot;
	h[tot].node = u, h[tot].flow = 0;
}

bool BFS(int st)
{
	for (int i = S; i <= T; i ++)
		Dfn[i] = 0;
	int l = 1, r = 0;
	q[++ r] = st, Dfn[st] = 1;
	while (l <= r)
	{
		int z = q[l ++];
		for (int i = Head[z]; i; i = h[i].next)
		{
			int d = h[i].node, p = h[i].flow;
			if (Dfn[d] || !p) continue ;
			Dfn[d] = Dfn[z] + 1;
			q[++ r] = d, f[d] = i;
			if (d == T) return 1;
		}
	}
	return 0;
}

int Flow()
{
	static int res = 0;
	for (; BFS(S); res ++)
	{
		for (int x = T; x != S; x = h[f[x] ^ 1].node)
			h[f[x]].flow --, h[f[x] ^ 1].flow ++;
	}
	return res;
}

int main()
{
	scanf("%d%d", &n, &m);
	S = 0, T = n + m + 2;
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", V + i);
		V[i] = min(V[i], n);
	}
	for (int i = 1; i <= n; i ++)
		scanf("%d", C + i);
	scanf("%d", &k);
	for (int i = 1; i <= k; i ++)
	{
		scanf("%d", Del + i);
		Flag[Del[i]] = 1;
	}
	for (int i = 1; i <= m; i ++)
		addedge(S, i, 1);
	for (int i = 1; i <= n; i ++)
		if (!Flag[i] && V[i] == 0)
			addedge(C[i], m + V[i] + 1, 1);
	addedge(m + 1, T, 1);
	for (int i = k, ans = 0; i; i --)
	{
		while (Flow() == ans + 1)
		{
			ans ++;
			addedge(m + ans + 1, T, 1);
			for (int i = 1; i <= n; i ++)
				if (!Flag[i] && V[i] == ans)
					addedge(C[i], m + V[i] + 1, 1);
		}
		Ans[i] = ans, Flag[Del[i]] = 0;
		if (V[Del[i]] <= ans)
			addedge(C[Del[i]], m + V[Del[i]] + 1, 1);
	}
	for (int i = 1; i <= k; i ++)
		printf("%d\n", Ans[i]);
	return 0;
}