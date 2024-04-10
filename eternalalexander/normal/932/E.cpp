#include <bits/stdc++.h>

using ll = long long;

const int mod = 1e9+7;
int S2[5005][5005],n,k,fac[5005],ifac[5005],ans;

int binom(int n,int m) { return (ll) fac[n] * ifac[m] % mod * ifac[n - m] % mod; }
int qpow(int a,int b) {
	if (b == 0) return 1;
	ll d = qpow(a,b>>1); d = d * d % mod;
	if (b & 1) d = d * a % mod;
	return d;
}

int main() {
	scanf("%d%d",&n,&k);
	fac[0] = ifac[0] = ifac[1] = 1;
	for (int i = 1; i <= k; ++ i) fac[i] = (ll) fac[i-1] * i % mod;
	for (int i = 2; i <= k; ++ i) ifac[i] = (ll) (mod - mod / i) * ifac[mod % i] % mod;
	for (int i = 1; i <= k; ++ i) ifac[i] = (ll) ifac[i-1] * ifac[i] % mod;
	S2[0][0] = 1;
	for (int i = 1; i <= k; ++ i) 
	for (int j = 1; j <= i; ++ j) 
		S2[i][j] = (S2[i-1][j-1] + (ll) j * S2[i-1][j] % mod) % mod;
	int coef = 1, N = n;
	for (int j = 0; j <= k && j <= n; ++ j) {
		if (j > 0) {
			coef = (ll) coef * N % mod;
			N --;
		} 
		ans = (ans + (ll) S2[k][j] * coef % mod * qpow(2,n-j) % mod) % mod;
	}
	printf("%d",ans);
	return 0;
}