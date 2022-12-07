#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 2e5 + 5 ; 
int n, a[N], K ;  
signed main()
{
	int T = gi() ; 
	while( T-- ) {
		n = gi(), K = gi() ;
		if( K & 1 ) K = 1 ;
		else K = 2 ;  
		rep( i, 1, n ) a[i] = gi() ; 
		rep( k, 1, K ) {
			int d = a[1] ;
			rep( i, 2, n ) d = max( d, a[i] ) ;
			rep( i, 1, n ) a[i] = d - a[i] ;
		}
		rep( i, 1, n ) printf("%lld ", a[i] ) ; puts("") ; 
		rep( i, 1, n ) a[i] = 0 ; 
	}
	return 0 ;
}