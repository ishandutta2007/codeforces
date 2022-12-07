#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define re register
#define int long long
inline int gi() {
	int cn = 0, flus = 1 ; char cc = getchar() ;
	while( cc > '9' || cc < '0' ) { if( cc == '-' ) flus = -flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' ) cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ; 
}
const int N = 1e5 + 5 ; 
int n, m, a[N], b[N], tot ; 
signed main() {
    n = gi() ; int ans = 0, Ans = n * n ; 
    rep( i, 1, n ) a[i] = gi(), m += a[i] ;
    if( m == 1 ) {
        puts("-1") ; exit(0) ;
    }
    rep( k, 2, m ) {
        if( m % k == 0 ) {
            ans = 0 ;
            for( re int i = 1; i <= n; ++ i ) {
                if( a[i] == 1 ) {
                    b[++ tot] = i ; 
                    if( tot == k ) {
                        int mid = ( k + 1 ) / 2 ; 
                        for( re int j = 1; j <= tot; ++ j ) {
                            ans += abs( b[j] - b[mid] ) ;
                        }
                        tot = 0 ; 
                    }
                }   
            }
            Ans = min( Ans, ans ) ; 
        }
    }
    printf("%I64d\n", Ans ) ;
    return 0 ; 
}