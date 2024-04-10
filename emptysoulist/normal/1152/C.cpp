#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define inf 12345678
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
int A, B, Ans, rk ;
int gcd( int x, int y ) {
	return ( x == 0 ) ? y : gcd( y % x, x ) ;
}
void solve( int x ) {
	int k = ( B / x ) * x ; 
	while( k < B ) k += x ; 
	int m = k - B ; 
	int rAns = ( A + m ) / gcd( A + m, B + m ) * ( B + m ) ;
	if( rAns < Ans || ( rAns == Ans && m < rk ) ) {
		Ans = rAns, rk = m ;
	} 
}
signed main()
{
	A = gi(), B = gi() ; if( A > B ) swap( A, B ) ; 
	int k = B - A ; Ans = A / gcd( A, B ) * B ; 
	for( re int i = 1; i * i <= k; ++ i ) {
		if( k % i == 0 ) solve(i), solve( k / i ) ;
	} printf("%lld\n", rk ) ;
	return 0 ;
}