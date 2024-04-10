#include <bits/stdc++.h>

typedef long long ll;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); std::cout.tie(nullptr);

	int T; std::cin >> T;
	while (T--) {
		int n, m; std::cin >> n >> m;
		std::vector<ll> a(n); for (int i = 0; i != n; ++i) std::cin >> a[i];
		a.push_back(-1e10); a.push_back(1e10);
		std::sort(a.begin(), a.end()); n += 2;
		std::vector<std::vector<std::pair<ll, ll>>> rgs(n - 1);
		while (m--) {
			ll l, r; std::cin >> l >> r;
			int i = std::lower_bound(a.begin(), a.end(), l) - a.begin();
			if (r >= a[i]) continue;
			rgs[i - 1].emplace_back(l, r);
		}
		ll f = 0, g = 0;
		for (int i = 0; i != n - 1; ++i) {
			std::sort(rgs[i].begin(), rgs[i].end());
			int sz = rgs[i].size();
			ll mx = a[i + 1], t00, t01, t10, t11;
			t00 = t01 = t10 = t11 = std::numeric_limits<ll>::max();
			for (int j = sz - 1; j >= 0; --j) {
				ll x = rgs[i][j].first - a[i], y = a[i + 1] - mx;
				t00 = std::min(t00, x + y);
				t01 = std::min(t01, x + y * 2);
				t10 = std::min(t10, x * 2 + y);
				t11 = std::min(t11, x * 2 + y * 2);
				mx = std::min(mx, rgs[i][j].second);
			}
			ll y = a[i + 1] - mx;
			t00 = std::min(t00, y);
			t01 = std::min(t01, y * 2);
			t10 = std::min(t10, y);
			t11 = std::min(t11, y * 2);
			ll tf = std::min(g + t00, f + t10), tg = std::min(g + t01, f + t11);
			f = tf; g = tg;
		}
		std::cout << std::min(f, g) << '\n';
	}
	return 0;
}