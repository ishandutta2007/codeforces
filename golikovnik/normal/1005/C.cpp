#include <bits/stdc++.h>

#define int long long
#define all(x) (x).begin(), (x).end()

using namespace std;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	map<int, int> mp;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		++mp[x];
	}
	int ans = 0;
	for (auto &p: mp) {
		int ok = 0;
		for (int LOG = 34; LOG >= 0; --LOG) {
			if (p.first + p.first == (1LL << LOG) && p.second == 1) continue;
			ok |= (mp.find((1LL << LOG) - p.first) != mp.end());
		}
		ans += (!ok) * p.second;
	}
	cout << ans << "\n";
	return 0;	
}