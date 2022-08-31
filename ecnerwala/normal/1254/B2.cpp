#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	vector<ll> A(N);
	for (int i = 0; i < N; i++) cin >> A[i];
	ll tot = 0;
	for (int i = 0; i < N; i++) tot += A[i];
	if (tot <= 1) {
		cout << -1 << '\n';
		exit(0);
	}

	vector<ll> factors;
	for (ll p = 2; p * p <= tot; p ++) {
		if (tot % p == 0) {
			factors.push_back(p);
			do {
				tot /= p;
			} while (tot % p == 0);
		}
	}
	if (tot > 1) factors.push_back(tot);

	vector<ll> pref(N+1);
	for (int i = 0; i < N; i++) pref[i+1] = pref[i] + A[i];

	ll ans = 1e18;
	for (ll k : factors) {
		if (k == 1) continue;
		ll cnd = 0;
		for (int i = 1; i < N; i++) {
			ll v = pref[i] % k;
			cnd += min(v, k - v);
		}
		ans = min(ans, cnd);
	}
	cout << ans << '\n';

	return 0;
}