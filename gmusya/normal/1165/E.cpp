#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long

using namespace std;

const ll MOD = 998244353;

int main() {
	ll n;
	cin >> n;
	vector <ll> a(n), b(n);
	for (ll i = 0; i < n; i++) 
		cin >> a[i];
	for (ll i = 0; i < n; i++)
		a[i] = a[i] * (i + 1) * (n - i);
	for (ll i = 0; i < n; i++) 
		cin >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	ll ans = 0;
	for (ll i = 0; i < n; i++)
		ans = (ans + (a[i] % MOD) * b[n - i - 1]) % MOD;
	cout << ans;
	return 0; 
}