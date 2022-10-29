#include <cstdio>
#include <vector>
const int N = 2e5, MOD = 998244353;
int n, q; 
std::vector<int> adj[N];
int par[N], w[N], in[N], out[N], c[N], top[N];
long long fen[N];
long long tag[N];

int time = 0;
void dfs(int u, int p)
{
	par[u] = p;
	w[u] = 1;
	in[u] = ++time;
	for (int v : adj[u])
		if (v != p)
		{
			dfs(v, u);
			w[u] += w[v];
		}
	out[u] = time;
	if (w[u] > w[c[p]])
		c[p] = u;
}

void hld(int u, int p)
{
	top[u] = c[p] == u ? top[p] : u;
	for (int v : adj[u])
		if (v != p)
			hld(v, u);
}

void set(int pos, long long val)
{
	for (; pos <= n; pos += pos & -pos)
		fen[pos] += val;
}

long long get(int pos, long long res = 0)
{
	for (; pos >= 1; pos -= pos & -pos)
		res += fen[pos];
	return res;
}

void update(int u, long long d)
{
	if (u == 0)
		return;
	set(in[u], d);
	set(out[u] + 1, -d);
}

int main()
{
	scanf("%d%d", &n, &q);
	long long inv = 1, base = n;
	for (int p = MOD - 2; p > 0; p /= 2)
	{
		if (p & 1)
			inv = inv * base % MOD;
		base = base * base % MOD;
	}
	for (int i = 1; i < n; ++i)
	{
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	hld(1, 0);
	long long sum = 0;
	for (int i = 0; i < q; ++i)
	{
		int t, v; scanf("%d%d", &t, &v);
		if (t == 1)
		{
			long long d; scanf("%lld", &d);
			sum += d * w[v];
			update(v, d * (n - w[v]));
			update(c[v], - d * w[c[v]]);
			tag[v] += d;
		}
		if (t == 2)
		{
			long long res = sum + get(in[v]);
			while (v != 0)
			{
				v = top[v];
				res -= tag[par[v]] * w[v];
				v = par[v];
			}
			printf("%lld\n", res % MOD * inv % MOD);
		}
	}
}