#include <bits/stdc++.h>

double ans[105];
int f[105][105][10005],n,a[105],b[105],sum,lim;
const int inf = 1e9;

int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d%d",&a[i],&b[i]);
		lim += a[i];
		sum += b[i];
	}
	for (int i = 0; i <= n; ++ i)
	for (int j = 0; j <= n; ++ j)
	for (int k = 0; k <= lim; ++ k)
		f[i][j][k] = -inf;
	f[0][0][0] = 0;
	for (int i = 1; i <= n; ++ i)
	for (int j = 0; j <= n; ++ j)
	for (int k = 0; k <= lim; ++ k) {
		f[i][j][k] = f[i-1][j][k];
		if (j >= 1 && k >= a[i]) 
			f[i][j][k] = std::max(f[i][j][k],f[i-1][j-1][k-a[i]] + b[i]);
	}
	for (int i = 0; i <= n; ++ i)
	for (int k = 0; k <= lim; ++ k) {
		ans[i] = std::max(ans[i],
		std::min((double)k,f[n][i][k] + (double) (sum - f[n][i][k]) / 2.0));
	}
	for (int i = 1; i <= n; ++ i) printf("%.10f ",ans[i]);
	return 0;
}