#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long

using namespace std;

int main() {
	ll t;
	cin >> t;
	while (t--) {
		vector <ll> a(3);
		for (ll i = 0; i < 3; i++)
			cin >> a[i];
		sort(a.begin(), a.end());
		ll ans1 = max((ll)0, (a[2] - a[0] - 2) * 2);
		cout << ans1 << endl;
	}
	return 0;
}