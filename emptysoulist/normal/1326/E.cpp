#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define ls(x) ( x << 1 )
#define rs(x) ( x << 1 | 1 )
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 3e5 + 5 ; 
int n, p[N], vis[N], q[N] ; 
struct Tr {
	int mx, tag, id ;
} tr[N << 2] ;
void pushmark( int x ) {
	if( !tr[x].tag ) return ; 
	tr[ls(x)].mx += tr[x].tag, tr[rs(x)].mx += tr[x].tag,
	tr[ls(x)].tag += tr[x].tag, tr[rs(x)].tag += tr[x].tag, tr[x].tag = 0 ;
}
void update( int x, int l, int r, int ql, int qr, int k ) {
	if( r < ql || l > qr ) return ;
	if( ql <= l && r <= qr ) { tr[x].mx += k, tr[x].tag += k ; return ; }
	pushmark(x) ; int mid = ( l + r ) >> 1 ; 
	update( ls(x), l, mid, ql, qr, k ), update( rs(x), mid + 1, r, ql, qr, k ) ;
	if( tr[ls(x)].mx > tr[rs(x)].mx ) tr[x].id = tr[ls(x)].id, tr[x].mx = tr[ls(x)].mx ;
	else tr[x].id = tr[rs(x)].id, tr[x].mx = tr[rs(x)].mx ; 
}
void build( int x, int l, int r ) {
	if( l == r ) { tr[x].id = l ; return ; }
	int mid = ( l + r ) >> 1 ; 
	build( ls(x), l, mid ), build( rs(x), mid + 1, r ) ;
	tr[x].id = l ;
}
signed main()
{
	n = gi() ; 
	rep( i, 1, n ) p[i] = gi(), vis[p[i]] = i ;
	rep( i, 1, n ) q[i] = gi() ; 
	build( 1, 1, n ) ;
	int ans = n ; update( 1, 1, n, 1, vis[n], 1 ) ; 
	rep( i, 1, n ) {
		while( tr[1].mx <= 0 ) -- ans, update( 1, 1, n, 1, vis[ans], 1 ) ;
		printf("%d ", ans ) ;
		update( 1, 1, n, 1, q[i], -1 ) ;
		
	}
	return 0 ;
}