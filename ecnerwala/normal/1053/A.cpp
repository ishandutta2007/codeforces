#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ll N, M, K; cin >> N >> M >> K;
	if ((2 * N * M) % K != 0) {
		cout << "NO" << '\n';
		return 0;
	}
	ll k2 = __gcd(K, 2ll);
	K /= k2;
	ll kn = __gcd(K, N);
	K /= kn;
	ll km = __gcd(K, M);
	K /= km;
	assert(K == 1);
	ll x = N / kn;
	ll y = M / km;
	if (k2 == 1) {
		assert(kn >= 2 || km >= 2);
		if (kn >= 2) {
			x *= 2;
		} else {
			y *= 2;
		}
		assert(x <= N && y <= M);
	} else {
		assert(k2 == 2);
	}
	cout << "YES" << '\n';
	cout << 0 << ' ' << 0 << '\n';
	cout << x << ' ' << 0 << '\n';
	cout << 0 << ' ' << y << '\n';

	return 0;
}