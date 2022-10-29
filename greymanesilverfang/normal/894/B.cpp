#include <cstdio>
#define ll long long
const ll INF = 1e9 + 7;

ll power(ll base, ll pow) {
	ll res; for (res = 1; pow > 0; pow >>= 1) {
		if (pow & 1) (res *= base) %= INF;
		(base *= base) %= INF;
	}
	return res;
}

int main() {
	ll n, m, k; scanf("%lld%lld%lld", &n, &m, &k);
	if (n + m & 1 && !~k) printf("0"); else
	printf("%lld", power(power(2, --n), --m));
}