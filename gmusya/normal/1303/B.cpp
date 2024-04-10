#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n, g, b;
		cin >> n >> g >> b;
		ll d = (n + 1) / 2;
		ll x = d / g;
		ll ans;
		if (x * g == d) {
			ans = (g + b) * (x - 1) + g;
			cout << max(n, ans) << endl;
			continue;
		}
		ans = (g + b) * x;
		ans += d - g * x;
		cout << max(n, ans) << endl;
	}
	return 0;
}