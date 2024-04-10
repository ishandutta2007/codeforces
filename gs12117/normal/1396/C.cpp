#include<cstdio>
int n;
long long int ra, rb, rc;
long long int d;
long long int a[1001000];
long long int cost[1001000][2];
long long int dp[1001000][2][2];
void setmin(long long int &lval, long long int rval) {
	if (lval > rval)lval = rval;
}
int main() {
	scanf("%d%lld%lld%lld%lld", &n, &ra, &rb, &rc, &d);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		cost[i][0] = ra * a[i] + rc;
		cost[i][1] = ra * (a[i] + 2);
		if (cost[i][1] > rb + ra)cost[i][1] = rb + ra;
		cost[i][0] += d;
		cost[i][1] += 2 * d;
		if (cost[i][1] > cost[i][0] + d)cost[i][1] = cost[i][0] + d;
		if (cost[i][0] > cost[i][1] + d)cost[i][0] = cost[i][1] + d;
	}
	for (int i = 0; i <= n; i++) {
		dp[i][0][0] = 1e18;
		dp[i][0][1] = 1e18;
		dp[i][1][0] = 1e18;
		dp[i][1][1] = 1e18;
	}
	dp[0][0][0] = 0;
	dp[0][0][1] = d;
	for (int i = 0; i < n; i++) {
		setmin(dp[i + 1][0][0], dp[i][0][0] + cost[i][0]);
		setmin(dp[i + 1][0][0], dp[i][0][1] + cost[i][1]);
		setmin(dp[i + 1][0][1], dp[i][0][0] + cost[i][1]);
		setmin(dp[i + 1][0][1], dp[i + 1][0][0] + d);
		setmin(dp[i + 1][0][0], dp[i + 1][0][1] + d);
		setmin(dp[i + 1][1][1], dp[i + 1][0][0]);
		setmin(dp[i + 1][1][1], dp[i + 1][0][1]);
		setmin(dp[i + 1][1][0], dp[i + 1][0][0]);
		setmin(dp[i + 1][1][0], dp[i][1][1] + cost[i][0]);
		setmin(dp[i + 1][1][1], dp[i][1][1] + cost[i][1]);
		setmin(dp[i + 1][1][1], dp[i + 1][1][0] + d);
		setmin(dp[i + 1][1][0], dp[i + 1][1][1] + d);
	}
	printf("%lld", dp[n][1][0] - d);
	return 0;
}