#include <cstdio>
#define ll long long
using namespace std;
ll q = 2, mod = 1e9 + 7, inv = 5e8 + 4;

struct matrix { 
	ll a, b, c, d; 
	matrix(ll _a, ll _b, ll _c, ll _d) {
		a = _a; b = _b; c = _c; d = _d;
	}
} res(0, 1, 0, 0), base(1, 2, 1, 0);

matrix operator * (matrix a, matrix b) {
	matrix c(0, 0, 0, 0);
	c.a = (a.a * b.a + a.b * b.c) % mod;
	c.b = (a.a * b.b + a.b * b.d) % mod;
	c.c = (a.c * b.a + a.d * b.c) % mod;
	c.d = (a.c * b.b + a.d * b.d) % mod;
	return c;
}

matrix pow(matrix base, ll p) {
	matrix res(1, 0, 0, 1);
	for (; p; p >>= 1) {
		if (p & 1)
			res = res * base;
		base = base * base;
	}
	return res;
}

ll pow(ll base, ll p) {
	ll res = 1;
	for (; p; p >>= 1) {
		if (p & 1)
			(res *= base) %= mod;
		(base *= base) %= mod;
	}
	return res;
}

int main() {
	int k; scanf("%d", &k);
	while (k--) {
		ll x; scanf("%lld", &x);
		base = pow(base, x);
		q = pow(q, x);
	}
	printf("%lld/%lld", (res * base).b * inv % mod, q * inv % mod);
}