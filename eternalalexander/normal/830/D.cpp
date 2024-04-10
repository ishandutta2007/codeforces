#include <bits/stdc++.h>
using ll = long long;
const int mod = 1e9+7;

int C[405][405],f[405][405],n;

int dfs(int n,int m) {
	if (f[n][m] != -1) return f[n][m];
	if (m == 0) return 1; 
	if (n == 1 && m == 1) return 1;
	if (n == 1 && m > 1) return 0;
	f[n][m] = 0;
	// does not involve root
	for (int i = 0; i <= m; ++ i) 
		f[n][m] = (f[n][m] + (ll) dfs(n-1,i) * dfs(n-1,m-i) % mod * C[m][i] % mod) % mod;
//	printf(">%d\n",f[n][m]);
	// root as a single path
	for (int i = 0; i < m; ++ i) 
		f[n][m] = (f[n][m] + (ll) dfs(n-1,i) * dfs(n-1,m-i-1) % mod * C[m-1][i] % mod * m % mod) % mod;
//	printf(">%d\n",f[n][m]);
	// combine root with one single path
	for (int i = 0; i <= m; ++ i) 
		f[n][m] = (f[n][m] + (ll) dfs(n-1,i) * dfs(n-1,m-i) % mod * C[m][i] % mod * 2 % mod * m % mod) % mod;
	//printf(">%d\n",f[n][m]);
	// combine two paths together
	for (int i = 0; i <= m + 1; ++ i) 
		f[n][m] = (f[n][m] + (ll) dfs(n-1,i) * dfs(n-1,m+1-i) % mod * C[m+1][i] % mod * m % mod) % mod;
	return f[n][m];
}


int main() {
	std::memset(f,-1,sizeof(f));
	scanf("%d",&n);
	for (int i = 0; i <= n + 2; ++ i) {
		C[i][0] = 1;
		for (int j = 1; j <= i; ++ j) C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
	}
	printf("%d",dfs(n,1));
	return 0;
}