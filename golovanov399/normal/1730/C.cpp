#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
// #define make_unique(x) sort(all(x)); x.resize(unique(all(x)) - x.begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

void solve() {
	string s;
	cin >> s;
	array<int, 10> cnt({});
	for (auto c : s) {
		cnt[c - '0'] += 1;
	}
	int i = 0;
	string ans = "";
	array<int, 10> reserved({});
	for (int d = 0; d < 9; ++d) {
		ans += string(reserved[d], '0' + d);
		while (cnt[d] > 0) {
			if (s[i] == '0' + d) {
				ans += s[i];
				--cnt[d];
			} else {
				int dd = s[i] - '0';
				--cnt[dd];
				++reserved[min(dd + 1, 9)];
			}
			++i;
		}
	}
	ans += string(cnt[9] + reserved[9], '9');
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