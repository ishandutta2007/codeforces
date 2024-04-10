#include <iostream>
#include <vector> 
#include <algorithm>

#define ll long long
#define endl '\n'
using namespace std;

int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		n *= 2;
		vector <ll> a(n);
		for (ll i = 0; i < n; i++)
			cin >> a[i];
		sort(a.begin(), a.end());
		cout << a[n / 2] - a[n / 2 - 1] << endl;
	}
	return 0;
}