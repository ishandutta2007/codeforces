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
int a[10] ; 
signed main()
{
	int T = gi() ; 
	while( T-- ) {
		rep( i, 1, 3 ) a[i] = gi() ; 
		sort( a + 1, a + 4 ) ;
		printf("%d\n", min((a[1] + a[2] + a[3]) / 2, a[1] + a[2] ) ) ;
	}
	return 0 ;
}