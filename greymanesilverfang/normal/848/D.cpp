#include <iostream>
const long long MOD = 1e9 + 7, MN = 50;
int x; long long y, f[MN+1][MN+1] = {1}, g[MN+1][MN+1] = {1}, tmp[MN+1][MN+1] = {}, inv[MN+1] = {1,1};
int main() {
	for (int i = 2; i <= MN; ++i)
		inv[i] = (MOD*MOD-MOD/i*inv[MOD%i])%MOD;
	for (int i = 1; i <= MN; ++i)
		for (int j = 1; j <= MN; ++j) {
			for (int k = 1; k <= i; ++k) {
				(f[i][j] += g[k-1][j-1]*g[i-k][j-1]) %= MOD;
				for (int l = j; l <= MN; ++l)
					(f[i][j] += g[k-1][j-1]*g[i-k][l]+g[k-1][l]*g[i-k][j-1]) %= MOD;
			}
			for (x = 1, y = f[i][j]; i*x<=MN && j*x<=MN; ++x, (y*=(f[i][j]+x-1)*inv[x]%MOD)%=MOD)
				for (int k = i*x; k <= MN; ++k)
					for (int l = j*x; l <= MN; ++l)
						(tmp[k][l] += g[k-i*x][l-j*x]*y) %= MOD;
			for (int k = i; k <= MN; ++k)
				for (int l = j; l <= MN; ++l) {
					(g[k][l] += tmp[k][l]) %= MOD;
					tmp[k][l] = 0;
				}
		}
	int n, m; std::cin >> n >> m; std::cout << g[n][m-1]; return 0;
}