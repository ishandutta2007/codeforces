#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

ll f(ll i, ll j) {
	if (i == -1) {
		return 0;
	}
	if (i & (1 << j)) {
		return ((i + 1) & ~((1 << (j + 1)) - 1)) / 2 + ((i + 1) & ((1 << j) - 1));
	} else {
		return (i & ~((1 << j) - 1)) / 2;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll t;
	cin >> t;
	while (t--) {
		ll l, r;
		cin >> l >> r;
		ll ans = 0;
		for (ll p = 0; p <= 30; ++p) {
			ll c1 = f(r, p), c2 = f(l - 1, p);
			ans = max(ans, c1 - c2);
		}
		cout << (r - l + 1) - ans << '\n';
	}
	return 0;
}