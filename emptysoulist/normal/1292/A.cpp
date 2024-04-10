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
const int N = 1e5 + 5 ; 
int Ans, num, a[4][N], n ; 
signed main()
{
	n = gi() ; int Q = gi() ;
	rep( i, 1, Q ) {
		int x = gi() - 1, y = gi() ; 
		a[x][y] ^= 1 ;
		if( a[x][y] == 0 ) {
			if( a[x ^ 1][y - 1] == 1 ) -- num ;
			if( a[x ^ 1][y + 1] == 1 ) -- num ;
			if( a[x ^ 1][y] == 1 ) -- num ;
		}
		else {
			if( a[x ^ 1][y - 1] == 1 ) ++ num ;
			if( a[x ^ 1][y + 1] == 1 ) ++ num ;
			if( a[x ^ 1][y] == 1 ) ++ num ;
		}
		if( num ) puts("No") ;
		else puts("Yes") ;
	}
	return 0 ;
}