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
const int N = 1e5 + 5 ; 
int n, a[N] ; 
int dfs( int x, int l, int r ) {
	if( x < 0 ) return 0 ; 
	int u = 1ll << x, fl = 0, pre = 0 ; 
	fl = a[l] & u ; 
	for( re int i = l + 1; i <= r; ++ i ) {
		int t = a[i] & u ; if( t != fl && ( pre == 0 ) ) pre = i ; 
	}
	if( !pre ) return dfs( x - 1, l, r ) ;
	return min( dfs( x - 1, l, pre - 1 ), dfs( x - 1, pre, r ) ) + u ;
}
signed main()
{
	n = gi() ; 
	rep( i, 1, n ) a[i] = gi() ; 
	sort( a + 1, a + n + 1 ) ;
	int ans = dfs( 30, 1, n ) ;
	printf("%I64d\n", ans ) ;
	return 0 ;
}