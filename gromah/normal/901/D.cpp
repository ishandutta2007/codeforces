#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 100000 + 5

int n, m, tot = 1, sz, e, Dep[N], Head[N], Fa[N], Ord[N];
LL Sum[2], A[N], Ans[N];

struct Edge
{
	int next, node;
	LL w;
}h[N << 1];

void addedge(int u, int v)
{
	h[++ tot].next = Head[u], Head[u] = tot;
	h[tot].node = v;
}

void dfs(int z, int fa)
{
	Ord[z] = z;
	Sum[Dep[z] & 1] += A[z];
	for (int i = Head[z]; i; i = h[i].next)
	{
		int d = h[i].node;
		if (d == fa) continue ;
		if (Dep[d] && (Dep[d] + Dep[z] + 1 & 1))
			e = i >> 1;
		else if (!Dep[d])
		{
			Dep[d] = Dep[z] + 1;
			Fa[d] = i;
			dfs(d, z);
		}
	}
}

bool cmp(int u, int v)
{
	return Dep[u] < Dep[v];
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++)
		scanf("%lld", A + i);
	for (int i = 1, u, v; i <= m; i ++)
	{
		scanf("%d%d", &u, &v);
		addedge(u, v);
		addedge(v, u);
	}
	dfs(Dep[1] = 1, 0);
	if (Sum[0] + Sum[1] & 1)
	{
		puts("NO");
		return 0;
	}
	if (Sum[0] != Sum[1])
	{
		if (!e)
		{
			puts("NO");
			return 0;
		}
		else
		{
			if (Dep[h[e << 1].node] & 1)
			{
				Ans[e] = Sum[1] - Sum[0] >> 1;
				Sum[1] = Sum[0];
			}
			else
			{
				Ans[e] = Sum[0] - Sum[1] >> 1;
				Sum[0] = Sum[1];
			}
			A[h[e << 1].node] -= Ans[e];
			A[h[e << 1 | 1].node] -= Ans[e];
		}
	}
	sort(Ord + 1, Ord + n + 1, cmp);
	for (int i = n; i > 1; i --)
	{
		int z = Ord[i], t = Fa[z];
		Ans[t >> 1] = A[z];
		A[z] -= Ans[t >> 1];
		A[h[t ^ 1].node] -= Ans[t >> 1];
	}
	puts("YES");
	for (int i = 1; i <= m; i ++)
		printf("%lld\n", Ans[i]);
	return 0;
}