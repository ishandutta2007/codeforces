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
const int M = 100 + 5 ; 
int n, a[M][M], vis[30], fa[30], book[30] ;
char s[M] ;  
int fd( int x ) {
	return ( fa[x] == x ) ? x : fa[x] = fd(fa[x]) ; 
}
void merge( int x, int y ) {
	int u = fd(x), v = fd(y) ; 
	if( u == v ) return ; 
	fa[u] = v ; 
}
signed main()
{
	n = gi() ; rep( i, 1, 26 ) fa[i] = i ; 
	rep( i, 1, n ) {
		scanf("%s", s + 1 ) ; int m = strlen( s + 1 ) ;
		for( re int j = 1; j <= m; ++ j ) vis[s[j] - 'a' + 1] = 1 ;
		int fl = 0 ; 
		rep( j, 1, 26 ) if( vis[j] ) {
			fl = j ; break ;
		} book[fl] = 1 ; 
		for( re int k = fl + 1; k < 27; ++ k ) if( vis[k] ) merge( fl, k ), book[k] = 1 ;
		memset( vis, 0, sizeof(vis) ) ;
	} 
	int ans = 0 ;
	rep( i, 1, 26 ) if( book[i] && ( fa[i] == i ) ) ++ ans ;
	printf("%d\n", ans ) ;
	return 0 ;
}