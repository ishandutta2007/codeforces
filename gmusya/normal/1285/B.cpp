#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'
#define ll long long

using namespace std;

int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		vector <ll> a(n);
		ll sum = 0;
		for (ll i = 0; i < n; i++)
			cin >> a[i];
		for (ll i = 0; i < n; i++)
			sum += a[i];
		ll cur = 0;
		ll ans = 0;
		for (ll i = 0; i < n - 1; i++) {
			cur += a[i];
			ans = max(ans, cur);
			cur = max((ll)0, cur);
		}
		cur = 0;
		for (ll i = 1; i < n; i++) {
			cur += a[i];
			ans = max(ans, cur);
			cur = max((ll)0, cur);
		}
		if (sum > ans)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}