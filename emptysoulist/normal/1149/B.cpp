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
const int N = 1e5 + 5 ; 
const int M = 250 + 5 ; 
const int inf = 1234567890 ;
char s[N], t1[M], t2[M], t3[M] ; 
int n, q, dp[M][M][M], tp[30][N] ; 
signed main()
{
	n = gi(), q = gi() ; 
	scanf("%s", s + 1 ) ; s[n + 1] = 'a' - 1 ;  
    rep( i, 1, 26 ) tp[i][n + 2] = tp[i][n + 3] = n + 1 ;
	for( re int i = n + 1; i >= 1; -- i ) {
        rep( j, 1, 26 ) tp[j][i] = n + 1 ; 
		if( i != n + 1 ) rep( j, 1, 26 ) tp[j][i] = tp[j][i + 1] ; 
		tp[s[i] - 'a' + 1][i] = i ; 
	}
	int l1 = 0, l2 = 0, l3 = 0 ;
	rep( i, 0, 250 ) rep( j, 0, 250 ) rep( k, 0, 250 ) dp[i][j][k] = n + 1 ; 
	dp[0][0][0] = 0 ;
	while( q-- ) {
		char opt = getchar() ;
		while( opt != '+' && opt != '-' ) opt = getchar() ; 
		if( opt == '+' ) {
			int wh = gi() ; char x = getchar() ;
			while( x > 'z' || x < 'a' ) x = getchar() ;
			if( wh == 1 ) {
				t1[l1 + 1] = x ; 
				rep( i, 0, l2 ) rep( j, 0, l3 ) {
					dp[l1 + 1][i][j] = n + 1 ;
					dp[l1 + 1][i][j] = min( dp[l1 + 1][i][j], tp[x - 'a' + 1][dp[l1][i][j] + 1] ) ;
					if( i > 0 ) dp[l1 + 1][i][j] = min( dp[l1 + 1][i][j], tp[t2[i] - 'a' + 1][dp[l1 + 1][i - 1][j] + 1] ) ;
					if( j > 0 ) dp[l1 + 1][i][j] = min( dp[l1 + 1][i][j], tp[t3[j] - 'a' + 1][dp[l1 + 1][i][j - 1] + 1] ) ;
				} ++ l1 ; 
			}
			if( wh == 2 ) {
				t2[l2 + 1] = x ; 
				rep( i, 0, l1 ) rep( j, 0, l3 ) {
					dp[i][l2 + 1][j] = n + 1 ;
					dp[i][l2 + 1][j] = min( dp[i][l2 + 1][j], tp[x - 'a' + 1][dp[i][l2][j] + 1] ) ;
					if( i > 0ll ) dp[i][l2 + 1][j] = min( dp[i][l2 + 1][j], tp[t1[i] - 'a' + 1][dp[i - 1][l2 + 1][j] + 1] ) ;
					if( j > 0ll ) dp[i][l2 + 1][j] = min( dp[i][l2 + 1][j], tp[t3[j] - 'a' + 1][dp[i][l2 + 1][j - 1] + 1] ) ;

                    //printf("Line: %lld %lld %lld ( %lld %lld ) %lld %lld\n", i, l2, j, dp[i][l2][j], dp[i][l2 + 1][j], x - 'a' + 1, tp[x - 'a' + 1][dp[i][l2][j] + 1] ) ; 
				} ++ l2 ; 
			}
			if( wh == 3 ) {
				t3[l3 + 1] = x ; 
				rep( i, 0, l1 ) rep( j, 0, l2 ) {
					dp[i][j][l3 + 1] = n + 1 ;
					dp[i][j][l3 + 1] = min( dp[i][j][l3 + 1], tp[x - 'a' + 1][dp[i][j][l3] + 1] ) ;
					if( i > 0 ) dp[i][j][l3 + 1] = min( dp[i][j][l3 + 1], tp[t1[i] - 'a' + 1][dp[i - 1][j][l3 + 1] + 1] ) ;
					if( j > 0 ) dp[i][j][l3 + 1] = min( dp[i][j][l3 + 1], tp[t2[j] - 'a' + 1][dp[i][j - 1][l3 + 1] + 1] ) ;
				} ++ l3 ; 
			}
		}
		else {
			int wh = gi() ; 
			if( wh == 1 ) {
				rep( i, 0, l2 ) rep( j, 0, l3 ) dp[l1][i][j] = n + 1 ; 
				-- l1 ; 
			}
			if( wh == 2 ) {
				rep( i, 0, l1 ) rep( j, 0, l3 ) dp[i][l2][j] = n + 1 ; 
				-- l2 ; 
			}
			if( wh == 3 ) {
				rep( i, 0, l1 ) rep( j, 0, l2 ) dp[i][j][l3] = n + 1 ; 
				-- l3 ; 
			}
		}
		if( dp[l1][l2][l3] > n ) puts("NO") ;
		else puts("YES") ;  
	}
	return 0 ;
}