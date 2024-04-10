#include <bits/stdc++.h>

using ll = long long;
const int mod = 998244353;
const int g = 3;
const int maxn = (1 << 21) + 222;

int n,m,a[maxn],b[maxn],rev[maxn],A[maxn],B[maxn],s1[maxn],s2[maxn],f[maxn],w[maxn],p[maxn],ans;

int qpow(int a,int b) {
	if (b == 0) return 1;
	ll d = qpow(a,b>>1); d = d * d % mod;
	if (b & 1) d = d * a % mod;
	return d;
}

void FFT(int *a,int lim,int flag) {
	for (int i = 1; i < lim; ++ i) rev[i] = (rev[i >> 1] >> 1) | ( (i & 1) * (lim >> 1) );
	for (int i = 0; i < lim; ++ i) if (i < rev[i]) std::swap(a[i],a[rev[i]]);
	for (int i = 1; i < lim; i <<= 1) {
		int wn = qpow(g,(mod - 1) / (i << 1));
		if (flag == -1) wn = qpow(wn,mod - 2);
		for (int j = 0; j < lim; j += (i << 1))
		for (int k = 0,w = 1; k < i; k ++,w=(ll)w*wn%mod ) {
			int a0 = a[j+k], a1 = (ll) w * a[j+k+i] % mod;
			a[j+k] = (a0 + a1) % mod; a[j+k+i] = (a0 - a1 + mod) % mod;
		}
	} if (flag == -1) {
		for (int i = 0,inv = qpow(lim,mod - 2); i < lim; ++ i) 
			a[i] = (ll) a[i] * inv % mod;
	}
}

void solve(int l,int r) {
	if (l == r) return ;
	int mid = (l + r) >> 1;
	solve(l,mid); solve(mid+1,r);
//	printf("work [%d %d]\n",l,r);
	int len = r - l + 10;
	int lim = 1; while (lim <= len) lim <<= 1;
	for (int i = 0; i < lim; ++ i) a[i] = b[i] = 0;
	for (int i = l; i <= mid; ++ i) a[i - l] = (i <= n ? A[i + n] : 0);
	for (int i = mid + 1; i <= r; ++ i) b[i - mid] = (i >= 0 ? B[i] : 0);
	FFT(a,lim,1); FFT(b,lim,1);
	for (int i = 0; i < lim; ++ i) a[i] = (ll) a[i] * b[i] % mod;
	FFT(a,lim,-1);
	for (int i = 0; i <= len; i ++) { 
		int cur = i + l + mid;
		if (cur % 2) continue;
		cur /= 2;
		if (cur < 1 || cur > n) continue;
		f[cur] = (f[cur] + a[i]) % mod;
	}
} 

int main() {
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; ++ i) scanf("%d",&w[i]);
	for (int i = 1; i <= m; ++ i) {
		scanf("%d",&p[i]);
		s1[p[i]] = s2[p[i]] = 1;
	} for (int i = 1; i <= 2 * n; ++ i) { 
		s1[i] = s1[i - 1] + s1[i];
		A[i + n] = qpow(2,s1[i]);
	} for (int i = -n; i <= 0; ++ i) A[i + n] = 1;
	for (int i = n; i >= 1; i --) {
		s2[i] = s2[i + 1] + s2[i];
		B[i] = qpow(2,s2[i]);
	} for (int i = n + 1; i <= 2 * n; ++ i) B[i] = 1;
//	for (int i = -n; i <= n; ++ i) printf("%d ",A[i + n]); puts("<A");
	//for (int i = 1; i <= 2 * n; ++ i) printf("%d ",B[i]); puts("<B");
	solve(-n,2 * n);
	for (int i = 1; i <= n; ++ i) {
		int c = std::min(2 * n - i,i - (-n));
	//	printf("%d > %d %d %d\n",i,f[i],c,f[i] - c);
		f[i] = (f[i] - c + mod) % mod;
		ans = (ans + (ll) w[i] * f[i] % mod) % mod;
		
	} //printf("ans = %d\n",ans);
	int divi = (qpow(2,m) - 1 + mod) % mod;
	divi = qpow(divi,mod - 2) % mod; 
	printf("%lld",(ll)ans * divi % mod);
	return 0;
}