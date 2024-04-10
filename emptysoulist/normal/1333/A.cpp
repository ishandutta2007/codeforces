#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 2e5 + 5 ; 
int T, n, m, a[N] ; 
signed main()
{
	T = gi() ;
	while( T-- ) {
		n = gi(), m = gi() ;
		if( n * m % 2 == 1 ) {
			rep( i, 1, n ) {
				if( i & 1 ) {
					rep( j, 1, m ) ( j & 1 ) ? printf("B") : printf("W") ; 
					puts("") ;
				}
				else {
					rep( j, 1, m ) ( j & 1 ) ? printf("W") : printf("B") ; 
					puts("") ;
				}
			}
		} 
		else {
			rep( i, 1, n ) {
				if( i == 1 ) {
					printf("B") ;
					rep( j, 2, m ) ( j & 1 ) ? printf("W") : printf("B") ;
					puts("") ;
				}
				else if( i & 1 ) {
					rep( j, 1, m ) ( j & 1 ) ? printf("W") : printf("B") ; 
					puts("") ;
				}
				else {
					rep( j, 1, m ) ( j & 1 ) ? printf("B") : printf("W") ; 
					puts("") ;
				}
			}
		}
	}
	return 0 ;
}