#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>

#define ll long long
#define endl '\n'
using namespace std;

int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		vector <ll> a(n);
		ll sum = 0;
		ll zeros = 0;
		for (ll i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
			if (a[i] == 0)
				zeros++;
		}
		ll cnt = 0;
		cnt += zeros;
		sum += zeros;
		if (sum == 0)
			cnt++;
		cout << cnt << endl;
	}
	return 0;
}