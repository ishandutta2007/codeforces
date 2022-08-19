#include <iostream>
using namespace std;

typedef long long ll;

int main() {
	ll x, k; cin >> x >> k;
	if (x == 0) {
		cout << 0 << '\n';
		return 0;
	}
	x *= 2;
	x--;
	const ll MOD = ll(1e9) + 7;
	x %= MOD;
	ll a = 2;
	while (k) {
		if (k & 1) x *= a, x %= MOD;
		a *= a, a %= MOD;
		k >>= 1;
	}
	x ++;
	x %= MOD;
	cout << x << '\n';
	return 0;
}