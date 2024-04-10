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
int x, y ; 
signed main()
{
	x = gi(), y = gi() ; 
	if( x == y ) {
		printf("%d0 %d1", x, y ) ;
	}
	else if( y == 1 && x == 9 ) {
		printf("9 10\n") ;
	}
	else if( y - x == 1 ) {
		printf("%d9 %d0", x, y ) ;
	}
	else puts("-1") ;
	return 0 ;
}