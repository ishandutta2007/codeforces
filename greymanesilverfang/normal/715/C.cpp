#include <cstdio>
#include <map>
#include <vector>
const int N = 1e5;
bool chk[N];
int n, m,
    pow[N], inv_pow[N],
    u[N], v[N], w[N],
    root, child,
    prv[N], wgt[N], h[N], val[N];
std::vector<int> adj[N];
std::map<int,int> cnt[N];
inline int inverse_modulo(int a, int b) { return a ? -(1LL * inverse_modulo(b % a, a) * b - 1) / a % m : 1; }

void dfs_wgt(int x)
{
	wgt[x] = 1;
	for (int e : adj[x])
	{
		int y = u[e] + v[e] - x;
		if (!chk[y] && y != prv[x])
		{
			prv[y] = x;
			dfs_wgt(y);
			wgt[x] += wgt[y];
		}
	}
}

void dfs_cnt(int x)
{
	++cnt[root][val[x]];
	++cnt[child][val[x]];
	for (int e : adj[x])
	{
		int y = u[e] + v[e] - x;
		if (!chk[y] && y != prv[x])
		{
			prv[y] = x;
			h[y] = h[x] + 1;
			val[y] = (val[x] + 1LL * w[e] * pow[h[x]]) % m;
			dfs_cnt(y);
		}
	}
}

long long dfs_rev(int x)
{
	int mod = 1LL * (m - val[x]) * inv_pow[h[x]] % m;
	long long res = cnt[root][mod] - cnt[child][mod];
	for (int e : adj[x])
	{
		int y = u[e] + v[e] - x;
		if (!chk[y] && y != prv[x])
		{
			prv[y] = x;
			h[y] = h[x] + 1;
			val[y] = (1LL * val[x] * 10 + w[e]) % m;
			res += dfs_rev(y);
		}
	}
	return res;
}

long long sub_solve()
{
	for (int e : adj[root])
	{
		int node = u[e] + v[e] - root;
		if (!chk[node])
		{
			child = node;
			prv[child] = root;
			h[child] = 1;
			val[child] = w[e] % m;
			dfs_cnt(child);
		}
	}
	long long res = cnt[root][0]++;
	for (int e : adj[root])
	{
		int node = u[e] + v[e] - root;
		if (!chk[node])
		{
			child = node;
			prv[child] = root;
			h[child] = 1;
			val[child] = w[e] % m;
			res += dfs_rev(child);
		}
	}
	cnt[root].clear();
	for (int e : adj[root])
	{
		int node = u[e] + v[e] - root;
		if (!chk[node])
		{
			child = node;
			cnt[child].clear();
		}
	}
	return res;
}

long long decomp(int x)
{
	prv[x] = 0;
	dfs_wgt(x);
	int total = wgt[x];
	bool centroid = false;
	while (!centroid)
	{
		centroid = true;
		for (int e : adj[x])
		{
			int y = u[e] + v[e] - x;
			if (!chk[y] && y != prv[x] && wgt[y] > total / 2)
			{
				x = y;
				centroid = false;
				break;
			}
		}
	}
	root = x;
	chk[x] = true;
	long long res = sub_solve();
	for (int e : adj[x])
	{
		int y = u[e] + v[e] - x;
		if (!chk[y])
			res += decomp(y);
	}
	return res;
}

int main()
{
	scanf("%d%d", &n, &m);
	if (m == 1)
	{
		printf("%lld", 1LL * n * (n - 1));
		return 0;
	}
	pow[1] = 10 % m;
	inv_pow[1] = (inverse_modulo(10 % m, m) + m) % m;
	for (int i = 2; i < n; ++i)
	{
		pow[i] = 1LL * pow[i - 1] * pow[1] % m;
		inv_pow[i] = 1LL * inv_pow[i - 1] * inv_pow[1] % m;
	}
	for (int i = 1; i < n; ++i)
	{
		scanf("%d%d%d", &u[i], &v[i], &w[i]);
		adj[u[i]].push_back(i);
		adj[v[i]].push_back(i);
	}
	printf("%lld", decomp(0));
	return 0;
}