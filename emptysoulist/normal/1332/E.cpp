
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
const int P = 998244353 ; 
int n, m, L, R, L0, L1 ; 
int fpow( int x, int k ) {
	int ans = 1, base = x % P ; 
	while( k ) {
		if( k & 1 ) ans = 1ll * ans * base % P ; 
		base = 1ll * base * base % P, k >>= 1 ; 
	} return ans % P ; 
}
signed main()
{
	n = gi(), m = gi(), L = gi(), R = gi() ; 
	int nn = n & 1, mm = m & 1 ; 
	if( nn * mm ) {
		printf("%I64d\n", fpow( ( R - L + 1 ), n * m % ( P - 1 ) ) ) ;
		exit(0) ; 
	}
	int t = ( R - L + 1 ) / 2 ; 
	L0 = t, L1 = t ; 
	if( ( R - L + 1 ) & 1 ) {
		if( L & 1 ) ++ L1 ; 
		else ++ L0 ; 
	}
	int k = n * m ;
	int ans = fpow( 2, P - 2 ) ;
	int ans1 = fpow( L0 + L1, k ) ;
	int ans2 = fpow( ( L1 - L0 + P ) % P, k ) ;
	int Ans = ans * ( ( ans1 + ans2 ) % P ) % P ;
	printf("%I64d\n", Ans ) ;
	return 0 ;
}