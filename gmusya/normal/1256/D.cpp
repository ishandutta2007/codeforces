#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n, k;
		cin >> n >> k;
		vector <char> x(n);
		for (ll i = 0; i < n; i++)
			cin >> x[i];
		ll l = 0;
		for (ll i = l; i < n; i++)
			if (x[i] == '0') {
				if (i - l < k) {
					swap(x[i], x[l]);
					k += (l - i);
					l++;
				} 
				else {
					swap(x[i], x[i - k]);
					break;
				}
			}
		for (auto c : x)
			cout << c;
		cout << endl;
	}

	return 0;
}