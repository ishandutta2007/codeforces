#include <bits/stdc++.h>

#define int long long
#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())

using namespace std;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10); cout << fixed;
	string s;
	cin >> s;
	int n = szof(s);
	int ans = n;
	for (char c = 'a'; c <= 'z'; ++c) {
		int mx = 0;
		int prev = -1;
		for (int i = 0; i < n; ++i) {
			if (s[i] == c) {
				if (prev < 0) {
					prev = mx = i;
				} else {
					mx = max(mx, i - prev - 1);
					prev = i;
				}
			}
		}
		if (prev < 0) continue;
		mx = max(mx, n - prev - 1);
		ans = min(ans, mx + 1);
	}
	cout << ans << "\n";
	return 0;	
}