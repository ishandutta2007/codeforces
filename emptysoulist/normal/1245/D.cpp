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
const int N = 2000 + 5 ;
int n, Ans ; 
struct P {
	int x, y, id ;	
} p[N] ;
struct E {
	int fr, ed, w, bk ; 
} e[N * N] ;
bool cmp( int x, int y ) {
	return e[x].w < e[y].w ; 
}
int fa[N], c[N], k[N], Id[N * N], cnt, book1, book2 ;
int Dis( int x, int y ) {
	return abs( p[x].x - p[y].x ) + abs( p[x].y - p[y].y ) ; 
}
int Get( int x, int y ) {
	return ( k[x] + k[y] ) * ( Dis( x, y ) ) ; 
}
int fd( int x ) {
	return ( x == fa[x] ) ? x : fa[x] = fd(fa[x]) ; 
}
signed main()
{
	n = gi() ; 
	rep( i, 1, n ) p[i].x = gi(), p[i].y = gi(), p[i].id = i ; 
	rep( i, 1, n ) c[i] = gi() ;
	rep( i, 1, n ) k[i] = gi() ; 
	rep( i, 1, n ) {
		e[++ cnt] = (E){ n + 1, i, c[i] }, Id[cnt] = cnt ;
		rep( j, i + 1, n ) {
			e[++ cnt] = (E){ i, j, Get( i, j ) }, Id[cnt] = cnt;
		}
	}
	rep( i, 1, n + 1 ) fa[i] = i ;
	sort( Id, Id + cnt + 1, cmp ) ;
	rep( i, 1, cnt ) {
		int u = e[Id[i]].fr, v = e[Id[i]].ed ;
		u = fd(u), v = fd(v) ;
		if( u == v ) continue ;
		e[Id[i]].bk = 1, Ans += e[Id[i]].w ;
		fa[u] = v ;
	}
	rep( i, 1, cnt ) {
		if( !e[i].bk ) continue ; 
		if( e[i].fr == n + 1 ) ++ book1 ; 
		else ++ book2 ; 
	}
	printf("%I64d\n%I64d\n", Ans, book1 ) ;
	rep( i, 1, cnt ) {
		if( !e[i].bk ) continue ; 
		if( e[i].fr == n + 1 ) printf("%I64d ", e[i].ed ) ;
	}
	puts("") ;
	printf("%I64d\n", book2 ) ;
	rep( i, 1, cnt ) {
		if( !e[i].bk ) continue ; 
		if( e[i].fr != n + 1 ) printf("%I64d %I64d\n", e[i].fr, e[i].ed ) ;
	} 
	return 0 ;
}