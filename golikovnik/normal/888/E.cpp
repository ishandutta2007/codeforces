#include <bits/stdc++.h>

#define int long long
#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())

using namespace std;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10); cout << fixed;
	int n, md;
	cin >> n >> md;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	auto get = [&](int l, int r) {
		set<int> res = set<int>({0});
		int len = r - l;
		if (!len) return res;
		for (int mask = 0; mask < (1 << len); ++mask) {
			int s = 0;
			for (int i = 0; i < len; ++i) {
				if ((mask >> i) & 1) {
					s += a[l + i];
					s %= md;
				}
			}
			res.insert(s);
		}		
		return res;
	};
	set<int> fi = get(0, n / 2), se = get(n / 2, n);
	int ans = 0;
	for (int x: fi) {
		for (int need: {md - x, 2 * md - x}) {
			auto it = se.lower_bound(need);
			if (it == se.begin()) continue;
			--it;
			ans = max(ans, (x + *it) % md);
		}
	}
	cout << ans << "\n";
	return 0;	
}