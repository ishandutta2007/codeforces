#include<cstdio>
int n, m;
int a[100100];
int sarr[100100];
int sl, sr;
long long int cans;
long long int dp[22][100100];
long long int srange(int l, int r) {
	while (sl < l) {
		sarr[a[sl]]--;
		cans -= sarr[a[sl]];
		sl++;
	}
	while (sl > l) {
		sl--;
		cans += sarr[a[sl]];
		sarr[a[sl]]++;
	}
	while (sr < r) {
		cans += sarr[a[sr]];
		sarr[a[sr]]++;
		sr++;
	}
	while (sr > r) {
		sr--;
		sarr[a[sr]]--;
		cans -= sarr[a[sr]];
	}
	return cans;
}
void dnc(int x, int l, int r, int cl, int cr) {
	if (l > r)return;
	int mid = (l + r) / 2;
	int cm = mid;
	dp[x + 1][mid] = dp[x][mid];
	for (int i = cl; i <= cr&&i < mid; i++) {
		long long int tmp = srange(i, mid) + dp[x][i];
		if (dp[x + 1][mid] > tmp) {
			dp[x + 1][mid] = tmp;
			cm = i;
		}
	}
	dnc(x, l, mid - 1, cl, cm);
	dnc(x, mid + 1, r, cm, cr);
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		dp[0][i] = 1e18;
	}
	for (int i = 0; i < m; i++) {
		dnc(i, 0, n, 0, n);
	}
	printf("%lld", dp[m][n]);
}