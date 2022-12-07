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
signed main()
{
	int T = gi() ;
	while( T-- ) {
		int n = gi(), d = gi() ; 
		int Tx = sqrt(d), ans = d + 2 ;
		for( re int i = max( 0ll, Tx - 10000 ); i <= Tx + 10000; ++ i ) {
			int fl = d / ( i + 1 ) ;
			if( fl * ( i + 1 ) < d ) ++ fl ;
			ans = min( ans, fl + i ) ;
		}
		if( ans <= n ) puts("Yes") ;
		else puts("No") ;
	}
	return 0 ;
}