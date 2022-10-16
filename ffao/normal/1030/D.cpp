#include <cstdio>
#include <cstring>
#include <iostream>
#define ll long long
using namespace std;
 
ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a % b);
}
ll n, m, k;
int main() {
	cin >> n >> m >> k;
	if (2 * n * m % k) {
		cout << "NO" << endl;
		return 0;
	}
	ll x = gcd(n * 2, k);
	ll x1, y2;
	cout << "YES" << endl;
	if (x == 1) {
		x1 = n;
		y2 = 2 * m / k;
	} else {
		x1 = n * 2 / x;
		y2 = m * x / k;
	}
	cout << 0 << ' ' << 0 << endl;
	cout << x1 << ' ' << 0 << endl;
	cout << 0 << ' ' << y2 << endl;
	return 0;
}