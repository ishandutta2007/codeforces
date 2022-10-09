#include <iostream>
#include <vector>
#include <algorithm>

#define int long long

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1);
	vector<long long> pref(n + 1);
	long long mx = -1e18;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		pref[i + 1] = pref[i] + a[i];
		mx = max(mx, pref[i + 1]);
	}
	long long sum = pref[n];
	vector<long long> ans(m, -1);
	vector<pair<int, pair<int, long long>>> q;
	for (int j = 0; j < m; ++j) {
		int x;
		cin >> x;
		if (sum <= 0) {
			q.push_back({x, {j, 0}});
		} else {
			int k = max(1ll * 0, (x - mx + sum - 1) / sum);
			q.push_back({x - k * sum, {j, (long long) k * n}});
		}
	}
	sort(q.rbegin(), q.rend());
	if (q.back().first == 0)
		exit(1);
	for (int i = 1; i <= n; ++i) {
		while (q.size() && pref[i] >= q.back().first) {
			ans[q.back().second.first] = q.back().second.second + i - 1;
			q.pop_back();
		}
	}
	for (auto i : ans)
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