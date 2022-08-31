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

void solve() {
	int n = nxt(), m = nxt();
	vector<vector<int>> ans;

	vector<vector<int>> a(n, vector<int>(m, 0));
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			a[i][j] = s[j] - '0';
		}
	}
	auto add = [&](int i, int j, int x, int y) {
		ans.push_back({});
		for (int dx : {0, 1}) {
			for (int dy : {0, 1}) {
				if (i + dx != x || j + dy != y) {
					ans.back().push_back(i + dx);
					ans.back().push_back(j + dy);
					a[i + dx][j + dy] ^= 1;
				}
			}
		}
	};

	for (int i = 0; i < n - 2; ++i) {
		for (int j = 0; j < m - 2; ++j) {
			if (a[i][j]) {
				add(i, j, i + 1, j + 1);
			}
		}
	}
	for (int j = 0; j < m - 2; ++j) {
		if (a[n - 2][j] && a[n - 1][j]) {
			add(n - 2, j, n - 2, j + 1);
		} else if (a[n - 2][j]) {
			add(n - 2, j, n - 1, j);
		} else if (a[n - 1][j]) {
			add(n - 2, j, n - 2, j);
		}
	}
	for (int i = 0; i < n - 2; ++i) {
		if (a[i][m - 2] && a[i][m - 1]) {
			add(i, m - 2, i + 1, m - 2);
		} else if (a[i][m - 2]) {
			add(i, m - 2, i, m - 1);
		} else if (a[i][m - 1]) {
			add(i, m - 2, i, m - 2);
		}
	}

	bool huevo = a[n - 2][m - 2] ^ a[n - 2][m - 1] ^ a[n - 1][m - 2] ^ a[n - 1][m - 1];
	if (huevo) {
		a[n - 2][m - 2] ^= 1;
		a[n - 2][m - 1] ^= 1;
		a[n - 1][m - 2] ^= 1;
		a[n - 1][m - 1] ^= 1;
	}
	vector<pair<int, int>> to_add;
	for (int i : {n - 2, n - 1}) {
		for (int j : {m - 2, m - 1}) {
			if (a[i][j]) {
				to_add.push_back({i, j});
			}
		}
	}
	if (huevo) {
		a[n - 2][m - 2] ^= 1;
		a[n - 2][m - 1] ^= 1;
		a[n - 1][m - 2] ^= 1;
		a[n - 1][m - 1] ^= 1;
	}
	for (auto [i, j] : to_add) {
		add(n - 2, m - 2, i, j);
	}

	cout << ans.size() << "\n";
	for (auto v : ans) {
		for (int x : v) {
			cout << x + 1 << " ";
		}
		cout << "\n";
	}

	// for (auto v : a) {
	// 	for (int x : v) {
	// 		cerr << x << " ";
	// 	}
	// 	cerr << "\n";
	// }
	for (auto v : a) {
		assert(!*max_element(all(v)));
	}
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}