#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main() {
	ll n, k;
	cin >> n >> k;
	vector <ll> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	vector <ll> b(n);
	b[0] = 0;
	ll uk = 0;
	for (ll i = 1; i < n; i++) {
		if (a[uk] > a[i]) {
			b[uk]++;
		}
		else {
			uk = i;
			b[uk]++;
		}
		if (b[uk] == k) {
			cout << a[uk];
			return 0;
		}
	}
	ll ma = 0;
	for (ll i = 0; i < n; i++)
		if (a[ma] < a[i])
			ma = i;
	cout << a[ma];
	return 0;
}