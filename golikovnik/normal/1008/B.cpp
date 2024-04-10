#include <bits/stdc++.h>

#define int long long
#define all(x) (x).begin(), (x).end()

using namespace std;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for (auto &x: a) cin >> x.first >> x.second;
	bool ok = 1;
	int prev = -1;
	for (int i = 0; i < n; ++i) {
		if (prev < 0) {
			prev = max(a[0].first, a[0].second);
			continue;
		}
		int x = min(a[i].first, a[i].second);
		int y = max(a[i].first, a[i].second);
		if (y <= prev) {
			prev = y;
			continue;
		} else if (x <= prev) {
			prev = x;
			continue;
		} else {
			ok = 0;
			break;
		}
	}
	cout << (ok ? "YES" : "NO") << "\n";
	return 0;	
}