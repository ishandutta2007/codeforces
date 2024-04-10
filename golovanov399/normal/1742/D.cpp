#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

void solve() {
	int n = nxt();
	const int m = 1011;
	vector<int> mx(m, -1);
	vector<int> ones;
	for (int i = 0; i < n; ++i) {
		int x = nxt();
		mx[x] = i + 1;
		if (x == 1) {
			ones.push_back(i + 1);
		}
	}
	int ans = -1;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			if (mx[i] > -1 && mx[j] > -1 && gcd(i, j) == 1) {
				ans = max(ans, mx[i] + mx[j]);
			}
		}
	}
	if ((int)ones.size() >= 1) {
		ans = max(ans, ones.back() * 2);
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	for (int i = 1; i <= t; ++i) {
		solve();
	}

	return 0;
}