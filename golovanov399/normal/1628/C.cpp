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

void solve() {
	int n = nxt();
	int ans = 0;
	vector<vector<int>> a(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			a[i][j] = nxt();
		}
	}
	vector<vector<char>> b(n, vector<char>(n, 0));
	auto touch = [&](int i, int j) {
		ans ^= a[i][j];
		if (i) {
			b[i - 1][j] ^= 1;
		}
		if (i < n - 1) {
			b[i + 1][j] ^= 1;
		}
		if (j) {
			b[i][j - 1] ^= 1;
		}
		if (j < n - 1) {
			b[i][j + 1] ^= 1;
		}
	};
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (!b[i - 1][j]) {
				touch(i, j);
			}
		}
	}
	// for (int i = 0; i < n; ++i) {
	// 	for (int j = 0; j < n; ++j) {
	// 		assert(b[i][j]);
	// 	}
	// }
	cout << ans << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}