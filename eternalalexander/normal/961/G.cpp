#include <bits/stdc++.h>

using ll = long long;
const int mod = 1e9+7;
const int maxn = 1 << 20;

int n,k,w[maxn],sum,fac[maxn],ifac[maxn];

int qpow(int a,int b) {
	int res = 1;
  	while (b > 0) {
		if (b & 1) res = (ll) res * a % mod;
		a = (ll) a * a % mod;
		b >>= 1;
	}
  	return res;
} 

int inv(int x) { 
	x %= mod;
	return x == 1 ? 1 : (ll) (mod - mod / x) * inv(mod % x) % mod; 
}

int binom(int n,int m) {
	if (n < m || n < 0 || m < 0) return 0;
	return (ll) fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

int main() {
	scanf("%d%d",&n,&k);
	fac[0] = ifac[0] = ifac[1] = 1;
	for (int i = 1; i <= n; ++ i) fac[i] = (ll) fac[i-1] * i % mod;
	for (int i = 2; i <= n ; ++ i) ifac[i] = (ll) (mod - mod / i) * ifac[mod % i] % mod;
	for (int i = 1; i <= n ; ++ i) ifac[i] = (ll) ifac[i-1] * ifac[i] % mod;
	for (int i = 1; i <= n; ++ i) { scanf("%d",&w[i]); sum = (sum + w[i]) % mod ; } 
	if (k == 1) { printf("%lld",(ll) n * sum % mod); return 0; }
	k --;
	int ans = 0, N = n - 1;
	auto det = [](int x) { return x & 1 ? mod - 1 : 1; };
	
	for (int i = 0; i <= k; ++ i) {
		//int q = inv(i);
		int coef = 0, latt = 0;
		//((ll) n * q + 1) % mod * qpow(q + 1, N) % mod;
		if (i == 0) {
			coef = (ll) binom(k,i) % mod * det(k - i) % mod;
			for (int j = 0; j <= N; ++ j) latt = (latt + (ll) binom(N,j) * (j+1) % mod * qpow(i,N - j) % mod) % mod;
		}
		else {
			coef = (ll) qpow(i,N) * binom(k,i) % mod * det(k - i) % mod;
			int q = inv(i);
			latt = (qpow(q+1,N) + (ll) qpow(q+1,N-1) * N % mod * q % mod) % mod;
		}
		ans = (ans + (ll) coef * latt % mod) % mod;
	} 
	/*
	for (int j = 0; j <= N; ++ j) {
		int coef = (ll) binom(N,j) * (j+1) % mod;
		int latt = 0;
		for (int i = 0; i <= k; ++ i) latt = (latt + (ll) binom(k,i) * qpow(i,N-j) % mod * det(k-i) % mod) % mod;
		ans = (ans + (ll) coef * latt % mod) % mod;
	}*/
	printf("%lld",(ll) ans * ifac[k] % mod * sum % mod);
	return 0;
}