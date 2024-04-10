#include<cstdio>
int n;
long long int p;
long long int divp[2010][2010];
long long int psq[2010];
long long int qsq[2010];
long long int dp[2010];
long long int sp[2010];
const int mod = 998244353;
long long int mpow(int x, int y) {
	if (y == 0)return 1;
	long long int r = mpow(x, y / 2);
	r *= r;
	r %= mod;
	if (y % 2 == 1) {
		r *= x;
		r %= mod;
	}
	return r;
}
long long int minv(int x) {
	return mpow(x, mod - 2);
}
int main() {
	scanf("%d", &n);
	int pa, pb;
	scanf("%d%d", &pa, &pb);
	p = pa*minv(pb) % mod;
	psq[0] = 1;
	qsq[0] = 1;
	for (int i = 0; i <= n; i++) {
		psq[i + 1] = psq[i] * p%mod;
		qsq[i + 1] = qsq[i] * (mod + 1 - p) % mod;
	}
	divp[1][1] = 1;
	divp[1][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			divp[i + 1][j] += divp[i][j] * psq[j] % mod;
			divp[i + 1][j] %= mod;
			divp[i + 1][j + 1] += divp[i][j] * qsq[i - j] % mod;
			divp[i + 1][j + 1] %= mod;
		}
	}
	dp[1] = 0;
	sp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = i*(i - 1) / 2;
		for (int j = 1; j < i; j++) {
			sp[i] += sp[j] * divp[i][j] % mod;
			sp[i] %= mod;
			dp[i] += sp[j] * divp[i][j] % mod*(dp[i - j] + dp[j] + mod - ((i - j)*(i - j - 1) / 2)) % mod;
			dp[i] %= mod;
		}
		dp[i] *= minv(sp[i]);
		dp[i] %= mod;
		sp[i] = mod + 1 - sp[i];
		sp[i] %= mod;
	}
	printf("%lld\n", dp[n]);
	return 0;
}