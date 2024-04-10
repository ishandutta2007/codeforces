#include <bits/stdc++.h>
#define maxn 1000005
#define ll long long
const int mod = 998244353;
int n,fac[maxn],ifac[maxn],a[maxn],ans;

int binom(int n,int m) {
	if (n<0||m<0||n<m)return 0;
	return (ll)fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}

int main() {
	scanf("%d",&n);
	fac[0] = ifac[0] = ifac[1] = 1;
	for (int i = 1; i <= 3*n; ++ i) fac[i] = (ll) fac[i-1] * i % mod;
	for (int i = 2; i <= 3*n; ++ i) ifac[i] = (ll) (mod - mod / i) * ifac[mod % i] % mod;
	for (int i = 1; i <= 3*n; ++ i) ifac[i] = (ll) ifac[i-1] * ifac[i] % mod;
	
	for (int i = 1; i <= 2*n; ++ i) scanf("%d",&a[i]);
	std::sort(a+1,a+2*n+1);
	for (int i = 1; i <= 2*n; ++ i) {
		int sum = binom(2*n-1,n);
		if (i <= n) ans = (ans - (ll) a[i] % mod * sum % mod + mod) % mod;
		else ans = (ans + (ll) a[i] % mod * sum % mod) % mod;
	} printf("%d",ans*2%mod);
	return 0;
}