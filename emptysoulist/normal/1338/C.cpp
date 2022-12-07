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
int n, m ; 
signed main()
{
	int T = gi() ; 
	while( T-- ) {
		n = gi(), m = ( ( n - 1 ) / 3 ) + 1 ; 
		int Id = 0, p = 0, Ans = 0 ; 
		for( re int i = 1; i <= 55; i += 2 ) {
			int u = 1ll << ( i - 1 ) ;
			if( m > u ) m -= u ; 
			else {
				p = i, Id = ( m - 1 ) + ( 1ll << ( i - 1 ) ) ; break ; 
			}
		}
		if( n % 3 == 1 ) printf("%lld\n", Id ) ;
		else if( n % 3 == 2 ) {
			for( re int i = 0; i < p - 1; i += 2 ) {
				 int u = ( ( Id >> i ) & 1 ) ;
				 int v = ( ( Id >> ( i + 1 ) ) & 1 ) ;
				 int t = v * 2 + u ;
				 if( t == 1 ) Ans += ( 2ll << i ) ;
				 if( t == 2 ) Ans += ( 3ll << i ) ;
				 if( t == 3 ) Ans += ( 1ll << i ) ;
			} cout << Ans + ( 1ll << (p) ) << endl ; 
		}
		else {
			for( re int i = 0; i < p - 1; i += 2 ) {
				 int u = ( ( Id >> i ) & 1 ) ;
				 int v = ( ( Id >> ( i + 1 ) ) & 1 ) ;
				 int t = v * 2 + u ;
				 if( t == 1 ) Ans += ( 3ll << i ) ;
				 if( t == 2 ) Ans += ( 1ll << i ) ;
				 if( t == 3 ) Ans += ( 2ll << i ) ;
			} cout << Ans + ( 3ll << (p - 1) ) << endl ; 
		}
	}
	return 0 ;
}