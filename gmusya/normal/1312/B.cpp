#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		vector <ll> a(n);
		for (ll i = 0; i < n; i++)
			cin >> a[i];
		sort(a.begin(), a.end());
		reverse(a.begin(), a.end());
		for (ll i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << endl;
	}
	return 0;
}