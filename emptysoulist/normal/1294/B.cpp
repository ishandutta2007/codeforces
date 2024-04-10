#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 1000 + 5 ; 
struct node {
	int x, y ; 
} p[N] ;
int n ; 
bool cmp( node a, node b ) {
	return ( a.x == b.x ) ? ( a.y < b.y ) : ( a.x < b.x ) ;
}
signed main()
{
	int T = gi() ; 
	while( T-- ) {
		n = gi() ;
		rep( i, 1, n ) p[i].x = gi(), p[i].y = gi() ;
		sort( p + 1, p + n + 1, cmp ) ;
		int X0 = 0, Y0 = 0, flag = 0 ;
		for( re int i = 1; i <= n; ++ i ) {
			if( p[i].y < p[i - 1].y ) flag = 1 ; 
		}
		if( flag ) puts("NO") ;
		else {
			puts("YES") ;
			rep( i, 1, n ) {
				for( re int j = X0 + 1; j <= p[i].x; ++ j ) printf("R") ;
				for( re int j = Y0 + 1; j <= p[i].y; ++ j ) printf("U") ;
				X0 = p[i].x, Y0 = p[i].y ;
			} puts("") ;
		}
	}
	return 0 ;
}