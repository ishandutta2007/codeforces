#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

long long S[5010][5010], tmp[5010];
long long sum[5010];
long long fac[5010], inv[5010];

long long power(int a, int b) {
	if (!b) return 1;
	long long tmp = power(a, b >> 1);
	return b & 1 ? tmp * tmp % mod * a % mod : tmp * tmp % mod;
}

long long C(int n, int k) {
	return fac[n] * inv[k] % mod * inv[n - k] % mod;
}

int main() {
	fac[0] = 1, inv[0] = 1;
	for (int i = 1; i <= 5005; i++) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = power(fac[i], mod - 2);
	}
	int n; scanf("%d", &n);
	S[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = i; j >= 1; j--) {
			S[i][j] = (S[i - 1][j - 1] + S[i - 1][j] * j) % mod;
		}
	}
	for (int i = 1; i <= n; i++) {
		reverse(S[i] + 1, S[i] + 1 + i);
		for (int j = 0; j < i; j++) {
			S[i][j] = S[i][j + 1] * fac[i - j] % mod;
		}
	}
	for (int j = 0; j < n; j++) {
		for (int i = n; i >= 0; i--) {
			S[i][j] = S[i][j] * fac[n] % mod * inv[i] % mod;
			S[i][j] = (S[i][j] + S[i + 1][j]) % mod;
		}
	}
	long long mul = 1;
	for (int i = n; i >= 1; i--) {
		sum[i] = (sum[i + 1] + mul) % mod;
		mul = mul * i % mod;
	}
	for (int i = 0; i < n; i++) {
		long long ans = 0;
		for (int j = i; j < n; j++) {
			ans = (ans + C(j, i) * S[j + 1][j] % mod * (j - i & 1 ? -1 : 1) + mod) % mod;
		}
		printf("%I64d ", ans);
	}
	printf("\n");
	return 0;
}