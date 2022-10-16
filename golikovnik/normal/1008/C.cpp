#include <bits/stdc++.h>

#define int long long
#define all(x) (x).begin(), (x).end()

using namespace std;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	map<int, int> mp;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		++mp[x];
		a[i] = x;
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int cur = a[i];
		auto it = mp.lower_bound(cur);
		if (it == mp.begin()) continue;
		--it;
		int key = it->first;
		++ans;
		--mp[key];
		if (!mp[key]) mp.erase(key);
	}
	cout << ans << "\n";
	return 0;	
}