#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int mod = 998244353;

const int N = 155555;
const int L = 18;
vector<int> a[N];
int tin[N], tout[N];
int par[N][L];
int timer = 0;
int sz[N];
int level[N];

void dfs(int v, int p = -1) {
	if (p == -1) {
		p = v;
	}
	tin[v] = timer++;
	sz[v] = 1;
	par[v][0] = p;
	for (int x : a[v]) {
		if (x == p) {
			continue;
		}
		level[x] = level[v] + 1;
		dfs(x, v);
		sz[v] += sz[x];
	}
	tout[v] = timer;
}

bool isPar(int u, int v) {
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

const int BLOCK = 800;
long long last_ans[N];
long long to_add[N];
int n;

void dfsRecalc(int v, long long what, int p = -1) {
	to_add[v] %= mod;
	what %= mod;
	last_ans[v] = (last_ans[v] + what + (n - sz[v]) * to_add[v] % mod) % mod;
	for (int x : a[v]) {
		if (x == p) {
			continue;
		}
		dfsRecalc(x, what + to_add[v] * (n - sz[x] - sz[v]), v);
	}
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	n = nxt();
	int q = nxt();
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	dfs(0);
	long long invn = 1;
	while (invn % n) {
		invn += mod;
	}
	invn /= n;

	for (int i = 1; i < L; ++i) {
		for (int j = 0; j < n; ++j) {
			par[j][i] = par[par[j][i - 1]][i - 1];
		}
	}
	auto goUp = [&](int v, int need_lvl) {
		int dl = level[v] - need_lvl;
		for (int i = 0; i < L; ++i) {
			if (dl & (1 << i)) {
				v = par[v][i];
			}
		}
		return v;
	};

	vector<pair<int, long long>> recent;
	while (q--) {
		int t = nxt();
		if (t == 1) {
			int v = nxt() - 1;
			long long d = 1ll * nxt() * invn % mod;
			recent.push_back({v, d});
		} else {
			int v = nxt() - 1;
			long long ans = last_ans[v];

			for (const auto& [u, d] : recent) {
				if (u == v) {
					ans += d * n % mod;
				} else if (isPar(u, v)) {
					int w = goUp(v, level[u] + 1);
					ans += d * (n - sz[w]) % mod;
				} else {
					ans += d * sz[u] % mod;
				}
			}

			ans %= mod;
			if (ans < 0) {
				ans += mod;
			}
			printf("%lld\n", ans);
		}

		if ((int)recent.size() == BLOCK) {
			memset(to_add, 0, sizeof(to_add));
			long long initial = 0;
			for (const auto& [u, d] : recent) {
				to_add[u] += d;
				initial += d * sz[u] % mod;
			}
			dfsRecalc(0, initial);
			recent.clear();
		}
	}

	return 0;
}