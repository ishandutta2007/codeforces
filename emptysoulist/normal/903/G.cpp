#include<bits/stdc++.h>
using namespace std;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define re register
#define ls(x) x * 2
#define rs(x) x * 2 + 1
#define inf 1e17
#define int long long
int read() {
	char cc = getchar(); int cn = 0, flus = 1;
	while(cc < '0' || cc > '9') {  if( cc == '-' ) flus = -flus;  cc = getchar();  }
	while(cc >= '0' && cc <= '9')  cn = cn * 10 + cc - '0', cc = getchar();
	return cn * flus;
}
const int N = 2e5 + 5 ; 
int n, m, q, A[N], B[N], C[N] ; 
int head[N], cnt ; 
struct E { int to, next, w ; } e[N * 2] ;
struct Tr { int mi, tag ; } tr[N * 4] ;
inline void add( int x, int y, int z ) {
	e[++ cnt] = (E){ y, head[x], z }, head[x] = cnt ; 
}
inline void build( int x, int l, int r ) {
	if( l == r ) { tr[x].mi = B[l] ; return ; }
	int mid = ( l + r ) >> 1 ; 
	build( ls(x), l, mid ), build( rs(x), mid + 1, r ) ;
	tr[x].mi = min( tr[ls(x)].mi, tr[rs(x)].mi ) ;
}
inline void pushmark( int x ) {
	if( tr[x].tag )
		tr[ls(x)].mi += tr[x].tag, tr[rs(x)].mi += tr[x].tag, 
		tr[ls(x)].tag += tr[x].tag, tr[rs(x)].tag += tr[x].tag, 
		tr[x].tag = 0 ;
}
inline void update( int x, int l, int r, int ql, int qr, int w ) {
	if( ql > r || qr < l ) return ; 
	if( ql <= l && r <= qr ) { tr[x].mi += w, tr[x].tag += w ; return ; }
	int mid = ( l + r ) >> 1 ; pushmark(x) ; 
	update( ls(x), l, mid, ql, qr, w ), update( rs(x), mid + 1, r, ql, qr, w ) ;
	tr[x].mi = min( tr[ls(x)].mi, tr[rs(x)].mi ) ; 
}
void Init() {
	build( 1, 1, n ) ; 
	rep( x, 1, n ) {
		Next( i, x ) update( 1, 1, n, 1, e[i].to, e[i].w ) ;
		C[x] = tr[1].mi ; 
	}
	memset( tr, 0, sizeof(tr) ) ;
	rep( i, 1, n ) B[i] = A[i] + C[i] ; 
	build( 1, 1, n ) ;
}
signed main()
{
	n = read(), m = read(), q = read() ; int x, y, z ; 
	rep( i, 2, n ) A[i - 1] = read(), B[i] = read() ; B[1] = 0 ;
	rep( i, 1, m ) {
		x = read(), y = read(), z = read(), add( x, y, z ) ;
	}
	Init() ; printf("%I64d\n", tr[1].mi );
	rep( i, 1, q ) {
		x = read(), z = read() ; 
		update( 1, 1, n, x, x, z - A[x] ), A[x] = z ; 
		printf("%I64d\n", tr[1].mi ) ; 
	}
	return 0 ;
}