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
int A, B, C, Ans = 0 ;
signed main()
{
	int T = gi() ; 
	while( T-- ) {
		Ans = 0 ;
		A = gi(), B = gi(), C = gi() ; 
		for( re int i = 0; i <= min( A, B / 2 ); ++ i ) {
			int rAns = 3 * i ; 
			int rB = B - 2 * i ; 
			int ru = min( rB, C / 2 ) ;
			Ans = max( Ans, rAns + ru * 3 ) ;
		}
		printf("%d\n", Ans ) ;
	}
	return 0 ;
}