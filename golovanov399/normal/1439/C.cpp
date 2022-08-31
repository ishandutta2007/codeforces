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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Node {
	int sz;
	int mx;
	int to_remax;
	long long sum;
};

void remax(int& x, int y) {
	x = max(x, y);
}

void merge(const Node& l, const Node& r, Node& res) {
	res = {
		l.sz + r.sz,
		max(l.mx, r.mx),
		0,
		l.sum + r.sum
	};
}

struct SegTree {
	int n;
	vector<Node> a;

	SegTree(const vector<int>& ar) {
		n = 1;
		while (n < (int)ar.size()) {
			n *= 2;
		}
		a.resize(n * 2, {0, 0, 0, 0ll});
		for (int i = 0; i < (int)ar.size(); ++i) {
			a[n + i] = {1, ar[i], 0, ar[i]};
		}
		for (int i = n - 1; i > 0; --i) {
			merge(a[i + i], a[i + i + 1], a[i]);
		}
	}

	void push(int v) {
		if (a[v].to_remax) {
			for (int t : {0, 1}) {
				::remax(a[v + v + t].mx, a[v].to_remax);
				::remax(a[v + v + t].to_remax, a[v].to_remax);
				a[v + v + t].sum = a[v + v + t].sz * a[v + v + t].mx;
			}
			a[v].to_remax = 0;
		}
	}

	long long getSum(int v, int l1, int r1, int l, int r) {
		if (l >= r1 || l1 >= r) {
			return 0;
		}
		if (l <= l1 && r >= r1) {
			return a[v].sum;
		}
		push(v);
		int m = (l1 + r1) / 2;
		return getSum(v + v, l1, m, l, r) + getSum(v + v + 1, m, r1, l, r);
	}

	long long getSum(int l, int r) {
		return getSum(1, 0, n, l, r);
	}

	int getLeftNoMore(int x) {
		int v = 1;
		if (a[v].mx <= x) {
			return 0;
		}
		int l = 0, r = n;
		while (r > l + 1) {
			int m = (l + r) / 2;
			if (a[v + v + 1].mx <= x) {
				v = v + v;
				r = m;
			} else {
				v = v + v + 1;
				l = m;
			}
		}
		return r;
	}

	void remax(int v, int l1, int r1, int l, int r, int x) {
		if (l >= r1 || l1 >= r) {
			return;
		}
		if (l <= l1 && r >= r1) {
			::remax(a[v].to_remax, x);
			::remax(a[v].mx, x);
			a[v].sum = a[v].sz * a[v].mx;
			return;
		}
		push(v);
		int m = (l1 + r1) / 2;
		remax(v + v, l1, m, l, r, x);
		remax(v + v + 1, m, r1, l, r, x);
		a[v].sum = a[v + v].sum + a[v + v + 1].sum;
		a[v].mx = max(a[v + v].mx, a[v + v + 1].mx);
	}

	void remax(int l, int r, int x) {
		l = max(l, getLeftNoMore(x));
		if (l < r) {
			remax(1, 0, n, l, r, x);
		}
	}

	int get(int pos) {
		int v = n + pos;
		int ans = a[v].mx;
		while (v > 1) {
			v /= 2;
			::remax(ans, a[v].to_remax);
		}
		return ans;
	}
};

void solve() {
	int n = nxt(), q = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	SegTree tree(a);
	while (q--) {
		int t = nxt();
		if (t == 1) {
			int x = nxt(), y = nxt();
			tree.remax(0, x, y);
		} else {
			int x = nxt() - 1, y = nxt();

			int ans = 0;
			while (x < n) {
				remax(x, tree.getLeftNoMore(y));
				if (x == n) {
					break;
				}
				int val = tree.get(x);
				int cnt = min(y / val, n - x);
				ans += cnt;
				y -= tree.getSum(x, x + cnt);
				x += cnt;
			}
			printf("%d\n", ans);
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