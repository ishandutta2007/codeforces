#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
} 
const int N = 1e5 + 5 ; 
int n, m, fa[N], sz[N], Ans, M, a[N], b[N], p[N], c[N], Id[N] ;
bool cmp( int x, int y ) {
	return c[x] > c[y] ;
}
int fd( int x ) {
	return ( x == fa[x] ) ? x : fa[x] = fd(fa[x]) ;
}
signed main() {
	n = gi(), m = gi() ; M = n * ( n - 1 ) ;
	rep( i, 1, n ) sz[i] = 1, fa[i] = i ;
	rep( i, 1, n ) p[i] = gi() ;
	rep( i, 1, m ) a[i] = gi(), b[i] = gi(), c[i] = min( p[a[i]], p[b[i]] ), Id[i] = i ;
	sort( Id + 1, Id + m + 1, cmp ) ;
	rep( i, 1, m ) {
		int x = a[Id[i]], y = b[Id[i]] ;
		int u = fd(x), v = fd(y) ;
		if( u == v ) continue ;
		Ans += 2ll * c[Id[i]] * sz[u] * sz[v] ;
		sz[u] += sz[v], fa[v] = u ;
	}
	printf("%.5lf\n", 1.0 * Ans / M ) ;
	return 0 ;
}