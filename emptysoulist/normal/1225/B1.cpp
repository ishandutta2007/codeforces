#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define inf 123456789
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 1e6 + 5 ; 
const int M = 2e5 + 5 ; 
int T, n, m, D, w[N], a[M], Ans, num ; 
void Add( int x ) {
	++ w[x] ; 
	if( w[x] == 1 ) ++ Ans ; 
}
void Del( int x ) {
	-- w[x] ; 
	if( w[x] == 0 ) -- Ans ; 
}
signed main()
{
	T = gi() ; 
	while( T-- ) {
		n = gi(), D = gi(), m = gi(), num = inf ; 
		rep( i, 1, n ) a[i] = gi() ; 
		rep( i, 1, m ) Add( a[i] ) ; num = min( num, Ans ) ;
		rep( i, m + 1, n ) {
			Add( a[i] ), Del( a[i - m] ) ;
			num = min( num, Ans ) ;
		}
		for( re int i = n - m + 1; i <= n; ++ i ) Del( a[i] ) ;
		printf("%d\n", num ) ;
	}
	return 0 ;
}