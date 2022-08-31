#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

void solve() {
	int n = nxt();
	string s, t;
	cin >> s >> t;
	int ans = -1;
	for (int par : {0, 1}) {
		int cnt[2] = {0, 0};
		for (int i = 0; i < n; ++i) {
			if (s[i] != t[i]) {
				cnt[t[i] - '0'] += 1;
			}
		}
		if ((cnt[0] + cnt[1]) % 2 == par && (cnt[0] == cnt[1] || cnt[1] == cnt[0] + 1)) {
			if (ans == -1 || ans > cnt[0] + cnt[1]) {
				ans = cnt[0] + cnt[1];
			}
		}
		for (char& c : s) {
			c = (c == '0') ? '1' : '0';
		}
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}