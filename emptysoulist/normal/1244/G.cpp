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
const int N = 1e6 + 5 ; 
int n, m, p[N], R, Ans ;
void print() {
	printf("%lld\n", Ans ) ;
	rep( i, 1, n ) printf("%lld ", i ) ;
	puts("") ;
	rep( i, 1, n ) printf("%lld ", p[i] ) ;
	exit(0) ;
}
signed main()
{
	n = gi(), m = gi() ;  
	rep( i, 1, n ) p[i] = i ;
	if( 1ll * n * ( n + 1 ) / 2 > m ) {
		printf("-1") ; exit(0) ;
	}
	R = n, Ans = 1ll * n * ( n + 1 ) / 2 ; 
	rep( l, 1, R ) {
		Ans += ( R - l ) ;
		if( Ans > m ) {
			Ans -= ( R - l ) ;
			swap( p[l], p[l + m - Ans] ), Ans += ( m - Ans ) ;
			print() ; 
		} 
		swap( p[l], p[R] ), -- R ; 
	}
	print() ; 
	return 0 ;
}