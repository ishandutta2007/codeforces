#include <bits/stdc++.h>

const int lim = 3e5;
const int maxn = 32768 + 177;
const int mod = 998244353;

using ll = long long;

int fac[lim + 17],ifac[lim + 17],n,a[maxn],b[maxn],ans,f[maxn],g[maxn],h[maxn];

int rev[maxn<<2];

int qpow(int a,int b) {
	if (b == 0) return 1;
	ll d = qpow(a,b>>1); d = d * d % mod;
	if (b&1) d = d * a % mod;
	return d;
}

void NTT( int *a, int lim, int flag ) {
	for (int i = 1; i < lim; ++ i) rev[i] = (rev[i>>1]>>1) | (i&1) * (lim>>1);
	for (int i = 0; i < lim; ++ i) if (i < rev[i]) std::swap(a[i], a[rev[i]]);
	for (int i = 1; i < lim; i <<= 1) {
		int wn = qpow(3,(mod-1)/(i<<1));
		if (flag == -1) wn = qpow(wn, mod - 2);
		for (int j = 0; j < lim; j += (i<<1)) {
			for (int k = 0, w = 1; k < i; w=(ll)w*wn%mod,++k) {
				int a1 = a[j+k], a2 = (ll) w * a[j+k+i] % mod;
				a[j+k] = (a1 + a2) % mod; a[j+k+i] = (a1 - a2 + mod) % mod;
			}
		}
	} if (flag == -1) 
		for (int i = 0,inv=qpow(lim,mod-2); i < lim; ++i) a[i] = (ll) a[i] * inv % mod;
}


int main() {
	scanf("%d",&n);
	int curL = 1;
	f[1] = 1;
	fac[0] = ifac[0] = ifac[1] = 1;
	for (int i = 1; i <= lim; ++ i) fac[i] = (ll) fac[i-1] * i % mod;
	for (int i = 2; i <= lim; ++ i) ifac[i] = (ll) (mod - mod / i ) * ifac[mod % i] % mod;
	for (int i = 1; i <= lim; ++ i) ifac[i] = (ll) ifac[i - 1] * ifac[i] % mod;
	auto binom = [&](int n,int m) {
		if (n < m || n < 0 || m < 0) return 0ll;
		return (ll) fac[n] * ifac[m] % mod * ifac[n - m] % mod;
	};
	for (int i = 1; i <= n; ++ i) {
		scanf("%d%d",&a[i],&b[i]);
		int nxtL = curL + a[i] - b[i];
		int N = curL + a[i];
		std::memset(g,0,sizeof(g));
		int L = 2 * N - curL - nxtL;
		std::memset(h,0,sizeof(h));
		for (int i = 1; i <= curL + nxtL; ++ i) 
		if (N - i + 1 >= 0 && (L - (N - i + 1)) >= 0)
			h[i] = (ll) ifac[N - i + 1] * ifac[L - (N - i + 1)] % mod;
		std::reverse(f + 1, f + curL + 1);
		int lm = 1; while (lm <= nxtL + curL + curL) lm <<= 1;
		NTT(f,lm,1); NTT(h,lm,1);
		for (int i = 0; i < lm; ++ i) g[i] = (ll) f[i] * h[i] % mod;
		NTT(g,lm,-1);
		std::memset(f,0,sizeof(f));
		for (int i = 1; i <= nxtL; ++ i) f[i] = (ll) g[curL + 1 + i] * fac[L] % mod;
		curL = nxtL;
	}
	for (int i = 1; i <= curL; ++ i) ans = (ans + f[i]) % mod;
	printf("%d",ans);
	return 0;
}