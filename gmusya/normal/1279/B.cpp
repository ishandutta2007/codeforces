#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;

int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n, s;
		cin >> n >> s;
		vector <ll> a(n);
		for (ll i = 0; i < n; i++)
			cin >> a[i];
		ll sum = 0;
		ll i;
		for (i = 0; i < n; i++) {
			if (sum + a[i] > s) {
				break;
			}
			sum += a[i];
		}
		if (i == 0) {
			cout << "1" << endl;
			continue;
		}
		if (i == n || i == n - 1) {
			cout << "0" << endl;
			continue;
		}
		ll ma = 0;
		for (ll j = 0; j <= i + 1; j++)
			if (a[ma] < a[j])
				ma = j;
		if (a[i + 1] < a[ma])
			cout << ma + 1 << endl;
		else
			cout << "0" << endl;
	}
	return 0;
}