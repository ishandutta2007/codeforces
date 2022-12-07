#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define re register
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int P = 1e9 + 7 ; 
const int N = 25 + 5 ; 
int dp[1 << 24], sum[1 << 24], m, n, a[N], t[N] ;  
int lowbit( int x ) {
	return x & ( -x ) ;
}
signed main()
{
	n = gi() ; rep( i, 0, n - 1 ) a[i] = gi() ; 
	m = gi() ; rep( i, 1, m ) t[i] = gi() ; 
	dp[0] = 1 ; int maxn = ( 1 << n ) - 1 ; 
	for( re int i = 1; i <= maxn; ++ i ) {
		int bef = 0 ; 
		rep( j, 0, 23 ) if( ( 1 << j ) & i ) { bef = j ; break ; }
		sum[i] = sum[i - ( 1 << bef )] + a[bef] ; 
		if( sum[i] == t[1] || sum[i] == t[2] ) continue ; 
		for( re int j = i; j; j -= lowbit(j) )
			dp[i] = ( dp[i] + dp[i & (~lowbit(j))] ) % P ; 
	}
	printf("%d\n", dp[maxn] ) ;
	return 0 ;
}