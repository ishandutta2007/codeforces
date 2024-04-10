#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main() {
	ll n;
	cin >> n;
	vector <ll> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	vector <ll> pre(n);
	pre[0] = a[0];
	for (ll i = 1; i < n; i++)
		pre[i] = pre[i - 1] + a[i];
	ll ans = 0;
	for (ll i = 0; i < n; i++)
		ans += (1 - a[i]) * pre[i];
	cout << ans;
	return 0;
}