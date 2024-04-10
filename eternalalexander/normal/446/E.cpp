//
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 //pragma is magic

//C++17(64)

#include <bits/stdc++.h>

using ll = long long;


int n,m,a[1 << 25],g[1 << 25],s; ll t;
const int mod = 1051131;
const int inv2 = (mod + 1) / 2;


inline int dec(int x) { return x >= mod ? x - mod : x; }
int lowbit(int x) { return x & -x; }

int qpow(int a,ll b) {
	if (b == 0) return 1;
	ll d = qpow(a,b >> 1);
	d = d * d % mod;
	if (b & 1) d = d * a % mod;
	return d;
}

void DFT(int *a,int n){
	for(int i=1;i<n;i<<=1)
	for(int len=i<<1,j=0;j<n;j+=len)
	for(int k=0;k<i;++k){
		int A0=a[j+k],A1=a[j+k+i];
		a[j+k]=dec(A0+A1);a[j+k+i]=dec(mod+A0-A1);
	}
}

void IDFT(int *a,int n){
	for(int i=1;i<n;i<<=1)
	for(int len=i<<1,j=0;j<n;j+=len)
	for(int k=0;k<i;++k){
		int A0=a[j+k],A1=a[j+k+i];
		a[j+k]=(ll) dec(A0+A1) * inv2 % mod; a[j+k+i]=(ll) dec(mod+A0-A1) * inv2 % mod;
	}
}

int main() {
	scanf("%d%lld%d",&m,&t,&s);
	n = 1 << m;
	for (int i = 0; i < s; ++ i) scanf("%d",&a[i]);
	for (int i = s; i < n; ++ i) a[i]=((ll) 101*a[i-s]+10007) % 1051131;
	DFT(a,n);
	for (int i = 0; i < n; ++ i) g[i] = lowbit(i) % mod; g[0] = 1;
///	for (int i = 0; i < n; ++ i) printf("%d ",g[i]); puts("");
	DFT(g,n);
	int last = 0;
	for (int i = 0; i < n; ++ i) {
		if ((i == 0) || (g[i] != g[i-1])) last = qpow(g[i],t);
//		printf("%d * %d\n",a[i],last);
		a[i] = (ll) a[i] * last % mod;
	} IDFT(a,n);
	int ans = 0;
	for (int i = 0; i < n; ++ i) { ans ^= a[i]; }
	printf("%d",ans);
	return 0;
}