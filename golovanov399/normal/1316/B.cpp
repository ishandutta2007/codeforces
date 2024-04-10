#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

void solve() {
	int n = nxt();
	string s;
	cin >> s;
	pair<string, int> ans = {string(n + 1, 'z'), n};
	for (int k = 1; k <= n; ++k) {
		string t = s.substr(k - 1) + s.substr(0, k - 1);
		if (n % 2 == k % 2) {
			reverse(t.end() - (k - 1), t.end());
		}
		ans = min(ans, {t, k});
	}
	cout << ans.first << "\n" << ans.second << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}