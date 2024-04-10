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
int X ; 
int gcd( int a, int b ) {
	return ( a == 0 ) ? b : gcd( b % a, a ) ;
}
signed main()
{
	X = gi() ; int Ans = X ; 
	for( re int i = 1; i <= sqrt(X); ++ i ) {
		if( X % i == 0 ) {
			int u = X / i ; 
			int Gd = gcd( u, i ) ;
			if( Gd != 1 ) continue ;
			else {
				Ans = min( Ans, max( i, u ) ) ; 
			}
		}
	}
	printf("%I64d %I64d\n", X / Ans, Ans ) ;
	return 0 ;
}