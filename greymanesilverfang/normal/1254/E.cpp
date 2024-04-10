#include <cstdio>
#include <map>
#include <utility>
#include <vector>
#define pii std::pair<int,int>
const int N = 6e5, MOD = 1e9+7;
int n;
std::vector<pii> adj[N];
pii par[N];
int time, in[N], out[N];
int l[4 * N], r[4 * N];
int cnt[N];
long long f[N]; // factorial

void dfs(int u, int p)
{
	in[u] = ++time;
	for (pii e : adj[u])
		if (e.second != p)
		{
			dfs(e.second, u);
			par[e.second] = {e.first, u};
		}
	out[u] = ++time;
}

bool is_parent(int u, int v)
{
	return in[u] <= in[v] && out[v] <= out[u];
}

bool set_order(int u, int a, int b)
{
	if (r[a] != 0 || l[b] != 0)
		return false;
	r[a] = b;
	l[b] = a;
	++cnt[u];
	return true;
}

bool update(int u, int v)
{
	int prv_u = 2 * (n + u);
	int prv_v = 2 * (n + v);
	while (!is_parent(u, v))
	{
		int cur = 2 * par[u].first + (u < par[u].second);
		if (!set_order(u, prv_u, cur))
			return false;
		u = par[u].second;
		prv_u = cur ^ 1;
	}
	while (v != u)
	{
		int cur = 2 * par[v].first + (v < par[v].second);
		if (!set_order(v, cur, prv_v))
			return false;
		v = par[v].second;
		prv_v = cur ^ 1;
	}
	if (!set_order(u, prv_u, prv_v))
		return false;
	return true;
}

bool check_cycle()
{
	for (int i = 4 * n; i >= 1; --i)
		if (r[i] != 0)
		{
			while (r[i] != 0 && r[i] != i)
			{
				int tmp = r[i];
				r[i] = r[tmp];
				r[tmp] = 0;
			}
			if (r[i] == i)
			{
				if (i < 2 * n)
					return false;
				int u = i / 2 - n;
				if (--cnt[u] < adj[u].size())
					return false;
			}
		}
	return true;
}

int solve()
{
	for (int u = 1; u <= n; ++u)
	{
		int v; scanf("%d", &v);
		if (v != 0 && (u == v || !update(u, v)))
			return 0;
	}
	if (!check_cycle())
		return 0;
	long long res = 1;
	for (int u = 1; u <= n; ++u)
		res = res * f[adj[u].size() - cnt[u]] % MOD;
	return res;
}

int main()
{
	scanf("%d", &n);
	f[0] = 1;
	for (int i = 1; i < n; ++i)
		f[i] = f[i - 1] * i % MOD;
	for (int i = 1; i < n; ++i)
	{
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back({i, v});
		adj[v].push_back({i, u});
	}
	dfs(1, 0);
	printf("%d", solve());
}