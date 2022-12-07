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
const int N = 1000 + 5 ; 
int a[N], n, m, Id[N], Sum ;
bool cmp( int x, int y ) {
    return a[x] < a[y] ; 
}
signed main() {
    int T = gi() ;
    while( T-- ) {
        n = gi(), m = gi(), Sum = 0 ; 
        rep( i, 1, n ) Id[i] = i, a[i] = gi(), Sum += a[i] ;
        if( n == 2 ) puts("-1") ;
        else if( m < n ) puts("-1") ;
        else {
            sort( Id + 1, Id + n + 1, cmp ) ;
            Sum *= 2 ; 
            for( re int i = n + 1; i <= m; ++ i ) 
            Sum += a[Id[1]], Sum += a[Id[2]] ;
            printf("%I64d\n", Sum ) ;
            rep( i, 2, n ) printf("%I64d %I64d\n", i, i - 1 ) ;
            printf("%I64d %I64d\n", 1ll, n ) ;
            //sort( Id + 1, Id + n + 1, cmp ) ;
            for( re int i = n + 1; i <= m; ++ i ) 
            printf("%I64d %I64d\n", Id[1], Id[2] ) ;
        }
   }
    return 0 ; 
}