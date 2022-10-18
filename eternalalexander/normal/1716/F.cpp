#include <bits/stdc++.h>

using ll = long long;
const int mod = 998244353;
const int maxn = 4e3 + 12;
int S[2005][2005],pw1[2005],pw2[2005];
int qpow(int a,int b) {
	if (b == 0) return 1;
	ll d = qpow(a,b>>1); d = d * d % mod;
	if (b & 1) d = d * a % mod;
	return d;
}

int main() {
	S[0][0] = 1;
	for (int i = 1; i <= 2000; ++ i) {
		for (int j = 1; j <= i; ++ j) S[i][j] = (S[i-1][j-1] + (ll) j * S[i-1][j] % mod) % mod;
	} 
	int t;scanf("%d",&t);while (t--) {
		int n,m,k,ans = 0;
		scanf("%d%d%d",&n,&m,&k);
		int b = m / 2; //even
		int a = m - b; //odd
		int ib = qpow(m,mod-2);
		pw1[0] = 1; pw2[0] = qpow(m,n);
		for (int i = 1; i <= k; ++ i) {
			pw1[i] = (ll) pw1[i-1] * a % mod;
			pw2[i] = (ll) pw2[i-1] * ib % mod;
		}
		int cur = 1;
		for (int i = 1; i <= k && i <= n; ++ i) {
			cur = (ll) cur * (n - i + 1) % mod;
			ans = (ans + (ll) cur * S[k][i] % mod * pw1[i] % mod * pw2[i] % mod) % mod;
		} printf("%d\n",ans);
	}
	return 0;
}