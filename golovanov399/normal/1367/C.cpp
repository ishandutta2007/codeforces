#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

void solve() {
	[[maybe_unused]] int n = nxt(), k = nxt();
	string s;
	cin >> s;
	int ans = 0;
	int cur = 0;
	bool initial = true;
	for (char c : s) {
		if (c == '1') {
			ans += initial ? cur / (k + 1) : (cur + 1) / (k + 1) - 1;
			cur = 0;
			initial = false;
		} else {
			cur += 1;
		}
	}
	ans += initial ? (cur + k) / (k + 1) : cur / (k + 1);
	cout << ans << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}