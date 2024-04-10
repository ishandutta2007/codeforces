#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

ll gcd(ll a, ll b) {
	if (a % b) return gcd(b, a % b);
	return b;
}

int main() {
	ll n, m, k;
	cin >> n >> m >> k;
	ll newn = n, newm = m;
	ll g = gcd(newn, k);
	newn /= g, k /= g;
	g = gcd(newm, k);
	newm /= g, k /= g;
	if (k > 2) {
		cout << "NO";
		return 0;
	}
	cout << "YES" << endl;
	if (k == 1) {
		if (newn * 2 <= n) newn *= 2;
		else newm *= 2;
	}
	cout << "0 0" << endl;
	cout << newn << " 0" << endl;
	cout << "0 " << newm << endl;
	return 0;
}