#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	vector <ll> p(33);
	vector <ll> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	p[0] = 1;
	for (ll i = 1; i < 33; i++)
		p[i] = 2 * p[i - 1];
	for (ll i = 32; i >= 0; i--) {
		ll cnt = 0;
		ll id = 0;
		for (ll j = 0; j < n; j++) 
			if ((p[i] & a[j]) != 0) {
				cnt++;
				id = j;
			}
		if (cnt == 1) {
			swap(a[0], a[id]);
			for (auto now : a)
				cout << now << " ";
			return 0;
		}
	}
	for (auto now : a)
		cout << now << " ";
	return 0;
}