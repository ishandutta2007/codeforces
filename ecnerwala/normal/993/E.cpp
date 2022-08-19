#include<bits/stdc++.h>
using namespace std;

template<typename T> void bitReversalPermute(T *a, int n) {
	assert((n & (n-1)) == 0);
	int i = 0;
	for (int j = 1; j < n-1; j++) {
		for (int k = n/2; k > (i ^= k); k /= 2);
		if (j < i) swap(a[i], a[j]);
	}
}

typedef long long ll;

ll mod(ll x, ll m) {
	ll r = x % m;
	return r < 0 ? r + m : r;
}

ll minv(ll x, ll m) {
	return x == 1 ? 1 : mod(minv(m % x, m) * (m - m / x), m);
}

struct IntFFT {
	int n, m, root, rootinv, ninv;
	IntFFT(int nn, int mm, int r) {
		n = nn;
		m = mm;
		root = r;
		rootinv = (int) minv(root, m);
		ninv = (int) minv(n, m);
		assert(((ll) root * rootinv % m) == 1);
		assert(((ll) n * ninv % m) == 1);
	}

	void operator() (int *a, bool invert) const {
		int cr = invert ? root : rootinv;
		for (int h = n/2; h; cr = (ll) cr * cr % m, h /= 2) {
			for (int i = 0, w = 1; i < h; i++, w = (ll) w * cr % m) {
				for (int j = i; j < n; j += 2 * h) {
					int k = j + h;
					int x = (int) mod(a[j]-a[k], m);
					a[j] = (a[j] + a[k]) % m;
					a[k] = (ll) w * x % m;
				}
			}
		}
		bitReversalPermute(a, n);
		if (invert) {
			for (int i = 0; i < n; i++) a[i] = (ll) a[i] * ninv % m;
		}
	}

	void mul(int *a, int *b) const {
		operator() (a, false);
		operator() (b, false);
		for (int i = 0; i < n; i++) {
			a[i] = (ll) a[i] * b[i] % m;
		}
		operator() (a, true);
	}
};

const int L = (1 << 19);
IntFFT ifft1(L, 998244353, 1847);
IntFFT ifft2(L, 995622913, 801);

int a[L];
int b[L];
int c[L];
int d[L];

int N;
int main() {
	ios_base::sync_with_stdio(false);
	int X; scanf("%d %d", &N, &X);
	int cnt = 0;
	a[0] += 1;
	b[N] += 1;
	c[0] += 1;
	d[N] += 1;
	for (int i = 0; i < N; i++) {
		int v; scanf("%d", &v);
		cnt += (v < X);
		a[cnt] += 1;
		b[N - cnt] += 1;
		c[cnt] += 1;
		d[N - cnt] += 1;
	}

	ifft1.mul(a, b);
	ifft2.mul(c, d);

	ll mi = minv(ifft1.m % ifft2.m, ifft2.m);
	for (int i = 0; i <= N; i++) {
		int x = a[N+i], y = c[N+i];
		//cerr << x << ' ' << y << '\n';
		ll f = mi * mod(y-x, ifft2.m) % ifft2.m;
		ll res = x + ifft1.m * f;
		if (i == 0) {
			res -= N+1;
			assert(res % 2 == 0);
			res /= 2;
		}
		cout << res << ' ';
	}
	cout << '\n';


	return 0;
}