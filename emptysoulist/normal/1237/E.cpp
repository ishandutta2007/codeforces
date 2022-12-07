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
int n ; 
signed main()
{
    n = gi() ; 
    if( n == 1 || n == 2 ) puts("1") ;
    else {
        int x = 4, y = 5 ; 
        while( max( x, y ) < n ) {
            int ux = x, uy = y ;
            if( ux & 1 ) x = ux + uy + 1, y = uy + uy + 1 ;
            else x = ux + uy + 1, y = ux + ux + 1 ; 
            if( x > y ) swap( x, y ) ;
        }
        if( x == n || y == n ) puts("1") ;
        else puts("0") ;
    }
	return 0 ;
}