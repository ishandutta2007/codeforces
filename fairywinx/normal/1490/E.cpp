#include <iostream>
#include <vector>
#include <algorithm>

#define int long long

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first;
		a[i].second = i + 1;
	}
	sort(a.begin(), a.end());
	long long sum = 0;
	vector<int> ans;
	int l = 0;
	for (int i = 0; i < n - 1; ++i) {
		sum += a[i].first;
		if (sum < a[i + 1].first)
			l = i + 1;
	}
	for (int i = l; i < n; ++i)
		ans.push_back(a[i].second);
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int i : ans)
		cout << i << ' ';
	cout << '\n';
}

signed main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();
}