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

const int N = 666'666;
vector<int> a[N];
int tin[N], tout[N];
int timer;
const int L = 20;
int par[N][L];

void dfs(int v) {
	for (int i = 1; i < L; ++i) {
		par[v][i] = par[par[v][i - 1]][i - 1];
	}
	tin[v] = timer++;
	for (int x : a[v]) {
		// cerr << v << " -> " << x << "\n";
		par[x][0] = v;
		dfs(x);
	}
	tout[v] = timer;
}

bool is_par(int u, int v) {
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
	if (u == -1) {
		return v;
	}
	if (v == -1) {
		return u;
	}
	if (is_par(u, v)) {
		return u;
	}
	for (int i = L - 1; i >= 0; --i) {
		if (!is_par(par[u][i], v)) {
			u = par[u][i];
		}
	}
	return par[u][0];
}

struct Node {
	int lca_of_all;
	int lca;
	int to_push;

	explicit Node(int v = -1): lca_of_all(v), lca(-1), to_push(-1) {}
};

struct Segtree {
	int n;
	vector<Node> a;

	Segtree(int _n) {
		n = 1;
		while (n < _n) {
			n *= 2;
		}
		a.resize(n + n);
		for (int i = 0; i < _n; ++i) {
			a[n + i].lca_of_all = i;
		}
		for (int i = n - 1; i > 0; --i) {
			a[i].lca_of_all = lca(a[i + i].lca_of_all, a[i + i + 1].lca_of_all);
		}
	}

	void push(int v) {
		if (int& x = a[v].to_push; x > -1) {
			for (int i : {0, 1}) {
				a[v + v + i].to_push = x;
				a[v + v + i].lca = x ? a[v + v + i].lca_of_all : -1;
			}
			x = -1;
		}
	}

	void update(int v, int l1, int r1, int l, int r, int x) {
		if (l >= r1 || l1 >= r) {
			return;
		}
		if (l <= l1 && r >= r1) {
			a[v].to_push = x;
			a[v].lca = x ? a[v].lca_of_all : -1;
			return;
		}
		push(v);
		int m = (l1 + r1) / 2;
		update(v + v, l1, m, l, r, x);
		update(v + v + 1, m, r1, l, r, x);
		a[v].lca = lca(a[v + v].lca, a[v + v + 1].lca);
	}

	void update(int l, int r, int x) {
		update(1, 0, n, l, r, x);
	}

	int get(int v, int l1, int r1, int l, int r) {
		if (l >= r1 || l1 >= r) {
			return -1;
		}
		if (l <= l1 && r >= r1) {
			return a[v].lca;
		}
		if (a[v].to_push > -1) {
			return a[v].to_push ? a[v].lca_of_all : -1;
		}
		int m = (l1 + r1) / 2;
		return lca(get(v + v, l1, m, l, r), get(v + v + 1, m, r1, l, r));
	}

	int get(int l, int r) {
		return get(1, 0, n, l, r);
	}
};

void solve() {
	int n = nxt(), q = nxt();
	vector<array<int, 3>> edges;
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1, w = nxt();
		edges.push_back({w, u, v});
	}
	sort(all(edges));
	vector<int> root(n);
	iota(all(root), 0);
	vector<int> val(n, -1);
	Dsu dsu(n);
	int sz = n;
	for (auto [w, u, v] : edges) {
		u = dsu.get(u);
		v = dsu.get(v);
		a[sz].push_back(root[u]);
		a[sz].push_back(root[v]);
		val.push_back(w);
		root.push_back(sz);
		dsu.merge(u, v);
		root[u] = root[v] = sz++;
	}
	par[sz - 1][0] = sz - 1;
	dfs(sz - 1);

	Segtree tree(n);
	while (q--) {
		int t = nxt();
		if (t != 3) {
			int l = nxt() - 1, r = nxt();
			tree.update(l, r, t % 2);
		} else {
			int x = nxt() - 1;
			cout << val[lca(x, tree.get(0, n))] << "\n";
		}
	}
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}