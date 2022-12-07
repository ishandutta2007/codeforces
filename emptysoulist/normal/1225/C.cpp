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
const int N = 65 ;
int n, p, ru[N] ; 
int solve( int x ) {
	if( x < 0 ) return 0 ; 
	int nw = 0 ; 
	while( x ) {
		if( x & 1 ) ++ nw ; 
		x >>= 1 ; 
	} return nw ; 
}
signed main()
{
	n = gi(), p = gi(), ru[0] = 1 ; 
	rep( i, 1, 42 ) ru[i] = ru[i - 1] * 2 ; 
	rep( i, 1, 42 ) ru[i] = ru[i] + p ;
	int Ans = 0 ; 
	while( ++ Ans ) {
		int x = n - p * Ans ; 
		if( x <= 0 ) { puts("-1") ; exit(0) ; }
		int tot = 0, u = x ;
		while( x ) {
			if( x & 1 ) ++ tot ; 
			x >>= 1 ; 
		}
		if( tot <= Ans && u >= Ans ) {
			printf("%I64d\n", Ans ) ;
			exit(0) ; 
		}
	} 
	return 0 ;
}