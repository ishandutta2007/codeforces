#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

const int N = 111111;
vector<int> a[N];
int h[N], tin[N], tout[N], timer;

void dfs(itn v, int p = -1) {
	tin[v] = timer++;
	for (int x : a[v]) {
		if (x != p) {
			h[x] = h[v] + 1;
			dfs(x, v);
		}
	}
	tout[v] = timer;
}

struct Node {
	int rot;
	vector<int> a;
};

struct SegTree {
	int n;
	int k;
	vector<Node> a;

	SegTree(int _n, int _k): k(_k) {
		n = 1;
		while (n < _n) {
			n *= 2;
		}
		a.resize(n + n, {0, vector<int>(k)});
	}

	void chg(int pos, int k, int x) {
		pos += n;
		while (pos > 0) {
			a[pos].a[k] ^= x;
			pos /= 2;
		}
	}

	void push(int v) {
		if (a[v].rot) {
			for (int t : {0, 1}) {
				a[v + v + t].rot = (a[v + v + t].rot + a[v].rot) % k;
				rotate(a[v + v + t].a.begin(), a[v + v + t].a.begin() + a[v].rot, a[v + v + t].a.end());
			}
			a[v].rot = 0;
		}
	}

	void recalc(int v) {
		for (int i = 0; i < k; ++i) {
			a[v].a[i] = a[v + v].a[i] ^ a[v + v + 1].a[i];
		}
	}

	void inc(int v, int l1, int r1, int l, int r, int d) {
		if (l >= r1 || l1 >= r) {
			return;
		}
		if (l <= l1 && r >= r1) {
			a[v].rot = (a[v].rot + d) % k;
			rotate(a[v].a.begin(), a[v].a.begin() + d, a[v].a.end());
			return;
		}
		push(v);
		int m = (l1 + r1) / 2;
		inc(v + v, l1, m, l, r, d);
		inc(v + v + 1, m, r1, l, r, d);
		recalc(v);
	}

	void inc(int l, int r, int d) {
		inc(1, 0, n, l, r, d);
	}

	int calc() const {
		int x = 0;
		for (int i = k / 2; i < k; ++i) {
			x ^= a[1].a[i];
		}
		return x;
	}
};

int n, k;

int ans[N];
void rec(int v, SegTree& tree, int p = -1) {
	// cerr << v + 1 << ": " << tree.a[1].a << "\n";
	ans[v] = !!tree.calc();
	for (int x : a[v]) {
		if (x != p) {
			tree.inc(0, n, 2 * k - 1);
			tree.inc(tin[x], tout[x], 2);
			rec(x, tree, v);
			tree.inc(0, n, 1);
			tree.inc(tin[x], tout[x], 2 * k - 2);
		}
	}
}

void solve() {
	n = nxt(), k = nxt();
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	vector<int> val(n);
	generate(all(val), nxt);
	dfs(0);
	SegTree tree(n, 2 * k);
	for (int i = 0; i < n; ++i) {
		tree.chg(tin[i], h[i] % (2 * k), val[i]);
	}
	rec(0, tree);
	for (int i = 0; i < n; ++i) {
		cout << ans[i] << " ";
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}