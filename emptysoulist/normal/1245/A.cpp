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
int gcd( int x, int y ) {
	if( x == 0 ) return y ; 
	return gcd( y % x, x ) ;
} 
signed main()
{
	int T = gi(), a, b ; 
	while( T-- ) {
		a = gi(), b = gi() ; 
		if( gcd( a, b ) == 1 ) puts("Finite") ;
		else puts("Infinite") ; 
	}
	return 0 ;
}