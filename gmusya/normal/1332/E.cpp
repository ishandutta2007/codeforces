#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

const ll MOD = 998244353;

ll binpow(ll val, ll pow) {
	if (pow == 0) return 1;
	if (pow % 2) return val * binpow(val, pow - 1) % MOD;
	ll x = binpow(val, pow / 2);
	return x * x % MOD;
}

int main() {
	ll n, m, L, R;
	cin >> n >> m >> L >> R;
	ll H = R - L + 1;
	if (n * m % 2) {
		cout << binpow(H, n * m);
		return 0;
	}
	cout << (binpow(H, n * m) + H % 2) * (MOD + 1) / 2 % MOD;
	return 0;
}