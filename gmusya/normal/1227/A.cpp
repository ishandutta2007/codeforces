#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		ll right = 0, left = 10000000000;
		ll n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			ll l, r;
			cin >> l >> r;
			right = max(right, l);
			left = min(left, r);
		}
		cout << max( (ll) 0, right - left) << endl;
	}
	return 0;
}