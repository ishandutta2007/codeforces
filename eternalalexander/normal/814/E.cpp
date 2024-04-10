#include <bits/stdc++.h>

using ll = long long;

const int mod = 1e9 + 7;

const int inv2 = (mod + 1) / 2, inv3 = (mod + 1) / 3;

int dp[55][55][55][2],coef[55][55][55][55],d[55],n,ipw2[55],ipw3[55],fac[55],C[55][55];

int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; ++ i) scanf("%d",&d[i]);
	if (d[1] == 3) dp[1][0][0][1] = 1;
	else dp[1][0][1][0] = 1;
	coef[0][0][0][0] = 1;
	for (int i = 0; i <= n; ++ i) {
		C[i][0] = 1;
		for (int j = 1; j <= i; ++ j) C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
	} 
	for (int i = 0; i <= n; ++ i)
	for (int j = 0; j <= n; ++ j) {
		for (int k = 0; k <= n; ++ k)
		for (int l = 0; l <= n; ++ l) {
			if (k > 0) {
				coef[k][l][i][j] = (
				//NONE 2 1 22 11 21
				(ll) (k - 1 >= 0 && i - 1 >= 0 ? coef[k-1][l][i-1][j] : 0) + 
				(ll) (k - 2 >= 0 && j - 1 >= 0 ? coef[k-2][l+1][i][j-1] : 0) * (k - 1) % mod +
				(ll) (k - 1 >= 0 && l - 1 >= 0 && j - 1 >= 0 ? 
					coef[k-1][l-1][i][j-1] : 0) * l % mod +
					
				(ll) (k - 3 >= 0 ? coef[k-3][l+2][i][j] : 0) * C[k-1][2] % mod +
				(ll) (k - 1 >= 0 && l - 2 >= 0 ? coef[k-1][l-2][i][j] : 0) * C[l][2] % mod +
				(ll) (k - 2 >= 0 ? coef[k-2][l][i][j] : 0) * (k-1) % mod * l % mod ) % mod;
			} else if (l > 0) {
				coef[k][l][i][j] = (
					(ll) (l - 1 >= 0 && j - 1 >= 0 ? coef[k][l-1][i][j-1] : 0) +
					(ll) (l - 2 >= 0 ? coef[k][l-2][i][j] : 0) * (l - 1) % mod ) % mod;
			}
		}
	} 
	ipw2[0] = ipw3[0] = fac[0] = 1;
	for (int i = 1; i <= n; ++ i) { 
		ipw2[i] = (ll) ipw2[i-1] * inv2 % mod;
		ipw3[i] = (ll) ipw3[i-1] * inv3 % mod;
		fac[i] = (ll) fac[i-1] * i % mod;
	}
//	printf("%d\n",coef[2][2][0][0]);
	for (int i = 1; i <= n; ++ i) {
		for (int j = 0; j <= i; ++ j)
		for (int k = 0; k + j <= i; ++ k)
		for (int l = 0; l <= 1; ++ l) {
			if (!dp[i][j][k][l]) continue;
		//	printf("<%d> <%d %d %d> = %d\n",i,j,k,l,dp[i][j][k][l]);
			int sumd = j + k * 2 + l * 3;
			if (sumd == 0) continue;
			int p = i + sumd;
			if (p > n) continue;
			int way = (ll) fac[sumd] * ipw2[k] % mod * ipw3[l] % mod * ipw2[l] % mod;
			int c1 = 0, c2 = 0;
			for (int q = i + 1; q <= p; ++ q) {
				if (d[q] == 2) c1 ++;
				else c2 ++;
			} 
		//	printf("c2 = %d, c1 = %d\n",c2,c1);
			for (int w1 = 0; w1 <= n; ++ w1) 
			for (int w2 = 0; w2 <= n; ++ w2) {
				//printf("%d * %d * %d -> dp[%d][%d][%d][%d]\n",dp[i][j][k][l],way,
			//	coef[c2][c1][w2][w1],p,w1,w2,0);
				dp[p][w1][w2][0] = (dp[p][w1][w2][0] + 
				(ll) dp[i][j][k][l] * way % mod * coef[c2][c1][w2][w1] % mod) % mod;
			}
		}
	} printf("%d",dp[n][0][0][0]);
	return 0;
}