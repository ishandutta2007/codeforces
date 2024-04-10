#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

struct Dsu {
	int n;
	vector<int> p, rk;

	Dsu(int _n): n(_n), p(_n), rk(_n) {
		std::iota(p.begin(), p.end(), 0);
	}

	int get(int v) {
		return v == p[v] ? v : p[v] = get(p[v]);
	}

	bool merge(int u, int v) {
		u = get(u);
		v = get(v);
		if (u == v) {
			return false;
		}
		if (rk[u] < rk[v]) {
			swap(u, v);
		}
		p[v] = u;
		if (rk[u] == rk[v]) {
			++rk[u];
		}
		return true;
	}
};

const int L = 20;

const int N = 111'111;
vector<int> a[N];
int par[N][L];
int tin[N], tout[N], lvl[N];
int timer = 0;

void dfs(int v, int p) {
	tin[v] = timer++;
	par[v][0] = p;
	for (int i = 1; i < L; ++i) {
		par[v][i] = par[par[v][i - 1]][i - 1];
	}
	for (int u : a[v]) {
		if (u == p) {
			continue;
		}
		lvl[u] = lvl[v] + 1;
		dfs(u, v);
	}
	tout[v] = timer;
}

bool is_par(int u, int v) {
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
	if (is_par(v, u)) {
		return v;
	}
	for (int i = L - 1; i >= 0; --i) {
		if (auto x = par[v][i]; !is_par(x, u)) {
			v = x;
		}
	}
	return par[v][0];
}

int up(int v, int l) {
	while (l) {
		v = par[v][__builtin_ctz(l)];
		l &= l - 1;
	}
	return v;
}

int add[N];

void push_add(int v, int p) {
	for (int x : a[v]) {
		if (x != p) {
			add[x] += add[v];
			push_add(x, v);
		}
	}
}

void solve() {
	int n = nxt(), m = nxt();
	vector<pair<int, int>> bad;
	Dsu dsu(n);
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1;
		int v = nxt() - 1;
		if (dsu.merge(u, v)) {
			a[u].push_back(v);
			a[v].push_back(u);
		} else {
			bad.push_back({u, v});
		}
	}
	dfs(0, 0);

	for (auto [u, v] : bad) {
		int l = lca(u, v);
		if (l == u) {
			add[0] += 1;
			add[up(v, lvl[v] - lvl[u] - 1)] -= 1;
			add[v] += 1;
		} else if (l == v) {
			add[0] += 1;
			add[up(u, lvl[u] - lvl[v] - 1)] -= 1;
			add[u] += 1;
		} else {
			add[u] += 1;
			add[v] += 1;
		}
	}

	push_add(0, 0);
	string ans(n, '0');
	for (int i = 0; i < n; ++i) {
		if (add[i] == (int)bad.size()) {
			ans[i] = '1';
		}
	}
	cout << ans << "\n";
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}