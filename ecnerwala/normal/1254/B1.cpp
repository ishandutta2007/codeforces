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
	for (ll k = 1; k * k <= tot; k++) {
		if (tot % k == 0) {
			factors.push_back(k);
			if (tot / k > k) {
				factors.push_back(tot / k);
			}
		}
	}

	vector<ll> pos;
	for (int i = 0; i < N; i++) {
		if (A[i]) pos.push_back(i);
	}
	ll ans = 1e18;
	for (ll k : factors) {
		if (k == 1) continue;
		ll cnd = 0;
		for (int i = 0; i < tot; i++) {
			cnd += abs(pos[i] - pos[i - i % k + k / 2]);
		}
		ans = min(ans, cnd);
	}
	cout << ans << '\n';

	return 0;
}