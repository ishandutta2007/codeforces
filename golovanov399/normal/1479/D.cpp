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

const int N = 333333;
vector<int> a[N];
int tin[N], tout[N];
int timer = 0;

const int L = 20;
int up[N][L];

void dfs(int v, int p) {
	up[v][0] = p;
	for (int i = 1; i < L; ++i) {
		up[v][i] = up[up[v][i - 1]][i - 1];
	}
	tin[v] = timer++;
	for (int x : a[v]) {
		if (x != p) {
			dfs(x, v);
		}
	}
	tout[v] = timer;
}

bool is_upper(int u, int v) {
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
	if (is_upper(v, u)) {
		return v;
	}
	for (int i = L - 1; i >= 0; --i) {
		if (auto w = up[v][i]; !is_upper(w, u)) {
			v = w;
		}
	}
	return up[v][0];
}

struct Node {
	int l, r;
	long long val;
};

struct SegTree {
	int n;
	vector<Node> a;
	vector<int> roots;

	SegTree(int _n): n(_n) {
		function<int(int, int)> build = [&](int l, int r) {
			int res = a.size();
			a.push_back({-1, -1, 0});
			if (l + 1 < r) {
				int m = (l + r) / 2;
				int left = build(l, m);
				int right = build(m, r);
				a[res].l = left;
				a[res].r = right;
			}
			return res;
		};
		roots.push_back(build(0, n));
	}

	int add(int v, int l1, int r1, int pos, long long x) {
		if (pos >= r1 || l1 >= pos + 1) {
			return v;
		}
		int res = a.size();
		a.push_back(a[v]);
		a[res].val ^= x;
		if (l1 == pos && r1 == pos + 1) {
			return res;
		}
		int m = (l1 + r1) / 2;
		int left = add(a[v].l, l1, m, pos, x);
		a[res].l = left;
		int right = add(a[v].r, m, r1, pos, x);
		a[res].r = right;
		return res;
	}

	void add(int epoch, int pos, long long x) {
		int root = roots[epoch];
		roots.push_back(add(root, 0, n, pos, x));
	}

	long long get(int v, int l1, int r1, int l, int r) {
		if (l >= r1 && l1 >= r) {
			return 0;
		}
		if (l <= l1 && r >= r1) {
			return a[v].val;
		}
		int m = (l1 + r1) / 2;
		return get(a[v].l, l1, m, l, r) ^ get(a[v].r, m, r1, l, r);
	}

	long long get(int epoch, int l, int r) {
		return get(roots[epoch], 0, n, l, r);
	}
};

void solve() {
	int n = nxt(), q = nxt();
	vector<int> val(n);
	for (int i = 0; i < n; ++i) {
		val[i] = nxt();
	}
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	dfs(0, 0);
	vector<vector<int>> where(n + 1);
	for (int i = 0; i < n; ++i) {
		where[val[i]].push_back(i);
	}
	vector<long long> rands(n + 1);
	mt19937 rr;
	uniform_int_distribution<long long> gen(0, (1ll << 60) - 1);
	for (int i = 0; i < n + 1; ++i) {
		rands[i] = gen(rr);
	}

	SegTree tree(n + 1);
	vector<int> epochs(n);

	function<void(int, int, int)> rec = [&](int v, int p, int old_epoch) {
		tree.add(old_epoch, val[v], rands[val[v]]);
		epochs[v] = (int)tree.roots.size() - 1;
		for (int x : a[v]) {
			if (x != p) {
				rec(x, v, epochs[v]);
			}
		}
	};
	rec(0, 0, 0);

	function<long long(const vector<int>&)> obtain = [&](const vector<int>& vs) {
		long long res = 0;
		for (int v : vs) {
			res ^= tree.a[v].val;
		}
		return res;
	};

	function<int(vector<int>, int, int, int, int)> calc = [&](vector<int> vs, int l1, int r1, int l, int r) {
		if (l >= r1 || l1 >= r) {
			return -1;
		}
		if (l <= l1 && r >= r1) {
			if (!obtain(vs)) {
				return -1;
			}
			while (l1 + 1 < r1) {
				int m = (l1 + r1) / 2;
				vector<int> ls = vs, rs = vs;
				for (int i = 0; i < (int)vs.size(); ++i) {
					ls[i] = tree.a[ls[i]].l;
					rs[i] = tree.a[rs[i]].r;
				}
				if (obtain(ls)) {
					vs.swap(ls);
					r1 = m;
				} else {
					vs.swap(rs);
					l1 = m;
				}
			}
			return l1;
		}
		int m = (l1 + r1) / 2;
		vector<int> ls = vs, rs = vs;
		for (int i = 0; i < (int)vs.size(); ++i) {
			ls[i] = tree.a[ls[i]].l;
			rs[i] = tree.a[rs[i]].r;
		}
		if (auto tmp = calc(ls, l1, m, l, r); tmp != -1) {
			return tmp;
		} else {
			return calc(rs, m, r1, l, r);
		}
	};

	while (q--) {
		int u = nxt() - 1, v = nxt() - 1;
		int l = nxt(), r = nxt() + 1;
		int lc = lca(u, v);
		vector<int> vertices = {u, v, lc};
		if (lc) {
			vertices.push_back(up[lc][0]);
		}
		vector<int> vs;
		for (int x : vertices) {
			vs.push_back(tree.roots[epochs[x]]);
		}
		cout << calc(vs, 0, n + 1, l, r) << "\n";
	}
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}