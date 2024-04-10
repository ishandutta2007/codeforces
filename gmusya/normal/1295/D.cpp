#include <iostream>
#include <vector>

#define ll long long

using namespace std;

ll gcd(ll a, ll b) {
	if (a % b == 0)
		return b;
	return gcd(b, a % b);
}

ll phi(ll n) {
	ll result = n;
	for (ll i = 2; i*i <= n; ++i)
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
	if (n > 1)
		result -= result / n;
	return result;
}

int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll a, b;
		cin >> a >> b;
		cout << phi(b / gcd(a, b)) << endl;
	}
	return 0;
}