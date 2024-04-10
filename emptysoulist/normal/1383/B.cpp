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
const int N = 1e5 + 5 ; 
int n, a[N] ;  
signed main()
{
	int T = gi() ; 
	while( T-- ) {
		n = gi() ; 
		rep( i, 1, n ) a[i] = gi() ; 
		int flag = 0 ; 
		drep( k, 0, 30 ) {
			int f = 0 ; 
			rep( i, 1, n ) if( (1ll << k) & a[i] ) ++ f ; 
			if( f % 2 == 0 ) continue ; 
			if( f % 4 == 1 ) { flag = 1 ; break ; }
			if( f % 4 == 3 ) { 
				if( (n - f) % 2 == 0 ) flag = 2 ; 
				else flag = 1 ; 
				break ; 
			}
		}
		if( flag == 0 ) puts("DRAW") ;
		if( flag == 1 ) puts("WIN") ;
		if( flag == 2 ) puts("LOSE") ;
		
	} 
	return 0 ;
}