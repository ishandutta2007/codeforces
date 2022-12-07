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
const int N = 3e5 + 5 ; 
const int M = 10 + 5 ;
const int P = 1e9 + 7 ; 
int n, m, a[N][M], b[N][M], t[N], vis[1030], ans, tx1, ty1 ;
bool check( int x ) {
	rep( i, 1, n ) {
		t[i] = 0 ;
		rep( j, 1, m ) b[i][j] = ( a[i][j] >= x ), t[i] |= ( b[i][j] << ( j - 1 ) ) ; 
		vis[t[i]] = i ;
	}
	int maxm = ( 1 << m ) - 1 ; 
	rep( i, 1, maxm ) {
		if( !vis[i] ) continue ; 
		for( re int j = i; j; j = ( j - 1 ) & i )  
		vis[j] = vis[i] ;
	}
	rep( i, 0, maxm ) {
		if( vis[i] && vis[i ^ maxm] ) {
			tx1 = vis[i], ty1 = vis[i ^ maxm] ;
			return 1 ; 
		}
	}
	return 0 ; 
}
signed main()
{
	n = gi(), m = gi() ; tx1 = 1, ty1 = 1 ;
	rep( i, 1, n ) rep( j, 1, m ) a[i][j] = gi() ; 
	int l = 1, r = 1e10 ; 
	while( l <= r ) {
		int mid = ( l + r ) >> 1 ; 
		if( check(mid) ) l = mid + 1, ans = mid ;
		else r = mid - 1 ;
		memset( vis, 0, sizeof(vis) ) ;
	} 
	printf("%I64d %I64d\n", tx1, ty1 ) ;
	return 0 ;
}