#include <bits/stdc++.h>

using ll = long long;

const int N = 1000;
const int L = 50;
const int mod = 1e9 + 7;

int n,k,fac[N*2+7],C[N*2+7][N*2+7],f[N+5][L+5][N+5];

int dec(int x) { return x >= mod ? x - mod : x; }

int main() {
	fac[0] = 1;
	for (int i = 1; i <= N; ++ i) fac[i] = (ll) fac[i-1] * i % mod;
	for (int i = 0; i <= N * 2; ++ i) {
		C[i][0] = 1;
		for (int j = 1; j <= i; ++ j) C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
	}
	f[1][0][0] = 1;
	for (int i = 1; i <= N; ++ i) 
	for (int j = 0; j <= L; ++ j) 
	for (int k = 0; k <= N; ++ k) {
		f[i+1][j][k] = dec(f[i+1][j][k] + f[i][j][k]);
		if (k + i <= N) f[i+1][j+1][k+i] = dec(f[i+1][j+1][k+i] + f[i][j][k]);
	}
	int t;scanf("%d",&t);while(t-->0) {
		int ans = 0;
		scanf("%d%d",&n,&k);
		for (int i = k * (k + 1) / 2; i <= n; ++ i) {
		//	printf("<%d> %d %d %d\n",k,f[n+1][k][i],C[n-i+k][k],fac[k]);
			ans = (ans + (ll) f[n+1][k][i] * C[n - i + k][k] % mod * fac[k] % mod) % mod;
		}
		printf("%d\n",ans);
	}
	return 0;
}