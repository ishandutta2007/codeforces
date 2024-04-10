#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		vector <ll> a(n);
		for (ll i = 0; i < n; i++)
			cin >> a[i];
		ll ans = a[0];
		ll sum = 0;
		for (ll i = 0; i < n; i++)
			sum += a[i];
		for (ll i = 1; i < n; i++) 
			ans = ans ^ a[i];
		ll x;
		cout << 3 << endl;
		x = 1e15 + (ans % 2);
		cout << x << " ";
		sum += x;
		ans = ans ^ x;
		cout << (2 * ans - sum) / 2 << " " << (2 * ans - sum) / 2 << endl;
		sum += (2 * ans - sum);
	}
	return 0;
}