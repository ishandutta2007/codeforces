#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;

int main() {
	ll n;
	cin >> n;
	vector <ll> a(n);
	ll black = 0, white = 0;
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	for (ll i = 0; i < n; i++) {
		if (i % 2 == 0) {
			black += a[i] / 2;
			white += (a[i] + 1) / 2;
		}
		if (i % 2 == 1) {
			black += (a[i] + 1) / 2;
			white += a[i] / 2;
		}
	}
	cout << min(black, white);
	return 0;
}