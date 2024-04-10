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
const int N = 4e5 + 5 ; 
int Q, X, vis[N], top, ans ; 
signed main()
{
	Q = gi(), X = gi() ;
	while( Q-- ) {
		int x = gi() ; x = x % X ;
		++ vis[x] ;
		while( 1 ) {
			if( vis[ans % X] ) -- vis[ans % X] ;
			else break ;
			++ ans ;
		} printf("%I64d\n", ans ) ;
	}
	return 0 ;
}