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
const int N = 2e6 + 5 ; 
int n, a[N], vis[N], st[N], top ; 
signed main()
{
	int T = gi() ;
	while( T-- ) {
		n = gi() ; rep( i, 1, n ) a[i] = i - gi() ; 
		int u = 1 ; 
		while( u ) {
			if( vis[u] ) break ; 
			vis[u] = 1, u = a[u] ; 
		}
		while( u ) {
			if( !vis[u] ) break ; 
			st[++ top] = u, vis[u] = 0, u = a[u] ;
		}
		printf("%d\n", top ) ;
		rep( i, 1, top ) printf("%d ", st[i] ) ;
		puts(""), top = 0 ;
		rep( i, 1, n ) a[i] = vis[i] = 0 ; 
	}
	return 0 ;
}