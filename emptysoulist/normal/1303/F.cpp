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
const int N = 300 + 5 ;
const int M = 2e6 + 5 ; 
int n, m, Q, a[N][N], Id[N][N], ans[M], fa[M << 1], cnt, num ;  
struct Que { int x, y, col, bef ; } q[M] ; 
int fd( int x ) { return ( x == fa[x] ) ? x : fa[x] = fd(fa[x]) ; }
void merge( int x, int y ) {
	int u = fd(x), v = fd(y) ;
	if( u != v ) fa[u] = v, -- num ;
}
void check( int x, int y ) {
	if( a[x][y] == a[x - 1][y] ) merge( Id[x][y], Id[x - 1][y] ) ;
	if( a[x][y] == a[x + 1][y] ) merge( Id[x][y], Id[x + 1][y] ) ;
	if( a[x][y] == a[x][y - 1] ) merge( Id[x][y], Id[x][y - 1] ) ;
	if( a[x][y] == a[x][y + 1] ) merge( Id[x][y], Id[x][y + 1] ) ;
}
void solve1() { // 
	rep( i, 1, Q ) {
		if( q[i].bef == q[i].col ) continue ;
		int x = q[i].x, y = q[i].y ; num = 1 ;
		a[x][y] = q[i].col, Id[x][y] = ++ cnt, fa[cnt] = cnt ;
		check( x, y ), ans[i] += num ; 
	}
}
void solve2() {
	for( re int i = Q; i >= 1; -- i ) {
		if( q[i].bef == q[i].col ) continue ;
		int x = q[i].x, y = q[i].y ; num = 1 ;
		a[x][y] = q[i].bef, Id[x][y] = ++ cnt, fa[cnt] = cnt ; 
		check( x, y ), ans[i] -= num ; 
	}
}
signed main()
{
	n = gi(), m = gi(), Q = gi() ;
	rep( i, 1, Q ) {
		int x = gi(), y = gi(), z = gi(), w = a[x][y] ; 
		q[i] = (Que){ x, y, z, w }, a[x][y] = z ;
	} ans[0] = 1, cnt = 0, memset( a, -1, sizeof(a) ) ;
	rep( i, 1, n ) rep( j, 1, m ) a[i][j] = 0 ;
	solve1(), memset( fa, 0, sizeof(fa) ), cnt = 0 ;
	rep( i, 1, n ) rep( j, 1, m ) Id[i][j] = ++ cnt, fa[cnt] = cnt ;
	rep( i, 1, n ) rep( j, 1, m ) check( i, j ) ;
	solve2() ; 
	rep( i, 1, Q ) ans[i] += ans[i - 1], printf("%d\n", ans[i] ) ;
	return 0 ;
}