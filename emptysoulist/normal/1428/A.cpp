#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 1e5 + 5 ; 
int n ; 
int abc(int x) {
	return (x > 0) ? x : -x ; 
}
signed main()
{
	int T = gi() ; 
	while( T-- ) {
		int x = gi(), y = gi() ; 
		int dx = gi(), dy = gi() ; 
		dx -= x, dy -= y ; 
		dx = abc(dx), dy = abc(dy) ; 
		if( dx == 0 && dy == 0 ) {
			puts("0") ; 
		}
		else if( dx == 0 || dy == 0 ) {
			int ans = dx + dy ; 
			printf("%lld\n", ans ) ; 
		}
		else {
			int ans = dx + dy + 2 ; 
			printf("%lld\n", ans ) ; 
		}
	}
	return 0 ;
}