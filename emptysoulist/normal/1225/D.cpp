#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 2e5 + 5 ; 
int n, m, A[N], B[N], Ans, Maxn, flag ;
map<int, int> e ; 
int Mul( int x, int y ) {
	if( x * y > Maxn ) flag = 1 ; 
	return x * y ;
}
int fpow( int x, int k ) {
	int ans = 1, base = x ;
	while( k ) {
		if( k & 1 ) ans = Mul( ans, base ) ;
		base = base * base, k >>= 1 ;  
		if( k && base > Maxn ) flag = 1 ; 
	} return ans ; 
}
int Togo( int x ) {
	int pax = 1 ; 
	for( re int i = 2; i <= sqrt(x); ++ i ) {
		if( x % i ) continue ; 
		int now = 0 ;
		while( x % i == 0 ) ++ now, x /= i ;
		pax = Mul( pax, fpow( i, now % m ) ) ;
	} 
	if( x ) pax = ( pax * x ) ;
	return pax ; 
}
int uGo( int x ) {
	int pax = 1 ; 
	for( re int i = 2; i <= sqrt(x); ++ i ) {
		if( x % i ) continue ; 
		int now = 0 ;
		while( x % i == 0 ) ++ now, x /= i ;
		pax = Mul( pax, fpow( i, ( m - now % m ) % m ) ) ;
		if( pax > Maxn ) return 0 ; 
	} if( x ) pax = Mul( pax, fpow( x, m - 1 ) ) ;
	if( pax > Maxn || flag ) return 0 ;
	return pax ;
}
signed main()
{
	n = gi(), m = gi() ;
	rep( i, 1, n ) A[i] = gi(), B[i] = Togo(A[i]), ++ e[B[i]], Maxn = max( Maxn, A[i] ) ; 
	rep( i, 1, n ) {
		flag = 0 ; int u = uGo(B[i]) ;
		if( u != B[i] ) Ans += e[u] ;
		else Ans += ( e[u] - 1 ) ;
	} printf("%I64d\n", Ans / 2 ) ;
	return 0 ;
}