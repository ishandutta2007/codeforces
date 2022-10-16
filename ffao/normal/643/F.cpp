#include <bits/stdc++.h>
using namespace std;


long long mod = (1LL<<32);

template <typename T>
T extGcd(T a, T b, T& x, T& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	else {
		int g = extGcd(b, a % b, y, x);
		y -= a / b * x;
		return g;
	}
}

template <typename T>
T modInv(T a, T m) {
	T x, y;
	extGcd(a, m, x, y);
	return ( (x % m) + m) % m;
}

unsigned C[150];
int n,p,q;
void solve() {
	scanf("%d %d %d", &n, &p, &q);
	p = min(p,n-1);

	for (int pp = 0; pp <= p; pp++) {
		C[pp]=1;
		int tw = 0;
		for (int i = n; i > n-pp; i--) {
			int ti = i;
			while (ti % 2 == 0) {
				ti /= 2;
				tw++;
			}
			C[pp] = (C[pp] * 1ll * ti) % mod;
		}
		for (int i = 1; i <= pp; i++ ) {
			int ti = i;
			while (ti % 2 == 0) {
				ti /= 2;
				tw--;
			}
			C[pp] = (C[pp] * 1ll * modInv((long long)ti, (long long)mod)) % mod;
		}
		for (int i = 0; i < tw; i++) C[pp] = (C[pp] * 2) % mod;
	}

	unsigned ans = 0;
	
	for (int i = 1; i <= q; i++) {
		unsigned curr = 0;

		int cb = n-1;
		int ti = i;
		if (ti % 2 == 0) cb = 32;
		while (ti % 2 == 0) {
			cb--;
			ti /= 2;
		}
		cb = min(cb,p);

		// sum x=0..p q^x * C(n,x)
		unsigned pot = 1;
		for (int pp = 0; pp <= cb; pp++) {
			curr = (curr + pot * C[pp]) % mod;
			pot = pot * i;
		}

		ans ^= (i * curr);
	}

	printf("%u\n", ans);

	
}

int main() {
    solve();
}