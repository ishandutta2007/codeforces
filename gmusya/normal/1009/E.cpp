#include <iostream>
#include <vector>

#define ll long long

using namespace std;

const ll MOD = 998244353;

int main() {
	ll n;
	cin >> n;
	vector <ll> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	vector <ll> pre(n);
	pre[0] = a[0];
	for (ll i = 1; i < n; i++)
		pre[i] = (pre[i - 1] + a[i]) % MOD;
	vector <ll> p2(n);
	p2[0] = 1;
	for (ll i = 1; i < n; i++)
		p2[i] = (p2[i - 1] * 2) % MOD;
	vector <ll> kek(n), sum(n);
	kek[0] = 1;
	sum[0] = 1;
	for (ll i = 1; i < n; i++) {
		kek[i] = (sum[i - 1] + p2[i - 1]) % MOD;
		sum[i] = (sum[i - 1] + kek[i]) % MOD;
	}
	ll ans = 0;
	for (ll i = 0; i < n; i++)
		ans = (ans + kek[i] * pre[n - i - 1]) % MOD;
	cout << ans;
	return 0;
}