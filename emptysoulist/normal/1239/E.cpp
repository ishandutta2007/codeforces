#include<bits/stdc++.h>
using namespace std ;
#define drep( i, s, t ) for( register int i = t; i >= s; -- i )
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 55 ; 
const int M = 1e6 + 5 ;
const int E = 5e4 + 5 ;
int n, Mx, a[N], ans[N][3], dp[N][M], Sum, pre[N][M], book[N] ; 
void out( int x ) {
	int tp = n ;
	for( re int i = 1; i <= n; ++ i ) {
		ans[i][2] = pre[tp][x], -- book[pre[tp][x]], x = x - pre[tp][x], -- tp ;
	} int cnt = 1 ; 
	for( re int i = 0; i <= Mx; ++ i ) {
		while( book[i] ) ans[++ cnt][1] = i, -- book[i] ;
	}
	for( re int i = 1; i <= n + 1; ++ i ) printf("%d ", ans[i][1] ) ;
	puts("") ; 
	for( re int i = 1; i <= n + 1; ++ i ) printf("%d ", ans[i][2] ) ;
	puts("") ; 
}
signed main()
{
	n = gi() ; rep( i, 1, n ) a[i] = gi(), Sum += a[i], Mx = max( Mx, a[i] ) ; 
	rep( i, 1, n ) a[i + n] = gi(), Sum += a[i + n], Mx = max( Mx, a[i + n] ) ; 
	sort( a + 1, a + 2 * n + 1 ) ; 
	ans[1][1] = a[1], ans[n][2] = a[2] ; 
	Sum = ( Sum - a[1] - a[2] ) / 2 ;
	dp[0][0] = 1 ; int m = 2 * n ; -- n ;
	rep( i, 3, m ) ++ book[a[i]] ; 
	rep( i, 3, m ) drep( j, 1, min( i, n ) )
		drep( k, a[i], Sum ) {
			if( dp[j][k] ) continue ; 
			if( dp[j - 1][k - a[i]] )
			pre[j][k] = a[i], dp[j][k] = 1 ;
		}
	drep( i, 0, Sum ) if( dp[n][i] ) { out(i) ; exit(0) ; }
	return 0 ;
}