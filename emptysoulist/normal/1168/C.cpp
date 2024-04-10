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
const int N = 3e5 + 5 ; 
int n, q, a[N], g[20], f[N][20] ; 
signed main()
{
	n = gi(), q = gi() ; 
	rep( i, 1, n ) a[i] = gi() ; 
	rep( i, 0, 19 ) g[i] = n + 1 ;
	memset( f, 63, sizeof(f) ) ; 
	for(re int i = n; i >= 1; -- i) {
		rep( j, 0, 19 ) if( (1 << j) & a[i] ) f[i][j] = i ;
		rep( j, 0, 19 ) if( (1 << j) & a[i] ) 
			rep( k, 0, 19 ) f[i][k] = min( f[i][k], f[g[j]][k] ) ; 
		rep( j, 0, 19 ) if( (1 << j) & a[i] ) g[j] = i ; 
	}
	while( q-- ) {
		int x = gi(), y = gi() ; 
		int flag = 0 ; 
		rep( j, 0, 19 ) if( (1 << j) & a[y] ) 
		flag |= (f[x][j] <= y) ;
		(flag) ? puts("Shi") : puts("Fou") ; 
	}
	return 0 ;
}