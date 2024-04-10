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

struct Node {
	int add;
	int val;
};

struct SegTree {
	int n;
	vector<Node> a;

	SegTree(int _n) {
		n = 1;
		while (n < _n) {
			n *= 2;
		}
		a.resize(n + n, {0, (int)1e9});
	}

	void push(int v) {
		for (int t : {0, 1}) {
			a[2 * v + t].add += a[v].add;
			a[2 * v + t].val += a[v].add;
		}
		a[v].add = 0;
	}

	void recalc(int v) {
		a[v].val = min(a[v + v].val, a[v + v + 1].val);
	}

	void add(int v, int l1, int r1, int l, int r, int x) {
		if (l >= r1 || l1 >= r) {
			return;
		}
		if (l <= l1 && r >= r1) {
			a[v].add += x;
			a[v].val += x;
			return;
		}
		int m = (l1 + r1) / 2;
		push(v);
		add(v + v, l1, m, l, r, x);
		add(v + v + 1, m, r1, l, r, x);
		recalc(v);
	}

	void add(int l, int r, int x) {
		add(1, 0, n, l, r, x);
	}

	int get(int v, int l1, int r1, int l, int r) {
		if (l >= r1 || l1 >= r) {
			return 1e9;
		}
		if (l <= l1 && r >= r1) {
			return a[v].val;
		}
		int m = (l1 + r1) / 2;
		push(v);
		return min(get(v + v, l1, m, l, r), get(v + v + 1, m, r1, l, r));
	}

	int get(int l, int r) {
		return get(1, 0, n, l, r);
	}

	void remin(int pos, int x) {
		int v = 1;
		int l = 0, r = n;
		while (l + 1 < r) {
			int m = (l + r) / 2;
			push(v);
			a[v].val = min(a[v].val, x);
			if (pos >= m) {
				l = m;
				v = v * 2 + 1;
			} else {
				r = m;
				v = v * 2;
			}
		}
		a[v].val = min(a[v].val, x);
	}
};

int solve(vector<int> a) {
	int n = a.size();
	if (n == 1) {
		return 1;
	}
	int ans = 1;
	for (int i = 0; i < n - 1; ++i) {
		if (a[i] != a[i + 1]) {
			++ans;
		}
	}

	SegTree tree(n + 1);
	tree.remin(n, 0);
	for (int i = 0; i < n; ++i) {
		int val = tree.get(0, n + 1) + 1;
		val = min(val, tree.get(a[i], a[i] + 1));
		if (i == 0 || a[i] != a[i - 1]) {
			tree.add(0, n + 1, 1);
		}
		if (i > 0) {
			tree.remin(a[i - 1], val);
		}
		// for (int j = 0; j <= n; ++j) {
		// 	cerr << tree.get(j, j + 1) << " ";
		// }
		// cerr << "\n";
	}
	ans = min(ans, tree.get(0, n + 1));
	return ans;
}

int stupid(vector<int> a) {
	int n = a.size();
	int ans = 1;
	for (int i = 0; i < n - 1; ++i) {
		if (a[i] != a[i + 1]) {
			++ans;
		}
	}
	for (int mask = 1; mask < (1 << n) - 1; ++mask) {
		int l0 = -1, l1 = -1;
		int tmp = 0;
		for (int i = 0; i < n; ++i) {
			if (mask & (1 << i)) {
				tmp += l1 != a[i];
				l1 = a[i];
			} else {
				tmp += l0 != a[i];
				l0 = a[i];
			}
		}
		ans = min(ans, tmp);
	}
	return ans;
}

int main() {
	// for (int n = 1; n <= 6; ++n) {
	// 	vector<int> a(n);
	// 	while (a[0] < n) {
	// 		int st = stupid(a);
	// 		int so = solve(a);
	// 		if (st != so) {
	// 			cout << n << "\n";
	// 			for (int x : a) {
	// 				cout << x + 1 << " ";
	// 			}
	// 			cout << "\nstupid: " << st << "\n solve: " << so << "\n";
	// 			return 0;
	// 		} else {
	// 			// cerr << "ok ";
	// 		}
	// 		a.back() += 1;
	// 		for (int i = n - 1; i > 0; --i) {
	// 			if (a[i] == n) {
	// 				a[i] = 0;
	// 				a[i - 1] += 1;
	// 			} else {
	// 				break;
	// 			}
	// 		}
	// 	}
	// }

	int n = nxt();
	vector<int> a(n);
	for (int& x : a) {
		x = nxt() - 1;
	}
	cout << solve(a) << "\n";

	return 0;
}