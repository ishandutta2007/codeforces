#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 2e5 + 5 ; 
int T, n, c[N], p[N], d[N], ans ; 
int st[N], top ; 
signed main()
{
	T = gi() ; 
	while( T-- ) {
		n = gi(), ans = n ; 
		rep( i, 1, n ) p[i] = gi() ; 
		rep( i, 1, n ) c[i] = gi() ; 
		for( re int i = 1; i <= n; ++ i ) {
			if( !d[i] ) {
				int u = i, L = 0 ; while( !d[u] ) d[u] = 1, u = p[u], ++ L ;
				ans = min( ans, L ) ; 
			}
		}
		for( re int i = 1; i <= n; ++ i ) {
			if( !d[i] ) continue ; 
			int u = i, flag ; top = 0 ;
			while( d[u] ) st[++ top] = u, d[u] = 0, u = p[u] ; 
			for( re int j = 1; j <= sqrt(top); ++ j ) {
				if( top % j ) continue ; 
				rep( k, 1, j ) {
					flag = 1 ; 
					for( re int t = k; t <= top; t += j ) if( c[st[t]] != c[st[k]] ) flag = 0 ;
					if( flag ) ans = min( ans, j ) ;
				}
				int kk = top / j ;
				rep( k, 1, kk ) {
					flag = 1 ; 
					for( re int t = k; t <= top; t += kk ) if( c[st[t]] != c[st[k]] ) flag = 0 ;
					if( flag ) ans = min( ans, kk ) ;
				}
			}
		}
		printf("%d\n", ans ) ; rep( i, 1, n ) d[i] = 0 ;
	}
	return 0 ;
}