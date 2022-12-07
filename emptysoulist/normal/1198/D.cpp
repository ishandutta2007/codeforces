#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 50 + 5 ; 
int n, f[N][N][N][N] ; 
char s[N][N] ; 
//(a, b) -> (c, d)
int dfs( int a, int b, int c, int d ) {
	if( f[a][b][c][d] != -1 ) return f[a][b][c][d] ; 
	if( ( a == c ) && ( b == d ) ) {
		f[a][b][c][d] = ( s[a][b] != '.' ) ;
		return f[a][b][c][d] ; 
	}
	f[a][b][c][d] = max( c - a + 1, d - b + 1 ) ;
	for( re int i = a + 1; i <= c; ++ i ) 
		f[a][b][c][d] = min( f[a][b][c][d], dfs( a, b, i - 1, d ) + dfs( i, b, c, d ) ) ;
	for( re int j = b + 1; j <= d; ++ j ) 
		f[a][b][c][d] = min( f[a][b][c][d], dfs( a, b, c, j - 1 ) + dfs( a, j, c, d ) ) ;
	return f[a][b][c][d] ; 
} 
signed main()
{
	n = gi() ; 
	memset( f, -1, sizeof(f) ) ; 
	rep( i, 1, n ) scanf("%s", s[i] + 1 ); 
	int ans = dfs( 1, 1, n, n ) ; 
	cout << ans << endl ; 
	return 0 ;
}