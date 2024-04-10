#include<bits/stdc++.h>
using namespace std;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define ls(x) ( x * 2 )
#define rs(x) ( x * 2 + 1 )
int read() {
	char cc = getchar(); int cn = 0, flus = 1;
	while(cc < '0' || cc > '9') {  if( cc == '-' ) flus = -flus;  cc = getchar();  }
	while(cc >= '0' && cc <= '9')  cn = cn * 10 + cc - '0', cc = getchar();
	return cn * flus;
}
const int N = 2e5 + 5 ;
int a[N], n, q ; 
struct Tree {
	int mi, tag ;
} tr[N * 4];
void pushmark( int x ) {
	if( tr[x].tag ) {
		int u = tr[x].tag ;
		if( tr[ls(x)].mi <= u ) {
			tr[ls(x)].mi = u,
			tr[ls(x)].tag = u ;
		}
		if( tr[rs(x)].mi <= u ) {
			tr[rs(x)].mi = u,
			tr[rs(x)].tag = u ;
		}
		tr[x].tag = 0 ;
		tr[x].mi = min( tr[ls(x)].mi, tr[rs(x)].mi ) ;
	}
}
void build( int x, int l, int r ) {
	if( l == r ) {
		tr[x].mi = a[l] ; return ;
	}
	int mid = ( l + r ) >> 1 ; 
	build( ls(x), l, mid ), build( rs(x), mid + 1, r ) ;
	tr[x].mi = min( tr[ls(x)].mi, tr[rs(x)].mi ) ;
}
void Add( int x, int l, int r, int wh, int val ) {
	if( l == r ) {
		tr[x].tag = 0, tr[x].mi = val ; return ; 
	}
	pushmark(x) ;
	int mid = ( l + r ) >> 1 ; 
	if( mid >= wh ) Add( ls(x), l, mid, wh, val ) ;
	else Add( rs(x), mid + 1, r, wh, val ) ;
	tr[x].mi = min( tr[ls(x)].mi, tr[rs(x)].mi ) ;
}
void dfs( int x, int l, int r ) {
	if( l == r ) {
		printf("%d ", tr[x].mi ) ;
		return ; 
	}
	pushmark(x) ;
	int mid = ( l + r ) >> 1 ;
	dfs( ls(x), l, mid ),
	dfs( rs(x), mid + 1, r ) ;
}
signed main()
{
	n = read() ; rep( i, 1, n ) a[i] = read() ;
	build( 1, 1, n ) ;
	q = read() ; int opt, x, y ;
	rep( i, 1, q ) {
		opt = read(), x = read() ;
		if( opt == 1 ) y = read(), Add( 1, 1, n, x, y ) ;
		else if( tr[1].mi < x ) tr[1].mi = x, tr[1].tag = x ;
	} 
	dfs( 1, 1, n ) ;
	return 0;
}