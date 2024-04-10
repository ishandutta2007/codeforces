#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long 

using namespace std;

int main() {
	ll n, k;
	cin >> n >> k;
	vector <ll> a(n), b(n), c(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	for (ll i = 0; i < n; i++)
		cin >> b[i];
	ll sum = 0;
	for (ll i = 0; i < n; i++)
		if (b[i])
			sum += a[i];
	for (ll i = 0; i < n; i++)
		if (!b[i])
			c[i] = a[i];
	vector <ll> pre(n);
	pre[0] = c[0];
	for (ll i = 1; i < n; i++)
		pre[i] = pre[i - 1] + c[i];
	ll ma = pre[k - 1];
	for (ll i = 0; i < n - k; i++)
		ma = max(ma, pre[i + k] - pre[i]);
	cout << sum + ma;
	return 0;
}