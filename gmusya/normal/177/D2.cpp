#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int main() {
	ll n, m, c;
	cin >> n >> m >> c;
	vector <ll> a(n + 1), b(m + 1), pre(m + 1);
	for (ll i = 1; i <= n; i++)
		cin >> a[i];
	for (ll i = 1; i <= m; i++)
		cin >> b[i];
	for (ll i = 1; i <= m; i++)
		pre[i] = (pre[i - 1] + b[i]) % c;
	for (ll i = 1; i <= n; i++) {
		ll l = max((ll) 1, i + m - n);
		ll r = min(m, i);
		a[i] = (a[i] + pre[r] - pre[l - 1] + c) % c;
	}
	for (ll i = 1; i <= n; i++)
		cout << a[i] << " ";
	return 0;
}