#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

void solve() {
	vector<int> cnt(26);
	int n = nxt(), k = nxt();
	string s;
	cin >> s;
	for (char c : s) {
		cnt[c - 'a'] += 1;
	}
	int ans = 0;
	for (int g = 1; g <= k; ++g) {
		if (k % g) {
			continue;
		}
		if (g > n) {
			continue;
		}
		int l = 1, r = n + 1;
		while (r > l + 1) {
			int m = (l + r) / 2;
			int tmp = 0;
			for (int x : cnt) {
				tmp += x / m;
			}
			(tmp >= g ? l : r) = m;
		}
		ans = max(ans, l * g);
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