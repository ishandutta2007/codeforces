#include<cstdio>
#include<algorithm>
int n, m, p;
int a[1010];
int b[2010];
long long int dp[1010][2010];
int dist(int x, int y) {
	if (x < y)return y - x;
	return x - y;
}
int main() {
	scanf("%d%d%d", &n, &m, &p);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &b[i]);
	}
	std::sort(a, a + n);
	std::sort(b, b + m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dp[i][j] = 1e10;
		}
	}
	for (int j = 0; j < m; j++) {
		dp[0][j] = dist(a[0], b[j]) + dist(b[j], p);
		if (j > 0 && dp[0][j - 1] < dp[0][j])dp[0][j] = dp[0][j - 1];
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			dp[i][j] = dist(a[i], b[j]) + dist(b[j], p);
			if (dp[i - 1][j - 1] > dp[i][j])dp[i][j] = dp[i - 1][j - 1];
			if (dp[i][j - 1] < dp[i][j])dp[i][j] = dp[i][j - 1];
		}
	}
	printf("%I64d\n", dp[n - 1][m - 1]);
	return 0;
}