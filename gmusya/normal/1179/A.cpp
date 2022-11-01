#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int main() {
	ll n, q;
	cin >> n >> q;
	vector <ll> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	vector <ll> ma(n);
	ma[0] = a[0];
	for (ll i = 1; i < n; i++)
		ma[i] = max(ma[i - 1], a[i]);
	ll ma_id = 0;
	for (ll i = 1; i < n; i++)
		if (a[i] > a[ma_id])
			ma_id = i;
	vector <ll> kek;
	for (ll i = 1; i < n; i++) 
		kek.push_back(min(ma[i - 1], a[i]));
	while (q--) {
		ll pos;
		cin >> pos;
		if (pos < n) {
			cout << ma[pos - 1] << " " << a[pos] << endl;
			continue;
		}
		cout << a[ma_id] << " " << kek[(pos - 1 + n - 1) % (n - 1)] << endl;
	}
	return 0;
}