#include <cstdio>
#include <algorithm>
#include <vector>
const int N = 3e5, MOD = 998244353;
struct edge {
	int node; int id;
	bool operator < (const edge &other) {
		return id < other.id;
	}
};
std::vector<edge> adj[N];
// prv[u] = edge from u to direct ancestor
int fl[N]; // picked before prv[u] or by prv[u]
int fr[N]; // picked after prv[u], or not picked at all
int fp[N]; // not picked by prv[u]

int add(int x, int y)
{
	int res = x + y;
	return res < MOD ? res : res - MOD;
}

int mul(int x, int y)
{
	return 1LL * x * y % MOD;
}

int inv(int x)
{
	int res = 1, base = x, p = MOD - 2;
	while (p > 0)
	{
		if (p & 1) res = mul(res, base);
		base = mul(base, base);
		p /= 2;
	}
	return res;
}

void dfs(int u, int p)
{
	int cur = 1;
	for (edge e : adj[u])
	{
		int v = e.node;
		if (v != p)
		{
			dfs(v, u);
			cur = mul(cur, fp[v]);
		}
	}
	std::sort(adj[u].begin(), adj[u].end());
	bool left = true;
	for (edge e : adj[u])
	{
		int v = e.node;
		if (v != p)
		{
			cur = mul(cur, inv(fp[v]));
			int &tmp = left ? fp[u] : fr[u];
			tmp = add(tmp, mul(cur, fr[v]));
			cur = mul(cur, fl[v]);
		}
		else 
		{
			fl[u] = cur;
			left = false;
		}
	}
	fr[u] = add(fr[u], cur);
	fl[u] = add(fl[u], fp[u]);
	fp[u] = add(fp[u], fr[u]);
}

int main()
{
	int n; scanf("%d", &n);
	for (int i = 1; i < n; ++i)
	{
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back({v, i});
		adj[v].push_back({u, i});
	}
	dfs(1, 0);
	printf("%d\n", add(fl[1], fr[1]));
}