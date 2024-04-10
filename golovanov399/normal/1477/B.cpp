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
	cin >> x;
	return x;
}

struct Segtree {
	int n;
	vector<int> to_push;
	vector<int> a;

	Segtree(const vector<int>& ar) {
		n = 1;
		while (n < (int)ar.size()) {
			n *= 2;
		}
		a.resize(n + n);
		to_push.resize(n + n, -1);
		for (int i = 0; i < (int)ar.size(); ++i) {
			a[n + i] = ar[i];
		}
		for (int i = n - 1; i > 0; --i) {
			a[i] = a[i + i] + a[i + i + 1];
		}
	}

	void push(int v, int len) {
		if (to_push[v] > -1) {
			to_push[v + v] = to_push[v];
			a[v + v] = len / 2 * to_push[v];
			to_push[v + v + 1] = to_push[v];
			a[v + v + 1] = len / 2 * to_push[v];
			to_push[v] = -1;
		}
	}

	int get(int v, int l1, int r1, int l, int r) {
		if (l >= r1 || l1 >= r) {
			return 0;
		}
		if (l <= l1 && r >= r1) {
			return a[v];
		}
		push(v, r1 - l1);
		int m = (l1 + r1) / 2;
		return get(v + v, l1, m, l, r) + get(v + v + 1, m, r1, l, r);
	}

	int get(int l, int r) {
		return get(1, 0, n, l, r);
	}

	void fill(int v, int l1, int r1, int l, int r, int x) {
		if (l >= r1 || l1 >= r) {
			return;
		}
		if (l <= l1 && r >= r1) {
			to_push[v] = x;
			a[v] = (r1 - l1) * to_push[v];
			return;
		}
		push(v, r1 - l1);
		int m = (l1 + r1) / 2;
		fill(v + v, l1, m, l, r, x);
		fill(v + v + 1, m, r1, l, r, x);
		a[v] = a[v + v] + a[v + v + 1];
	}

	void fill(int l, int r, int x) {
		fill(1, 0, n, l, r, x);
	}
};

void solve() {
	int n = nxt(), q = nxt();
	string s, f;
	cin >> s >> f;
	vector<pair<int, int>> qrs(q);
	for (int i = 0; i < q; ++i) {
		qrs[i].first = nxt() - 1;
		qrs[i].second = nxt();
	}

	vector<int> ar(n);
	for (int i = 0; i < n; ++i) {
		ar[i] = f[i] - '0';
	}
	Segtree tree(ar);
	reverse(all(qrs));
	for (auto [l, r] : qrs) {
		int cnt = tree.get(l, r);
		if (cnt * 2 == r - l) {
			puts("NO");
			return;
		}
		// cerr << l << " " << r << ": " << cnt << " " << (cnt * 2 < r - l ? 0 : 1) << "\n";
		tree.fill(l, r, cnt * 2 < r - l ? 0 : 1);
	}
	for (int i = 0; i < n; ++i) {
		if (tree.get(i, i + 1) != s[i] - '0') {
			puts("NO");
			return;
		}
	}
	puts("YES");
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}