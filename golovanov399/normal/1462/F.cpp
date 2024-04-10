#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

void solve() {
	int n = nxt();
	vector<pair<int, int>> a(n);
	vector<int> rs(n), ls(n);
	for (int i = 0; i < n; ++i) {
		ls[i] = a[i].first = nxt();
		rs[i] = a[i].second = nxt();
	}
	sort(all(ls));
	sort(all(rs));
	int ans = n;
	for (auto [l, r] : a) {
		ans = min<int>(ans, (lower_bound(all(rs), l) - rs.begin()) + (ls.end() - upper_bound(all(ls), r)));
	}
	cout << ans << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}