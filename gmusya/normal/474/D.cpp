#include <iostream>
#include <vector>

#define ll long long
using namespace std;

const ll MOD = 1e9 + 7;

int main() {
	std::ios::sync_with_stdio(false);
	ll t, k;
	cin >> t >> k;
	vector <ll> a(1e5 + 1 + k);
	a[0] = 1;
	for (ll i = 0; i < 1e5; i++) {
		a[i + k] = (a[i + k] + a[i]) % MOD;
		a[i + 1] = (a[i + 1] + a[i]) % MOD;
	}
	vector <ll> sum(a.size());
	sum[1] = a[1];
	for (ll i = 1; i < a.size() - 1; i++)
		sum[i] = (sum[i - 1] + a[i]) % MOD;
	while (t--) {
		ll l, r;
		cin >> l >> r;
		cout << (sum[r] - sum[l - 1] + MOD) % MOD << '\n';
	}
	return 0;
}