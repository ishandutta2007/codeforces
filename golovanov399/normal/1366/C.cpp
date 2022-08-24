#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

void solve() {
	int n = nxt(), m = nxt();
	vector<int> cnt[2];
	for (int i = 0; i < 2; ++i) {
		cnt[i].resize(n + m - 1);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cnt[nxt()][i + j] += 1;
		}
	}
	int ans = 0;
	for (int i = 0; i + i < n + m - 2; ++i) {
		ans += min(cnt[0][i] + cnt[0][n + m - 2 - i], cnt[1][i] + cnt[1][n + m - 2 - i]);
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