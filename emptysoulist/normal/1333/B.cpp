#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 2e5 + 5 ; 
int T, n, m, a[N], b[N], f[N][5] ; 
signed main()
{
	T = gi() ;
	while( T-- ) {
		n = gi() ;
		rep( i, 1, n ) {
			a[i] = gi() ; 
			rep( j, 1, 3 ) f[i][j] = ( f[i - 1][j] | f[i][j] ) ;
			f[i + 1][a[i] + 2] = 1 ;   
		}
		rep( i, 1, n ) b[i] = gi() ; 
		int flag = 1 ; 
		for( re int i = n; i >= 1; -- i ) {
			int d = b[i] - a[i] ;
			if( d > 0 && ( !f[i][3] ) ) flag = 0 ;
			if( d < 0 && ( !f[i][1] ) ) flag = 0 ;
		}
		if( flag ) puts("YES") ;
		else puts("NO") ;  
		rep( i, 1, n ) rep( j, 1, 3 ) f[i][j] = 0 ; 
		rep( j, 1, 3 ) f[n + 1][j] = 0 ;
	}
	return 0 ;
}