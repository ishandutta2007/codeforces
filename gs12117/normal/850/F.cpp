#include<cstdio>
int n;
int a[100100];
const int mod = 1000000007;
long long int m;
long long int dp[100100];
long long int sdp[100100];
long long int mpow(long long int x, long long int y) {
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
long long int minv(long long int x) {
	return mpow(x%mod, mod - 2);
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	m = 0;
	for (int i = 0; i < n; i++) {
		m += a[i];
	}
	m %= mod;
	for (int i = 1; i < 100010; i++) {
		dp[i] = dp[i - 1] * (i - 1) % mod*(m + mod - i) % mod;
		dp[i] += (m*(m + mod - 1));
		dp[i] %= mod;
		dp[i] *= minv((i + 1)*(m + mod - i) % mod);
		dp[i] %= mod;
	}
	sdp[1] = (m - 1)*(m - 1) % mod;
	for (int i = 1; i < 100010; i++) {
		sdp[i + 1] = sdp[i] + mod - dp[i];
		sdp[i + 1] %= mod;
	}
	long long int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += sdp[a[i]] * a[i] % mod;
		ans %= mod;
	}
	ans *= minv(m);
	ans %= mod;
	printf("%lld", ans);
	return 0;
}