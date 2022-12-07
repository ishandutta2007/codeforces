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
const int N = 5000 + 5 ; 
const int P = 1e9 + 7 ;
int n, m, s[N][N], inv, Ans ; 
int fpow( int x, int k ) {
	int ans = 1, base = x % P ; 
	while( k ) {
		if( k & 1 ) ans = ans * base % P ;
		base = base * base % P, k >>= 1 ;
	} return ans % P ; 
} 
signed main()
{
	s[0][0] = 1, n = gi(), m = gi(), inv = 1 ;
	rep( i, 1, m ) rep( j, 0, i ) {
		s[i][j] = s[i - 1][j - 1] ;
		if( j > 0 ) s[i][j] += j * s[i - 1][j] % P, s[i][j] %= P ;
	}
	for( re int j = 0; j <= min( n, m ); ++ j ) {
		int u = s[m][j] * fpow( 2, n - j ) % P ; 
		Ans += u * inv % P, Ans %= P ;
		inv *= ( n - j ), inv %= P ;
	}
	printf("%lld\n", Ans ) ;
	return 0 ;
}