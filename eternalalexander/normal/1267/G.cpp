#include <bits/stdc++.h>

const int maxn = 105;
using ldb = long double;

int n,c[maxn];
ldb x,C[maxn][maxn],ans,f[maxn][maxn*maxn];

int main() {
	std::cin >> n >> x;
	for (int i = 1; i <= n; ++ i) std::cin >> c[i];
	for (int i = 0; i <= n; ++ i) {
		C[i][0] = 1;
		for (int j = 1; j <= i; ++ j) C[i][j] = C[i-1][j] + C[i-1][j-1];
	}
	std::sort(c + 1, c + n + 1);
	f[0][0] = 1;
	int lim = 0;
	for (int i = 1; i <= n; ++ i) {
		lim += c[i];
		for (int j = i; j >= 1; -- j)
		for (int k = lim; k >= c[i]; -- k) {
			f[j][k] += f[j-1][k-c[i]];
		}
	}
	for (int i = n; i >= 1; -- i) {
		ldb v1 = ( ( n / (ldb) i ) + 1 ) * ( (ldb) x / 2.0 );
		ldb c = 0, s = 0;
		for (int j = 1; j <= lim; ++ j) {
			if (j < v1 * i) s += (f[i][j] / i) * j ;
			else c += f[i][j];
		} ans += (c * v1 + s) / C[n][i];
	} printf("%.10Lf",ans);
	return 0;
}