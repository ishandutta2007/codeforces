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
const int N = 1e6 + 5 ; 
struct node {
	int x, y, id ; 
} a[N] ; 
int n, Maxn, cnt ; 
bool cmp( node x, node y ) {
	return ( x.x / cnt == y.x / cnt ) ? x.y < y.y : x.x < y.x ; 
}
signed main()
{
	n = gi() ; rep( i, 1, n ) 
	a[i].x = gi(), a[i].y = gi(), a[i].id = i, Maxn = max( Maxn, a[i].x ) ;
	cnt = sqrt( Maxn ) ;
	sort( a + 1, a + n + 1, cmp ) ;
	rep( i, 1, n ) printf("%d ", a[i].id ) ;
	return 0 ;
}