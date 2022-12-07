#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define re register
inline int gi() {
	int cn = 0, flus = 1 ; char cc = getchar() ;
	while( cc > '9' || cc < '0' ) { if( cc == '-' ) flus = -flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' ) cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ; 
}
signed main() {
    int T = gi() ;
    while( T-- ) {
        int a = gi(), b = gi() ;
        int x = abs( b - a ) ;
        int ans = 0 ;
        ans += x / 5, x %= 5,
        ans += x / 2, x %= 2,
        ans += x ;
        printf("%d\n", ans ) ;
    }
    return 0 ; 
}