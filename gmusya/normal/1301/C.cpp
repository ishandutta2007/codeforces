#include <iostream>
#include <vector>

#define ll long long
#define endl '\n'

using namespace std;

int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n, m;
		cin >> n >> m;
		ll g;
		if (2 * m >= n)
			g = n - m;
		else
			g = m + 1;
		ll x = 0;
		if (n == m) 
			x = 0;
		else {
			ll z = n - m;
			ll a = z / g;
			ll b = z % g;
			//cout << z << " " << g << " " << a << " " << b << endl;
			x += (g - b) * ((a * (a - 1)) / 2 + a);
			a++;
			x += b * ((a * (a - 1)) / 2 + a);
		}
		cout << n * (n - 1) / 2 + n - x << endl;
	}
	return 0;
}