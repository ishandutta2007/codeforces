#pragma GCC optimize("O3")

#include <iostream>
#include <algorithm>

using namespace std;

using ll = long long;

ll solve(ll n) {
	if (n == 1) {
		return -1;
	}
	if (n % 2 == 1) {
		return 2;
	}
	ll x = 2;
	while (n % 2 == 0) {
		n /= 2;
		x *= 2;
	}
	if (n == 1) {
		return -1;
	} else {
		return min(x, n);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		ll res = solve(n);
		cout << solve(n) << '\n';
	}
	return 0;
}