#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define ls(x) ( x << 1 )
#define rs(x) ( x << 1 | 1 ) 
#define int long long
#define inf 1234567890000
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 8e5 + 5 ; 
int n, q, S, cnt, idnex, head[N], tr[N], tr2[N], dis[N], vis[N] ; 
struct E {
	int to, next, w ; 
} e[N * 10] ;
void add( int x, int y, int z ) {
	e[++ cnt] = (E){ y, head[x], z }, head[x] = cnt ; 
}
void build( int x, int l, int r ) {
	tr[x] = ++ idnex ; if( l == r ) { add( tr[x], l, 0 ) ; return ; }
	int mid = ( l + r ) >> 1 ;
	build( ls(x), l, mid ), build( rs(x), mid + 1, r ) ;
	add( tr[x], tr[ls(x)], 0 ), add( tr[x], tr[rs(x)], 0 ) ;
}
void build2( int x, int l, int r ) {
	tr2[x] = ++ idnex ; 
	if( l == r ) { 
		add( l, tr2[x], 0 ) ; return ; 
	}
	int mid = ( l + r ) >> 1 ; 
	build2( ls(x), l, mid ), build2( rs(x), mid + 1, r ),
	add( tr2[ls(x)], tr2[x], 0 ), add( tr2[rs(x)], tr2[x], 0 ) ;
}
void Add( int x, int l, int r, int ql, int qr, int id, int z ) {
	if( r < ql || l > qr ) return ;
	if( ql <= l && r <= qr ) { add( id, tr[x], z ) ; return ; }
	int mid = ( l + r ) >> 1 ; 
	Add( ls(x), l, mid, ql, qr, id, z ), Add( rs(x), mid + 1, r, ql, qr, id, z ) ;
}
void Add2( int x, int l, int r, int ql, int qr, int id, int z ) {
	if( r < ql || l > qr ) return ;
	if( ql <= l && r <= qr ) { 
		add( tr2[x], id, z ) ; 
		return ; 
	}
	int mid = ( l + r ) >> 1 ; 
	Add2( ls(x), l, mid, ql, qr, id, z ), Add2( rs(x), mid + 1, r, ql, qr, id, z ) ;
}
queue<int> Q ; 
void SPFA() {
	rep( i, 1, idnex ) dis[i] = inf ; 
	dis[S] = 0, Q.push(S) ; 
	while( !Q.empty() ) {
		int u = Q.front() ; Q.pop(), vis[u] = 0 ;
		Next( i, u ) {
			int v = e[i].to ;
			if( dis[v] > dis[u] + e[i].w ) {
				dis[v] = dis[u] + e[i].w ;
				if( !vis[v] ) Q.push(v), vis[v] = 1 ; 
			}
		}
	} 
}
signed main()
{
	n = gi(), q = gi(), S = gi(), idnex = n ;
	int opt, x, l, r, z ; build( 1, 1, n ), build2( 1, 1, n ) ;
	while( q-- ) {
		opt = gi(), x = gi(), l = gi(), r = gi() ;
		if( opt == 1 ) add( x, l, r ) ;
		if( opt == 2 ) z = gi(), Add( 1, 1, n, l, r, x, z ) ;
		if( opt == 3 ) z = gi(), Add2( 1, 1, n, l, r, x, z ) ;
	}
	SPFA() ; 
	rep( i, 1, n ) printf("%lld ", ( dis[i] < inf ) ? dis[i] : -1 ) ;
	return 0 ;
}