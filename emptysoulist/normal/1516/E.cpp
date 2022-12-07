#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( int i = (t); i >= (s); -- i )
#define mp make_pair
#define pi pair<int, int>
#define pb push_back
#define vi vector<int>
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int P = 1e9 + 7 ; 
const int N = 205 ; 
int fpow(int x, int k) {
	int ans = 1, base = x ;
	while(k) {
		if(k & 1) ans = 1ll * ans * base % P ;
		base = 1ll * base * base % P, k >>= 1 ;
	} return ans ;
}
int n, K, f[N], g[N], F[N][N], inv[N], fac[N], ans[N] ; 
int Fp[N] ; 
void polydiv(int *a) { rep( i, 1, K ) a[i - 1] = i * a[i] % P ; a[K] = 0 ; }
void polyln(int *a) {
	rep( j, 0, K ) Fp[j] = 0 ; 
	rep( j, 1, K ) {
		int de = 0 ;
		for(int i = 1; i < j; ++ i) de = (de + (Fp[i] * a[j - i]) % P * i) % P ;
		Fp[j] = (a[j] - de * inv[j] % P + P) % P ; 
	} rep( j, 0, K ) a[j] = Fp[j] ; 
}
void polyexp(int *a) {
	rep( j, 0, K ) Fp[j] = 0 ; polydiv(a), Fp[0] = 1 ; 
	rep( j, 1, K ) {
		for(int k = 0; k < j; ++ k) Fp[j] = (Fp[j] + (Fp[k] * a[j - k - 1])) % P ; 
		Fp[j] = Fp[j] * inv[j] % P ; 
	} rep( j, 0, K ) a[j] = Fp[j] ; 
}
signed main()
{
	n = gi() ; int m = gi() ; fac[0] = 1 ; 
	K = min(n, m) ; 
	rep( i, 1, K ) fac[i] = fac[i - 1] * (n - i + 1) % P ; 
	rep( i, 1, K ) inv[i] = fpow(i, P - 2) ; 
	rep( i, 0, K ) f[i] = fpow(i, P - 2) ; 
	rep( i, 0, K ) g[i] = fpow(i + 1, P - 2) ; 
	int L = n - K ; 
	polyln(g) ; 
	rep( i, 0, K ) g[i] = g[i] * L % P ; 
	polyexp(g) ; 
	//g * f^i[x^{K - i}]
	F[0][0] = 1 ; 
	rep( i, 1, K ) {
		rep( j, 0, K ) F[i][j] = (F[i][j - 1] + F[i - 1][j]) % P ; 
		rep( j, 0, K ) F[i][j] = F[i][j] * i % P ; 
		drep( j, 1, K ) F[i][j] = F[i][j - 1] * inv[j] % P ; 
		F[i][0] = 0 ; 
	}
	for(int i = 0; i <= K; ++ i) {
		int u = K - i ; 
		rep( j, 0, K ) ans[i] = (ans[i] + g[j] * F[u][K - j]) % P ; 
		ans[i] = ans[i] * fac[i] % P ; 
	}
	for(int i = 2; i <= m; ++ i) ans[i] += ans[i - 2], ans[i] %= P ; 
	rep( i, 1, m ) printf("%lld ", ans[i]) ; 
	return 0 ;
}