#include <cstdio>

using namespace std;

typedef long long ll;

const int P = 998244353;
const int N = 1000010;

int n;
int fac[N];

int mpow(int a, int k);
int comb(int n, int m);
int inv(int a) { return mpow(a, P - 2); }

int main() {
	scanf("%d", &n);
	fac[0] = 1;
	for (int i = 1; i <= n; ++i)
		fac[i] = fac[i - 1] * (ll)i % P;
	int ans = (mpow(3, n * (ll)n % (P - 1)) + P - mpow((mpow(3, n) + P - 3) % P, n)) % P * 2;
	if (ans >= P)
		ans -= P;
	int cent = 0;
	for (int a = 1; a <= n; ++a) {
		cent = (cent + comb(n, a) * (ll)((a & 1) ? P - 1 : 1) % P * ((ll)mpow(mpow(3, n - a) - 1, n) + P - mpow(3, (n - a) * (ll)n % (P - 1))) % P) % P;
	}
	ans = (ans - 3LL * cent) % P;
	if (ans < 0)
		ans += P;
	printf("%d\n", ans);
	return 0;
}

int mpow(int a, int k) {
	int ret = 1;
	while (k) {
		if (k & 1)
			ret = ret * (ll)a % P;
		a = a * (ll)a % P;
		k >>= 1;
	}
	return ret;
}

int comb(int n, int m) {
	return fac[n] * (ll)inv(fac[m]) % P * inv(fac[n - m]) % P;
}