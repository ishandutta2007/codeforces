#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define LL unsigned long long
#define int unsigned long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 1e5 + 5 ; 
const int M = 12 ; 
const LL iv = 14757395258967641293ull ;
int n ; 
struct akf {
	LL m[M] ; 
	void init() { rep( i, 0, 9 ) m[i] = 0 ; }
} A[N], Nx[M] ; 
akf Move( akf x, int l ) {
	akf ans ; ans.init() ; 
	rep(i, 0, 9) ans.m[(i + l) % 10] = x.m[i] ;
	return ans ; 
}
akf operator * ( LL c, akf x ) {
	akf ans ; ans.init() ; 
	rep(i, 0, 9) ans.m[i] = x.m[i] * c ;
	return ans ; 
}
akf operator * ( akf x, akf y ) {
	akf ans ; ans.init() ; 
	rep(i, 0, 9) rep(j, 0, 9) ans.m[(i + j) % 10] += x.m[i] * y.m[j] ; 
	return ans ; 
} 
akf operator + ( akf x, akf y ) {
	akf ans ; ans.init() ; 
	rep( i, 0, 9 ) ans.m[i] = x.m[i] + y.m[i] ; 
	return ans ; 
}
akf operator - ( akf x, akf y ) {
	akf ans ; ans.init() ; 
	rep( i, 0, 9 ) ans.m[i] = x.m[i] - y.m[i] ; 
	return ans ; 
}
void FWT() {
	for( re int k = 1; k < n; k *= 10 ) for( re int i = 0; i < n; i += (k * 10) ) 
	for( re int j = i; j < i + k; ++ j ) {
		rep( l, 0, 9 ) Nx[l].init() ; 
		rep( l, 0, 9 ) rep( o, 0, 9 )
		Nx[l] = Nx[l] + Move(A[j + o * k], o * l % 10) ; 
		rep( l, 0, 9 ) A[j + l * k] = Nx[l] ; 
	}
}
void IFWT() {
	for( re int k = 1; k < n; k *= 10 ) for( re int i = 0; i < n; i += (k * 10) ) 
	for( re int j = i; j < i + k; ++ j ) {
		rep( l, 0, 9 ) Nx[l].init() ; 
		rep( l, 0, 9 ) rep( o, 0, 9 )
		Nx[l] = Nx[l] + iv * Move(A[j + o * k], 10 - o * l % 10) ; 
		rep( l, 0, 9 ) A[j + l * k] = Nx[l] ; 
	}
}
akf fpow(akf x, LL k) {
	akf ans, base = x ; ans.init(), ans.m[0] = 1 ; 
	while(k) {
		if(k & 1) ans = ans * base ;
		base = base * base, k >>= 1 ; 
	} return ans ; 
}
signed main()
{
	n = gi() ; int x, m = n ; 
	rep( i, 1, n ) x = gi(), ++ A[x].m[0] ; 
	n = N - 5 ; 
	FWT() ; 
	for(re int i = 0; i < n; ++ i) A[i] = fpow( A[i], m ) ;
	IFWT() ; int p = ( 1ll << 58 ) ; 
	for( re int i = 0; i < m; ++ i ) {
		A[i].m[5] -= A[i].m[3] ;
	    A[i].m[0] -= (A[i].m[2] + A[i].m[5]) ; 
	    printf("%llu\n", (long long)((A[i].m[0] / 32ll) % p ) ) ; 
	}
	return 0 ;
}