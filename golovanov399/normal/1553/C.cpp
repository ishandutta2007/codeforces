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
	string s;
	cin >> s;
	int ans = 10;
	for (int winner : {0, 1}) {
		auto t = s;
		for (int i = 0; i < 10; ++i) {
			if (s[i] != '?') {
				continue;
			}
			t[i] = '0' + (i % 2 == winner);
		}
		int rest[2] = {5, 5};
		int cur[2] = {0, 0};
		for (int i = 0; i < 10; ++i) {
			rest[i % 2] -= 1;
			cur[i % 2] += (t[i] == '1');
			if (cur[0] > cur[1] + rest[1] || cur[1] > cur[0] + rest[0]) {
				ans = min(ans, i + 1);
			}
		}
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