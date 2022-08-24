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

void remax(int& x, int y) {
	x = (x < y) ? y : x;
}

void remin(int& x, int y) {
	x = (x > y) ? y : x;
}

void solve() {
	int n = nxt(), m = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	{
		auto b = a;
		make_unique(b);
		for (int& x : a) {
			x = lower_bound(all(b), x) - b.begin();
		}
	}
	const int sz = a.size();
	vector<vector<int>> where(sz);
	for (int i = 0; i < n; ++i) {
		where[a[i]].push_back(i);
	}

	vector<vector<int>> to_add(n);
	for (int i = 0; i < m; ++i) {
		int l = nxt() - 1, r = nxt();
		to_add[l].push_back(r);
	}

	vector<int> ptr(sz);
	multiset<int> rs;
	vector<int> to_remax(n + 1, -1);
	for (int i = 0; i < n; ++i) {
		rs.erase(i);
		for (int x : to_add[i]) {
			rs.insert(x);
		}
		// for (auto y : rs) {
		// 	cerr << y << ", ";
		// }
		// cerr << "\n";
		int v = a[i];
		if (!rs.empty()) {
			int mx = *rs.rbegin();
			int j = lower_bound(all(where[v]), mx) - where[v].begin();
			// cerr << i << ": value = " << v << ", last = " << j - 1 << "\n";
			// from ptr[v] to j - 1
			if (ptr[v] < j - 1) {
				// on [0, i] remax with where[j - 2]
				// on [i + 1, where[ptr[v] + 1]] remax with where[j - 1]
				// on [where[ptr[v] + 1] + 1, n) remax with infty
				remax(to_remax[0], where[v][j - 2]);
				remax(to_remax[i + 1], where[v][j - 1]);
				remax(to_remax[where[v][ptr[v] + 1] + 1], inf);
			}
		}
		++ptr[v];
	}
	// for (auto x : to_remax) {
	// 	cerr << x << " ";
	// }
	// cerr << "\n";

	int ans = inf;
	int cur = -inf;
	for (int i = 0; i < n; ++i) {
		remax(cur, to_remax[i]);
		remin(ans, cur - i + 1);
	}
	if (ans < 0) {
		ans = 0;
	}
	cout << ans << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}