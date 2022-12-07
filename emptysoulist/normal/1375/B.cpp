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
const int N = 300 + 5 ; 
int T, n, m, a[N][N], b[N][N] ; 
signed main()
{
	T = gi() ; 
	while( T-- ) {
		n = gi(), m = gi() ; 
		rep( i, 1, n ) rep( j, 1, m ) a[i][j] = 4 ; 
		rep( i, 1, n ) a[i][1] = a[i][m] = 3 ; 
		rep( i, 1, m ) a[1][i] = a[n][i] = 3 ;
		a[1][1] = a[n][1] = a[n][m] = a[1][m] = 2 ; 
		rep( i, 1, n ) rep( j, 1, m ) b[i][j] = gi() ;
		int flag = 0 ; 
		rep( i, 1, n ) rep( j, 1, m ) {
			if( b[i][j] > a[i][j] ) flag = 1 ; 
		}
		if( flag ) puts("NO") ; 
		else {
			puts("YES"); 
			rep( i, 1, n ) {
				rep( j, 1, m ) printf("%d ", a[i][j] ) ;
				puts("") ; 
			}
		}
	}
	return 0 ;
}