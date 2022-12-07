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
const int N = 50 ;
const int P = 1e9 + 7 ; 
int n, m, a[N][N] ; 
bool check() {
	for( re int i = 1; i <= n; ++ i ) {
		for( re int j = 1; j <= m; ++ j ) {
			int flag = 0 ; 
			if( a[i][j] == a[i][j - 1] ) ++ flag ;
			if( a[i][j] == a[i][j + 1] ) ++ flag ;
			if( a[i][j] == a[i - 1][j] ) ++ flag ;
			if( a[i][j] == a[i + 1][j] ) ++ flag ;
			if( flag > 1 ) return 0 ; 
		}
	}
	return 1 ; 
}
int Ans = 0 ;
void dfs( int x ) {
	if( x == ( n * m + 1 ) ) {
		Ans += check() ; return  ;
	}
	int ux = ( x - 1 ) / m + 1, uy = ( x - 1 ) % m + 1 ;
	a[ux][uy] = 0, dfs( x + 1 ) ;
	a[ux][uy] = 1 ;
	dfs( x + 1 ) ; 
}
const int M = 3e5 + 5 ; 
int f[M] ; 
signed main()
{
	n = gi(), m = gi() ; 
	if( n > m ) swap( n, m ) ; f[1] = 2, f[2] = 4 ; 
	rep( i, 3, m ) f[i] = ( f[i - 1] + f[i - 2] ) % P ; 
	printf("%I64d\n", ( f[n] + f[m] - 2 + P ) % P ) ;
	return 0 ;
}