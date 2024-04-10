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
int n, a[N], g[N], sum[N], f[N], tree[N], tree2[N], vis[N] ; 
int lowbit( int x ) {
	return x & ( -x ) ;
}
int query( int x ) {
	int sum = 0 ;
	for( re int i = x; i; i -= lowbit(i) ) sum += tree[i] ;
	return sum ; 
}
void Add( int x, int k ) {
	for( re int i = x; i <= n; i += lowbit(i) ) tree[i] += k ;
}
int query2( int x ) {
	int sum = 0 ;
	for( re int i = x; i; i -= lowbit(i) ) sum += tree2[i] ;
	return sum ; 
}
void Add2( int x, int k ) {
	for( re int i = x; i <= n; i += lowbit(i) ) tree2[i] += k ;
}
int Get( int l, int r, int L, int R ) {
	int ans = l, m = query( r ) - query( l ) ; 
	while( l <= r ) {
		int mid = ( l + r ) >> 1 ; 
		int lkid = query( mid - 1 ) - query(L) ;
		int rkid = query(R) - query(mid) ;
		lkid = mid - L - lkid, rkid = R - mid - rkid ; 
		if( lkid <= rkid ) ans = mid, l = mid + 1 ;
		else r = mid - 1 ; 
	}
	return ans ; 
}
signed main()
{
	n = gi() ; rep( i, 1, n ) a[i] = gi(), g[a[i]] = i ; 
	for( re int i = 1; i <= n; ++ i ) {
		int u = i - 1 - query( g[i] ) ;
		f[i] = f[i - 1] + u, Add( g[i], 1 ) ; 
	}
	memset( tree, 0, sizeof(tree) ) ;
	int L = n, R = 1 ;
	for( re int i = 1; i <= n; ++ i ) Add( i, 1 ), Add2( i, i ), vis[i] = 1 ;
	for( re int i = 1; i <= n; ++ i ) {
		L = min( L, g[i] ), R = max( R, g[i] ) ;
		Add( g[i], -1 ), Add2( g[i], -g[i] ), vis[g[i]] = 0 ;
		int mid = Get( L, R, L, R ) ; 
		int k1 = query2( mid ) - query2( L ), kk1 = query( mid ) - query( L ) ;
		int k2 = query2( R ) - query2( mid ), kk2 = query( R ) - query( mid ) ;
		
		sum[i] = ( k1 - kk1 * L - ( kk1 * ( kk1 - 1 ) ) / 2 ) + ( kk2 * R - k2 - ( kk2 * ( kk2 - 1 ) ) / 2 ) ;
	}
	rep( i, 1, n ) printf("%I64d ", sum[i] + f[i] ) ;
	return 0 ;
}