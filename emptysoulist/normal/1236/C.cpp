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
const int N = 300 + 5 ;
int a[N][N], n ;
int Id( int x, int y ) {
	return ( x - 1 ) * n + y ; 
} 
signed main()
{
	n = gi() ; int type = 0 ; 
	rep( i, 1, n ) {
		if( i % 2 == 1 ) rep( j, 1, n ) a[j][i] = ++ type ;
		else for( re int j = n; j >= 1; -- j ) a[j][i] = ++ type ;
	}
	rep( i, 1, n ) {
		rep( j, 1, n ) printf("%d ", a[i][j] ) ;
		puts("") ; 
	}
	return 0 ;
}