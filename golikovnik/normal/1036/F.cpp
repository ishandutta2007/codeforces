#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 1000000000000000000;

#define sqr(x) ((x) * (x))

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10); cout << fixed;
	int t; cin >> t;
	vector<ll> powers;
	powers.reserve(1003479);
	for (ll base = 2; base * base * base <= INF; ++base) {
		ll start = base * base * base;
		if (sqr(1LL * int32_t(sqrtl(start))) != start)
			powers.push_back(start);
		while ((INF + base - 1) / base >= start) {
			start *= base;
			if (sqr(1LL * int32_t(sqrtl(start))) != start)
				powers.push_back(start);
		}
	}
	sort(all(powers));
	powers.resize(unique(all(powers)) - powers.begin());
	while (t--) {
		ll n; cin >> n;
		ll ans = int32_t(sqrtl(n)) - 1;
		ans += upper_bound(all(powers), n) - powers.begin();
		ans = n - 1 - ans;
		cout << ans << "\n";
	}
	return 0;	
}