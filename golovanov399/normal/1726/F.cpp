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

struct Linear {
	long long a, b;
};

struct Node {
	bool final;
	Linear val;
};

struct Segtree {
	int n;
	vector<Node> a;

	Segtree(int _n) {
		n = 1;
		while (n < _n) {
			n *= 2;
		}
		a.resize(n + n, {false, {0ll, 0ll}});
	}

	void push(int v) {
		if (a[v].final) {
			for (int i : {0, 1}) {
				a[v + v + i].final = true;
				a[v + v + i].val = a[v].val;
			}
		}
		a[v].final = false;
	}

	void upd(int v, int l1, int r1, int l, int r, const Linear& lin) {
		if (l >= r1 || l1 >= r) {
			return;
		}
		if (l <= l1 && r >= r1) {
			a[v].final = true;
			a[v].val = lin;
			return;
		}
		push(v);
		int m = (l1 + r1) / 2;
		upd(v + v, l1, m, l, r, lin);
		upd(v + v + 1, m, r1, l, r, lin);
	}

	void upd(int l, int r, const Linear& lin) {
		upd(1, 0, n, l, r, lin);
	}

	Linear get(int pos) {
		Linear res = {0ll, 0ll};
		int v = pos + n;
		while (v) {
			if (a[v].final) {
				res = a[v].val;
			}
			v /= 2;
		}
		return res;
	}
};

void solve() {
	int n = nxt(), t = nxt();
	long long sum = 0;
	vector<int> g(n), c(n);
	for (int i = 0; i < n; ++i) {
		g[i] = nxt(), c[i] = nxt();
	}
	for (int i = 1; i < n; ++i) {
		c[i] = (c[i] + (sum += nxt())) % t;
	}

	vector<int> times = {0};
	for (int i = 0; i < n; ++i) {
		times.push_back((t - c[i]) % t);
		times.push_back((t - c[i] + g[i]) % t);
	}
	make_unique(times);
	const int sz = times.size();

	Segtree tree(sz);
	for (int i = n - 1; i >= 0; --i) {
		// if (time + c[i]) % t < g[i], then we copy
		int l = (t - c[i]) % t;
		int r = l + g[i];
		if (r >= t) {
			r -= t;
		}
		int li = lower_bound(all(times), l) - times.begin();
		int ri = lower_bound(all(times), r) - times.begin();
		auto lin = tree.get(li);
		long long val = lin.b + lin.a * l;
		// on [r, l) the answer is val + (waiting time)
		// waiting time at r is t - g[i]
		if (ri < li) {
			tree.upd(ri, li, {-1ll, t - g[i] + r + val});
		} else {
			tree.upd(ri, sz, {-1ll, t - g[i] + r + val});
			tree.upd(0, li, {-1ll, l + val});
		}
	}
	times.push_back(t);
	long long ans = 1e18;
	for (int i = 0; i < sz; ++i) {
		auto lin = tree.get(i);
		ans = min(ans, lin.a * (times[i + 1] - 1) + lin.b);
	}
	cout << ans + sum << "\n";
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}