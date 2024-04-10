#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define mp make_pair
#define pi pair<int, int>
#define pb push_back
#define int long long
#define vi vector<int>
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 4e5 + 5 ; 
const int P = 998244353 ; 
const int G = 3 ; 
const int Gi = (P + 1) / 3 ; 
int fpow(int x, int k) {
	int ans = 1, base = x ;
	while(k) {
		if(k & 1) ans = 1ll * ans * base % P ;
		base = 1ll * base * base % P, k >>= 1 ;
	} return ans ;
}
int n, m, limit, L, Inv, iv[N], fac[N], inv[N] ; 
int A[N], B[N], f[N], h[N], R[N] ; 
void init(int x) {
	limit = 1, L = 0 ; while(limit < x) limit <<= 1, ++ L ; 
	rep(i, 0, limit - 1) R[i] = ((R[i >> 1] >> 1) | ((i & 1) << (L - 1))) ; 
	Inv = fpow(limit, P - 2) ; 
}
void Init(int x) {
	fac[0] = inv[0] = 1 ; 
	rep( i, 1, x ) fac[i] = fac[i - 1] * i % P ; 
	inv[x] = fpow(fac[x], P - 2) ; 
	drep( i, 1, x ) inv[i - 1] = inv[i] * i % P ; 
	rep( i, 1, x ) iv[i] = fac[i - 1] * inv[i] % P ; 
}
void NTT(int *a, int type) {
	for(int i = 0; i < limit; ++ i) if(R[i] > i) swap(a[i], a[R[i]]) ; 
	for(int k = 1; k < limit; k <<= 1) {
		int d = fpow((type) ? G : Gi, (P - 1) / (k << 1)) ; 
		for(int i = 0; i < limit; i += (k << 1)) 
		for(int j = i, g = 1; j < i + k; ++ j, g = g * d % P) {
			int nx = a[j], ny = a[j + k] * g % P ; 
			a[j] = (nx + ny) % P, a[j + k] = (nx - ny + P) % P ; 
		} 
	} if(!type) for(int i = 0; i < limit; ++ i) a[i] = a[i] * Inv % P ; 
}
signed main() 
{
	n = gi(), m = gi() ; 
	rep( i, 0, n ) f[i] = gi() ; 
	Init(n + 5) ; 
	rep( i, 0, n ) A[i] = f[i] * fac[i] % P ; 
	rep( i, 0, n ) B[i] = inv[n - i] ; 
	init(n + n + 5), NTT(A, 1), NTT(B, 1) ; 
	rep( i, 0, limit ) A[i] = A[i] * B[i] % P ; 
	NTT(A, 0) ; 
	rep( i, 0, n ) h[i] = A[i + n] * inv[i] % P ; 
	rep( i, 0, n ) h[i] = h[i] * fpow(iv[i + 1], m) % P ; 
	rep( i, 0, limit ) B[i] = A[i] = 0 ; 
	rep( i, 0, n ) B[i] = inv[n - i] * fpow(P - 1, n - i) % P ; 
	rep( i, 0, n ) A[i] = h[i] * fac[i] % P ; 
	NTT(A, 1), NTT(B, 1) ; 
	rep( i, 0, limit ) A[i] = A[i] * B[i] % P ; 
	NTT(A, 0) ; 
	rep( i, 0, n ) f[i] = A[i + n] * inv[i] % P ; 
	rep( i, 0, n ) printf("%lld ", f[i] ) ; 
	return 0 ; 
}