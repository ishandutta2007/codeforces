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

void solve() {
	int n = nxt(), m = nxt();
	vector<vector<int>> a(n, vector<int>(m, 0));
	bool fail = false;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			a[i][j] = nxt();
			int c = 0;
			if (i > 0) {
				++c;
			}
			if (i < n - 1) {
				++c;
			}
			if (j > 0) {
				++c;
			}
			if (j < m - 1) {
				++c;
			}
			if (c < a[i][j]) {
				fail = true;
			}
			a[i][j] = c;
		}
	}
	if (fail) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	for (const auto& v : a) {
		for (int x : v) {
			cout << x << " ";
		}
		cout << "\n";
	}
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}