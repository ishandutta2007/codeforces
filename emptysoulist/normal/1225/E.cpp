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
const int P = 1e9 + 7 ; 
const int N = 2000 + 5 ;
int n, m, dp[N][N][2], U[N][N], D[N][N], A[N][N], Sum[N][N][2] ;
char s[N][N] ;
int check0( int x, int id, int R ) {
	int l = 1, r = R, ans = R ;
	while( l <= r ) {
		int mid = ( l + r ) >> 1 ; 
		if( ( U[id][m] - U[id][mid] ) <= x ) ans = mid, r = mid - 1 ;
		else l = mid + 1 ;
	} return ans ; 
}
int check1( int x, int id, int R ) {
	int l = 1, r = R, ans = R ;
	while( l <= r ) {
		int mid = ( l + r ) >> 1 ; 
		if( ( D[n][id] - D[mid][id] ) <= x ) ans = mid, r = mid - 1 ;
		else l = mid + 1 ;
	} return ans ; 
}
signed main()
{
	n = gi(), m = gi() ; if( n == m && n == 1 ) {
		puts("1") ; exit(0) ; 
	} 
	rep( i, 1, n ) scanf("%s", s[i] + 1 ) ;
	rep( i, 1, n ) rep( j, 1, m ) 
	A[i][j] = ( s[i][j] == 'R' ) ;
	
	rep( i, 1, n ) rep( j, 1, m )
		U[i][j] = U[i][j - 1] + ( A[i][j] == 1 ) ;
	rep( j, 1, m ) rep( i, 1, n )
		D[i][j] = D[i - 1][j] + ( A[i][j] == 1 ) ;
	Sum[1][1][1] = Sum[1][1][0] = dp[1][1][1] = dp[1][1][0] = 1 ;
	rep( i, 1, n ) rep( j, 1, m ) {
		if( i == 1 && j == 1 ) continue ; 
		int k0 = check0( m - j, i, j ) ;
		dp[i][j][0] = ( Sum[i][j - 1][1] - Sum[i][k0 - 1][1] + P ) % P ;  
		int k1 = check1( n - i, j, i ) ;
		dp[i][j][1] = ( Sum[i - 1][j][0] - Sum[k1 - 1][j][0] + P ) % P ;
		Sum[i][j][0] = ( Sum[i - 1][j][0] + dp[i][j][0] ) % P ; 
		Sum[i][j][1] = ( Sum[i][j - 1][1] + dp[i][j][1] ) % P ; 
	}
	printf("%d\n", ( dp[n][m][0] + dp[n][m][1] ) % P ) ;
	return 0 ;
}