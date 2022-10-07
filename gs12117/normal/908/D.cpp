#include<cstdio>
int n, pa, pb;
const int mod = 1000000007;
long long int pd,pinv;
long long int dp[1010][1010];
int chk[1010][1010];
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
long long int calc(int an, int abn) {
	if (an + abn >= n)return (an + abn + pd) % mod;
	if (chk[an][abn] == 1)return dp[an][abn];
	chk[an][abn] = 1;
	dp[an][abn] = pa*pinv%mod*calc(an + 1, abn) % mod;
	dp[an][abn] += pb*pinv%mod*calc(an, abn + an) % mod;
	dp[an][abn] %= mod;
	return dp[an][abn];
}
int main() {
	scanf("%d%d%d", &n, &pa, &pb);
	pinv = mpow(pa + pb, mod - 2);
	pd = mpow(pb, mod - 2)*pa%mod;
	printf("%lld\n", calc(1, 0));
	return 0;
}