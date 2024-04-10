#include <bits/stdc++.h>

#define int long long
#define all(x) (x).begin(), (x).end()
#define mp make_pair

using namespace std;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		int r;
		cin >> r;
		a[i] = {-r, i};
	}
	vector<int> ans(n);
	for (int i = 0; i < k; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		if (-a[x].first < -a[y].first) swap(x, y);
		if (-a[x].first > -a[y].first) --ans[x];
	}	
	sort(all(a));
	for (int i = 0; i < n; ++i) {
		int r = a[i].first, who = a[i].second;
		int res = a.end() - lower_bound(all(a), mp(r + 1, 0ll));
		ans[who] += res;
	}
	for (int x: ans) cout << x << " ";
	cout << "\n";
	return 0;	
}