#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 5e5 + 5 ; 
const int inf = 1e17 ; 
const int Inf = 1e16 ; 
int n, m, Sum, a[N], b[N], p[N], vis[N], book[N] ; 
int tree[N] ; 
int lowbit( int x ) {
	return ( x & (-x) ) ;
}
int qry( int x ) {
	int sum = 0 ; for( re int i = x; i; i -= lowbit(i) ) sum += tree[i] ; return sum ; 
}
void add( int x, int k ) { for( re int i = x; i <= m; i += lowbit(i) ) tree[i] += k ; }
signed main()
{
	n = gi() ;
	rep( i, 1, n ) a[i] = gi() ;
	rep( i, 1, n ) p[i] = gi(), Sum += p[i] ;
	m = gi(), add( 1, -inf ) ; 
	rep( i, 1, m ) b[i] = gi(), vis[b[i]] = i, book[b[i]] = 1 ; 
	vis[n + 1] = m + 1 ; 
	for( re int i = n; i >= 1; -- i )
		if( !vis[i] ) vis[i] = vis[i + 1] ;	
	rep( i, 1, n ) {
		if( p[i] > 0 ) add( vis[a[i]], p[i] ) ;
		if( book[a[i]] ) {
			int u = qry( vis[a[i]] - 1 ) + p[i] ; 
			int f = qry( vis[a[i]] ) ;
			if( u > f ) add( vis[a[i]], u - f ), add( vis[a[i]] + 1, f - u ) ;
		}
	}
	if( qry(m) < -Inf ) puts("NO") ;
	else puts("YES"), printf("%lld\n", Sum - qry(m) ) ;
	return 0 ;
}