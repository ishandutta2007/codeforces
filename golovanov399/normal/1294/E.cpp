#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	int n = nxt(), m = nxt();
	vector<vector<int>> a(m, vector<int>(n, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			a[j][i] = nxt() - 1;
		}
	}

	int ans = 0;
	for (int i = 0; i < m; ++i) {
		map<int, int> M;
		for (int j = 0; j < n; ++j) {
			if (a[i][j] % m == i && a[i][j] < n * m) {
				M[(j - (a[i][j] / m) + n) % n] += 1;
			}
		}
		int mn = n;
		for (auto [s, c] : M) {
			mn = min(mn, s + n - c);
		}
		ans += mn;
	}
	cout << ans << "\n";

	return 0;
}