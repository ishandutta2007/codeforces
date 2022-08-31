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

struct SegTree {
	int n;
	vector<int> a;
	vector<int> to_add;

	SegTree(int _n) {
		n = 1;
		while (n < _n) {
			n *= 2;
		}
		a.resize(n + n);
		to_add.resize(n + n);
	}

	void relax(int v) {
		a[v + v] += to_add[v];
		to_add[v + v] += to_add[v];
		a[v + v + 1] += to_add[v];
		to_add[v + v + 1] += to_add[v];
		to_add[v] = 0;
	}

	void add(int v, int l1, int r1, int l, int r, int x) {
		if (l >= r1 || l1 >= r) {
			return;
		}
		if (l <= l1 && r >= r1) {
			a[v] += x;
			to_add[v] += x;
			return;
		}
		relax(v);
		int m = (l1 + r1) / 2;
		add(v + v, l1, m, l, r, x);
		add(v + v + 1, m, r1, l, r, x);
		a[v] = min(a[v + v], a[v + v + 1]);
	}

	void add(int pos, int x) {
		add(1, 0, n, 0, pos + 1, x);
	}

	int get() {
		if (a[1] >= 0) {
			return -1;
		}
		int v = 1, l = 0, r = n;
		while (l + 1 < r) {
			relax(v);
			int m = (l + r) / 2;
			if (a[v + v + 1] < 0) {
				l = m;
				v = v + v + 1;
			} else {
				r = m;
				v = v + v;
			}
		}
		return l;
	}
};

SegTree tree(1e6);

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	itn n = nxt(), m = nxt();
	vector<int> a(n), b(m);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}
	for (int j = 0; j < m; ++j) {
		b[j] = nxt();
	}
	for (int x : a) {
		tree.add(x, -1);
	}
	for (int x : b) {
		tree.add(x, 1);
	}

	int q = nxt();
	while (q--) {
		int t = nxt(), i = nxt() - 1, x = nxt();
		if (t == 1) {
			tree.add(a[i], 1);
			a[i] = x;
			tree.add(a[i], -1);
		} else {
			tree.add(b[i], -1);
			b[i] = x;
			tree.add(b[i], 1);
		}

		printf("%d\n", tree.get());
	}

	return 0;
}