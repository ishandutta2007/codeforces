#include<stdio.h>
int n, m;
int a[4010][4010];
int sa[4010][4010];
int dp[810][4010];
void calc(int d, int al, int ar, int bl, int br) {
	if (al > ar) {
		return;
	}
	int mid = (al + ar) / 2;
	int sd = br;
	if (mid < sd)sd = mid;
	int r = -1;
	dp[d + 1][mid] = 1234567890;
	for (int i = bl; i <= sd; i++) {
		if (dp[d + 1][mid] > dp[d][i] + sa[i][mid]) {
			dp[d + 1][mid] = dp[d][i] + sa[i][mid];
			r = i;
		}
	}
	calc(d, al, mid - 1, bl, r);
	calc(d, mid + 1, ar, r, br);
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int r = getchar();
			while (r<'0' || r>'9')r = getchar();
			a[i][j] = r - '0';
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; i + j <= n; j++) {
			int l = j;
			int r = i + j;
			sa[l][r] = sa[l + 1][r] + sa[l][r - 1] - sa[l + 1][r - 1] + a[l][r - 1];
		}
	}
	for (int i = 0; i <= n; i++) {
		dp[1][i] = sa[0][i];
	}
	for (int i = 1; i < m; i++) {
		calc(i, 0, n, 0, n);
	}
	printf("%d", dp[m][n]);
	return 0;
}