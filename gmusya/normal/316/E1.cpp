#include <iostream>
#include <vector>

#define endl '\n'
#define ll long long

using namespace std;

const ll MOD = 1e9;

int main() {
	ll n, m;
	cin >> n >> m;
	vector <ll> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	vector <ll> f(n);
	f[0] = 1;
	if (n > 1)
		f[1] = 1;
	for (ll i = 2; i < n; i++)
		f[i] = (f[i - 1] + f[i - 2]) % MOD;
	vector <ll> answer;
	while (m--) {
		ll t;
		cin >> t;
		if (t == 1) {
			ll pos, val;
			cin >> pos >> val;
			pos--;
			a[pos] = val;
		}
		if (t == 2) {
			ll l, r;
			ll ans = 0;
			cin >> l >> r;
			l--;
			r--;
			for (ll i = l; i <= r; i++) 
				ans = (ans + a[i] * f[i - l]) % MOD;
			answer.push_back(ans);
		}
	}
	for (ll x : answer)
		cout << x << endl;
	return 0;
}