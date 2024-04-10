#include <bits/stdc++.h>

using ll = long long;
const int maxn = 1e6 + 222;
const int mod = 1e9 + 7;
int n,k,ans,fac[maxn],ifac[maxn];

int binom(int n,int m) { return (ll) fac[n] * ifac[m] % mod * ifac[n - m] % mod; }

int main() {
	scanf("%d%d",&n,&k);
	fac[0] = ifac[0] = ifac[1] = 1;
	for (int i = 1; i <= n; ++ i) fac[i] = (ll) fac[i - 1] * i % mod;
	for (int i = 2; i <= n; ++ i) ifac[i] = (ll) ( mod - mod / i ) * ifac[mod % i] % mod;
	for (int i = 1; i <= n; ++ i) ifac[i] = (ll) ifac[i - 1] * ifac[i] % mod;
	for (int i = 0; i <= n && i <= k; ++ i) ans = (ans + binom(n,i)) % mod;
	printf("%d",ans); 
	return 0;
}