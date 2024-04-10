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
const int N = 1e4 + 5 ; 
int n, k, a[N] ; 
signed main() {
	int T = gi() ; 
	while( T -- ) {
		n = gi(), k = gi() ; 
		rep( i, 1, n ) a[i] = gi() ; 
		int d = 1, flag = 0 ;
		if( k == 1 ) {
			flag = a[1] ; 
			rep( i, 2, n ) if( a[i] != a[1] ) flag = -1 ;
			if( flag == -1 ) puts("-1") ;
			else puts("1") ;
			continue ; 
		}
		rep( i, 2, n ) if(a[i - 1] != a[i] && a[i]) ++ d ;
		if( d <= k ) { puts("1") ; continue ; }
		else {
			d -= k ; int tmp = 1 ;
			while( d > 0 ) 
				d -= k, ++ d, tmp ++ ;
			printf("%lld\n", tmp ) ;
			continue;
		}
	}
	return 0;
}