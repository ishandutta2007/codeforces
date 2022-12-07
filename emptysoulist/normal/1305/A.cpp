#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 100 + 5 ; 
int T, n, A[N], B[N] ; 
signed main()
{
	T = gi() ;
	while( T-- ) {
		n = gi() ;
		rep( i, 1, n ) A[i] = gi() ;
		sort( A + 1, A + n + 1 ) ;
		rep( i, 1, n ) B[i] = gi() ;
		sort( B + 1, B + n + 1 ) ;
		rep( i, 1, n ) printf("%d ", A[i] ) ; puts("") ;
		rep( i, 1, n ) printf("%d ", B[i] ) ; puts("") ; 
	}
	return 0 ;
}