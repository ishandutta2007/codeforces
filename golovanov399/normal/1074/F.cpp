#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

struct Node {
	int add;
	int mx, cnt;
};

struct SegTree {
	int n;
	vector<Node> a;

	SegTree(int _n) {
		n = 1;
		while (n < _n) {
			n *= 2;
		}
		a.resize(n + n);
		for (int i = 0; i < _n; ++i) {
			a[n + i].cnt = 1;
		}
		for (int i = n - 1; i > 0; --i) {
			a[i].cnt = a[2 * i].cnt + a[2 * i + 1].cnt;
		}
	}

	void relax(int v) {
		if (v < n) {
			a[v + v].add += a[v].add;
			a[v + v].mx += a[v].add;
			a[v + v + 1].add += a[v].add;
			a[v + v + 1].mx += a[v].add;
		}
		a[v].add = 0;
	}

	void add(int v, int l1, int r1, int l, int r, int x) {
		if (l >= r1 || l1 >= r) {
			return;
		}
		if (l <= l1 && r >= r1) {
			a[v].add += x;
			a[v].mx += x;
			return;
		}
		int m = (l1 + r1) / 2;
		relax(v);
		add(v + v, l1, m, l, r, x);
		add(v + v + 1, m, r1, l, r, x);

		a[v].mx = max(a[v + v].mx, a[v + v + 1].mx);
		a[v].cnt = 0;
		if (a[v].mx == a[v + v].mx) {
			a[v].cnt += a[v + v].cnt;
		}
		if (a[v].mx == a[v + v + 1].mx) {
			a[v].cnt += a[v + v + 1].cnt;
		}
	}

	void add(int l, int r, int x) {
		add(1, 0, n, l, r, x);
	}
};

const int N = 222222;
vector<int> a[N];
int sz[N];
int level[N];
int tin[N], tout[N];
int timer;

int par[20][N];

void dfs(int v, int p = -1) {
	sz[v] = 1;
	for (int x : a[v]) {
		if (x == p) {
			continue;
		}
		level[x] = level[v] + 1;
		dfs(x, v);
		sz[v] += sz[x];
	}
	par[0][v] = p;
}

void dfsSize(int v, int p = -1) {
	for (int i = 0; i < (int)a[v].size(); ++i) {
		if (a[v][i] == p) {
			a[v].erase(a[v].begin() + i);
			--i;
		}
	}
	sort(all(a[v]), [&](int i, int j) {
		return sz[i] > sz[j];
	});

	tin[v] = timer++;
	for (int x : a[v]) {
		dfsSize(x, v);
	}
	tout[v] = timer;
}

bool isPar(int i, int j) {
	return tin[i] <= tin[j] && tout[i] >= tout[j];
}

int lca(int u, int v) {
	if (isPar(u, v)) {
		return u;
	}
	for (int i = 20 - 1; i >= 0; --i) {
		if (par[i][u] == -1) {
			continue;
		}
		if (!isPar(par[i][u], v)) {
			u = par[i][u];
		}
	}
	return par[0][u];
}

int up(int v, int k) {
	for (int i = 0; i < 20; ++i) {
		if (k & (1 << i)) {
			v = par[i][v];
		}
	}
	return v;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	memset(par, -1, sizeof(par));

	int n = nxt(), q = nxt();
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	dfs(0);
	dfsSize(0);

	for (int i = 0;; ++i) {
		bool something_changed = false;
		for (int v = 0; v < n; ++v) {
			if (par[i][v] == -1) {
				continue;
			}
			int j = par[i][v];
			if (par[i][j] == -1) {
				continue;
			}
			j = par[i][j];
			something_changed = true;
			par[i + 1][v] = j;
		}
		if (!something_changed) {
			break;
		}
	}

	SegTree tree(timer);
	set<pair<int, int>> S;

	int bal = 0;
	while (q--) {
		int u = nxt() - 1, v = nxt() - 1;
		if (v < u) {
			swap(u, v);
		}
		pair<int, int> p = {u, v};
		int add = 1;
		if (S.count(p)) {
			add = -1;
			S.erase(p);
		} else {
			S.insert(p);
		}
		bal += add;

		int l = lca(u, v);
		for (int w : {u, v}) {
			if (l == w) {
				tree.add(tin[0], tout[0], add);
				int x = up(u + v - w, level[u + v - w] - level[w] - 1);
				tree.add(tin[x], tout[x], -add);
			} else {
				tree.add(tin[w], tout[w], add);
			}
		}

		int ans = 0;
		if (tree.a[1].mx == bal) {
			ans = tree.a[1].cnt;
		}
		printf("%d\n", ans);
	}

	return 0;
}