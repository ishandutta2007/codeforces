#include<stdio.h>
int n;
int a[1001000];
const int mod = 1000000007;
int max_d = 1000000;
int pten[10];
long long int ptwo[1001000];
long long int en[1001000];
long long int dp[1001000];
long long int esum[1001000];
int main() {
	pten[0] = 1;
	for (int i = 0; i < 8; i++) {
		pten[i + 1] = pten[i] * 10;
	}
	ptwo[0] = 1;
	for (int i = 0; i < max_d; i++) {
		ptwo[i + 1] = ptwo[i] * 2 % mod;
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		dp[a[i]] *= 2;
		dp[a[i]] += ptwo[en[a[i]]] * a[i] % mod * a[i] % mod;
		dp[a[i]] += esum[a[i]] * a[i] % mod*ptwo[en[a[i]]] % mod;
		dp[a[i]] %= mod;
		en[a[i]]++;
		esum[a[i]] += a[i];
		esum[a[i]] %= mod;
	}
	for (int i = 0; i < 6; i++) {
		int p = pten[i];
		for (int j = max_d; j >= 0; j--) {
			if (j / p % 10 == 0)continue;
			if (en[j] == 0)continue;
			int k = j - p;
			dp[k] = dp[j] * ptwo[en[k]] % mod + dp[k] * ptwo[en[j]] % mod + esum[j] * esum[k] % mod*ptwo[en[j] + en[k] - 1] % mod;
			dp[k] %= mod;
			esum[k] += esum[j];
			esum[k] %= mod;
			en[k] += en[j];
		}
	}
	for (int i = 0; i < 6; i++) {
		int p = pten[i];
		for (int j = 0; j < max_d; j++) {
			if (j / p % 10 == 0)continue;
			int k = j - p;
			dp[k] -= dp[j];
			dp[k] += mod;
			dp[k] %= mod;
		}
	}
	long long int ans = 0;
	for (int i = 0; i < max_d; i++) {
		ans ^= i*dp[i];
	}
	printf("%I64d", ans);
	return 0;
}