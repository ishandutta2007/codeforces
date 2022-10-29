#include <cstdio>
#include <algorithm>
#include <vector>
const int N = 1e5+5, MOD = 1e9+7;
int l[N], r[N];
long long inv[N];
std::vector<int> adj[N];
int w[N], h[N];

long long pow(long long base, int p)
{
	long long res = 1;
	while (p > 0)
	{
		if (p & 1) res = res * base % MOD;
		base = base * base % MOD;
		p /= 2;
	}
	return res;
}

void dfs(int u, int p)
{
	w[u] = 1;
	for (int v : adj[u])
		if (v != p)
		{
			dfs(v, u);
			w[u] += w[v];
		}
}

void purge(std::vector<int> &v, int x)
{
	v.erase(std::find(v.begin(), v.end(), x));
}

struct slope_bit {
	struct bit {
		long long f[N];
		long long get(int pos) {
			long long res = 0;
			while (pos > 0) {
				res += f[pos];
				pos -= pos & -pos;
			}
			return res % MOD;
		}
		void set(int pos, long long val) {
			while (pos < N) {
				f[pos] += val;
				pos += pos & -pos;
			}
		}
	} fcoe, fval;
	long long get(int pos) {
		return fcoe.get(pos) * pos % MOD + fval.get(pos);
	}
	long long get(int l, int r) {
		return get(r) - get(l - 1);
	}
	void set(int pos, long long val) {
		fcoe.set(pos, val);
		fval.set(pos, val * (1 - pos) % MOD);
	}
	void set(int l, int r, long long val) {
		set(l, val);
		set(r + 1, -val);
	}
} fcnt, fsum;

long long get(int u, int p)
{
	h[u] = h[p] + 1;
	long long res = (fcnt.get(l[u], r[u]) * h[u] + fsum.get(l[u], r[u])) % MOD * inv[u] % MOD;
	for (int v : adj[u])
		if (v != p)
			res += get(v, u);
	return res % MOD;
}

void set(int u, int p, int sign)
{
	h[u] = h[p] + 1;
	fcnt.set(l[u], r[u], inv[u] * sign);
	fsum.set(l[u], r[u], inv[u] * h[u] % MOD * sign);
	for (int v : adj[u])
		if (v != p)
			set(v, u, sign);
}

long long sub_solve(int u)
{
	long long res = 0;
	fcnt.set(l[u], r[u], inv[u]);
	for (int v : adj[u])
	{
		res += get(v, 0);
		set(v, 0, 1);
	}
	fcnt.set(l[u], r[u], -inv[u]);
	for (int v : adj[u])
		set(v, 0, -1);
	return res % MOD;
}

long long solve(int u)
{
	dfs(u, 0);
	int sum = w[u];
	while (true)
	{
		int max = 0;
		for (int v : adj[u])
			if (w[v] < w[u] && w[v] > w[max])
				max = v;
		if (w[max] * 2 < sum)
			break;
		u = max;
	}
	for (int v : adj[u])
		purge(adj[v], u);
	long long res = sub_solve(u);
	for (int v : adj[u])
		res += solve(v);
	return res % MOD;
}

int main()
{
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d%d", &l[i], &r[i]);
		inv[i] = pow(r[i] - l[i] + 1, MOD - 2);
	}
	for (int i = 1; i < n; ++i)
	{
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	long long res = solve(1);
	for (int i = 1; i <= n; ++i)
		res = res * (r[i] - l[i] + 1) % MOD;
	printf("%lld\n", (res + MOD) % MOD);
}