#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	ll g; cin >> g;
	for (int i = 1; i < N; i++) {
		ll a; cin >> a;
		g = __gcd(a, g);
	}

	ll ans = 1;
	for (ll p = 2; p * p <= g; p++) {
		ll e = 0;
		while (g % p == 0) {
			g /= p;
			e++;
		}
		ans *= e+1;
	}
	if (g > 1) {
		ans *= 2;
	}
	cout << ans << '\n';

	return 0;
}