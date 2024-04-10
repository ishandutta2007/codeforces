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
const int N = 1e5 + 5 ; 
const int M = 21 ; 
int n, m, f[1 << M], dp[1 << M], cnt[M][M] ;
char s[N] ;
int G( char x ) {
	return x - 'a' ;
}
signed main()
{
	n = gi(), m = gi() ;  
	scanf("%s", s + 1 ) ;
	rep( i, 1, n - 1 ) ++ cnt[G(s[i])][G(s[i + 1])], ++ cnt[G(s[i + 1])][G(s[i])] ;
	int maxn = ( 1 << m ) - 1, t = m - 1 ; 
	rep( i, 1, maxn ) {
		rep( j, 0, t ) {
			if( ( ( 1 << j ) & i ) ) 
			rep( k, 0, t ) {
				if( !( ( 1 << k ) & i ) )
				f[i] += cnt[j][k] ; 
			}
		}
	}
	memset( dp, 63, sizeof(dp) ), dp[0] = 0 ;
	rep( i, 1, maxn ) {
		rep( j, 0, t ) {
			if( ( 1 << j ) & i )
			dp[i] = min( dp[i ^ ( 1 << j )] + f[i], dp[i] ) ;
		}
	}
	printf("%d\n", dp[maxn] ) ;
	return 0 ;
}