#include <bits/stdc++.h>

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) int32_t((x).size())

using namespace std;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(12); cout << fixed;
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	map<int, set<int>> mp;
	for (int i = 0; i < n; ++i) {
		mp[a[i]].insert(i);
	}
	vector<pair<int, int>> ans;
	for (const auto &item: mp) {
		if (sz(item.second) == 1) {
			ans.push_back({item.first, 0});
			continue;
		}
		bool ok = 1;
		int m = sz(item.second);
		vector<int> nums;
		nums.reserve(m);
		for (const int &x: item.second) nums.push_back(x);
		int res = nums[1] - nums[0];
		for (int i = 1; i + 1 < m; ++i) {
			ok &= (nums[i + 1] - nums[i] == res);
		}
		if (ok) ans.push_back({item.first, res});
	}
	cout << sz(ans) << "\n";
	for (const auto &p: ans) cout << p.first << " " << p.second << "\n";
	return 0;
}