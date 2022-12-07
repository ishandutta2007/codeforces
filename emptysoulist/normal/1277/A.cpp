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
int T ;  
signed main()
{
	int T = gi() ; 
	while( T-- ) {
		int n = gi() ; int u = 0, ans = 0 ;
		for( re int i = 1; i <= 9; ++ i ) {
			while( u <= n ) {
				u = u * 10 + i ; 
				if( u > n ) break ; 
				++ ans ; 
			} u = 0 ;
		}
		printf("%I64d\n", ans ) ;
	} 
	return 0 ;
}