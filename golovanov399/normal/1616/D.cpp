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

const int inf = 1e9;

struct Segtree {
	int n;
	vector<int> a;

	Segtree(int _n) {
		n = 1;
		while (n < _n) {
			n *= 2;
		}
		a.resize(n + n, -inf);
	}

	void upd(int pos, int x) {
		int v = pos + n;
		a[v] = x;
		while (v > 1) {
			v /= 2;
			a[v] = max(a[v + v], a[v + v + 1]);
		}
	}

	int get(int v, int l1, int r1, int l, int r) {
		if (l >= r1 || l1 >= r) {
			return -inf;
		}
		if (l <= l1 && r >= r1) {
			return a[v];
		}
		int m = (l1 + r1) / 2;
		return max(get(v + v, l1, m, l, r), get(v + v + 1, m, r1, l, r));
	}

	int get(int l, int r) {
		return get(1, 0, n, l, r);
	}
};

void solve() {
	int n = nxt();
	vector<long long> a(n);
	generate(all(a), nxt);
	int x = nxt();
	for (auto& y : a) {
		y -= x;
	}
	vector<long long> p(n + 1);
	partial_sum(all(a), p.begin() + 1);

	vector<int> dp(n + 1, 0);
	Segtree tree(n + 1);
	tree.upd(0, 0);
	vector<pair<long long, int>> st;
	int last = 0;
	for (int i = 1; i <= n; ++i) {
		// for (auto p : st) {
		// 	cerr << "(" << p.first << ", " << p.second << ") ";
		// }
		// cerr << "\n";
		auto it = lower_bound(all(st), pair{p[i], i}, greater<pair<long long, int>>());
		int l = (it == st.begin()) ? 0 : prev(it)->second + 1;
		l = max(l, last);
		// cerr << l << " " << i << "\n";
		dp[i] = tree.get(l, i) + i;
		last = max(last, l);
		// cerr << "dp = " << dp[i] << "\n";
		tree.upd(i, dp[i - 1] - i);

		while (!st.empty() && st.back().first <= p[i - 1]) {
			st.pop_back();
		}
		st.push_back({p[i - 1], i - 1});
	}
	cout << dp[n] << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}