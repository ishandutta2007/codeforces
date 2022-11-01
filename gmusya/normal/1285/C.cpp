#include <iostream>
#include <vector>

#define ll long long

ll gcd(ll a, ll b) {
	if (b % a == 0)
		return a;
	return gcd(b % a, a);
}
using namespace std;

int main() {
	ll n;
	cin >> n;
	vector <ll> div;
	for (ll i = 1; i * i <= n; i++)
		if (n % i == 0)
			div.push_back(i);
	for (ll i = div.size() - 1; i >= 0; i--) {
		ll a = div[i];
		ll b = n / div[i];
		if (gcd(a, b) == 1) {
			cout << a << " " << b;
			return 0;
		}
	}
	return 0;
}