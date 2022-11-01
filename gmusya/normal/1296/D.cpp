#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int main() {
	ll n, a, b, k;
	cin >> n >> a >> b >> k;
	vector <ll> arr(n), brr(n);
	for (ll i = 0; i < n; i++)
		cin >> arr[i];
	for (ll i = 0; i < n; i++) {
		ll x = arr[i] % (a + b);
		if (x == 0)
			x = a + b;
		brr[i] = ((x + a - 1) / a) - 1;
	}
	sort(brr.begin(), brr.end());
	ll cnt = 0;
	for (ll i = 0; i < n; i++) {
		if (k >= brr[i]) {
			k -= brr[i];
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}