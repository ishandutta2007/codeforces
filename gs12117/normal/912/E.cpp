#include<cstdio>
int n;
long long int m;
int a[17];
long long int dp[17][501000];
int dpl[17];
const long long int cmax = 1000000000000000010LL;
const int smax = 500000;
long long int cdp(int x, long long int d) {
	int res = -1;
	for (int i = 20; i >= 0; i--) {
		res += 1 << i;
		if (res >= dpl[x] || dp[x][res] > d)res -= 1 << i;
	}
	res++;
	return res;
}
long long int calc(int x, long long int d) {
	if (d == 0)return 0;
	if (x == 0)return 1;
	if (d <= dp[x][dpl[x] - 1])return cdp(x, d);
	return calc(x - 1, d) + calc(x, d / a[x - 1]);
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%lld", &m);
	dpl[0] = 1;
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		int kl = 0;
		int kr = 0;
		for (int j = 0; j < smax; j++) {
			if (kr == j || (kl != dpl[i] && dp[i + 1][kr] > dp[i][kl] / a[i])) {
				dp[i + 1][j] = dp[i][kl];
				kl++;
			}
			else {
				if (dp[i + 1][kr] > cmax / a[i])break;
				dp[i + 1][j] = dp[i + 1][kr] * a[i];
				kr++;
			}
			dpl[i + 1]++;
		}
	}
	long long int ans = 0;
	for (int i = 59; i >= 0; i--) {
		ans += 1LL << i;
		if (calc(n, ans) >= m)ans -= 1LL << i;
	}
	ans++;
	printf("%lld", ans);
	return 0;
}