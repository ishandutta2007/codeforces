
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
const int N = 2e5 + 5 ; 
int T, n, a[N], ans ; 
set<int> b ;
signed main()
{
	int T = gi() ; 
	while( T-- ) {
		n = gi() ; rep( i, 1, n ) {
			a[i] = gi() ;
			if( !( a[i] & 1 ) ) b.insert(a[i]) ; 
		}
		set<int>::iterator it ;
		while( !b.empty() ) {
			it = b.end() ; -- it ;
			++ ans ; int u = *it ; b.erase(u), u /= 2 ; 
			if( ( u & 1 ) == 0 ) b.insert(u) ;
		}
		printf("%d\n", ans ), b.clear(), ans = 0 ;
	} 
	return 0 ;
}