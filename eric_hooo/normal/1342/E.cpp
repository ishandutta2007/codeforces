#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

long long fac[200010], inv[200010];

long long power(long long a, int b) {
	if (!b) return 1;
	long long tmp = power(a, b >> 1);
	return b & 1 ? tmp * tmp % mod * a % mod : tmp * tmp % mod;
}

long long C(int n, int k) {
	return fac[n] * inv[k] % mod * inv[n - k] % mod; 
} 

int main () {
	int n; long long tmp; scanf("%d%I64d", &n, &tmp);
	if (tmp >= n) {
		printf("0\n");
		return 0;
	}
	int k = n - tmp;
	long long ans = 0;
	fac[0] = inv[0] = 1;
	for (int i = 1; i <= n; i++) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = power(fac[i], mod - 2);
	}
	for (int i = tmp; i <= n; i++) {
		(ans += C(n - tmp, i - tmp) * power(n - i, n) % mod * (i - tmp & 1 ? -1 : 1) + mod) %= mod;
	}
	ans = ans * C(n, tmp) % mod * (tmp ? 2 : 1) % mod;
	printf("%I64d\n", ans);
	return 0;
}