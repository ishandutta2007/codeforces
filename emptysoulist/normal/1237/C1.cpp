#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define il inline
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int inf = 123456789 ;
const int N = 50000 + 5 ;
struct Point {
    int x, y, z, id ;
} a[N], b[N], c[N], de[N], de2[N], zero ;
struct Del {
    int x, y ; 
} D[N] ; 
int n, num ; 
bool cmp1( Point x, Point y ) {
	return x.z < y.z ; 
}
bool cmp2( Point x, Point y ) {
	return x.y < y.y ; 
}
bool cmp3( Point x, Point y ) {
	return x.x < y.x ; 
}
inline Point solve2( int L, int R ) {
	rep( i, L, R ) c[i] = b[i] ; 
	sort( c + L, c + R + 1, cmp3 ) ; int i ;
	for( i = L; i < R; i += 2 ) D[++ num] = (Del){ c[i].id, c[i + 1].id } ;
	
	if( i == R ) return c[i] ;
	else return zero ; 
}
inline Point solve1( int L, int R ) {
	if( L == R ) return a[L] ;
	rep( i, L, R ) b[i] = a[i] ;
	sort( b + L, b + R + 1, cmp2 ) ;
	int cnt = 0, l = L, r = L, i ; 
	for( l = L; l <= R; l = r + 1 ) {
		while( b[r + 1].y == b[l].y && r + 1 <= R ) ++ r ; 
		de2[++ cnt] = solve2( l, r ) ;
	}
	sort( de2 + 1, de2 + cnt + 1, cmp2 ) ;
	for( i = 1; i <= cnt + 1; ++ i ) if( de2[i].id != 0 ) break ; 
	for( ; i < cnt; i += 2 ) D[++ num] = (Del){ de2[i].id, de2[i + 1].id } ;
	if( i == cnt ) return de2[cnt] ;
	else return zero ; 
}
signed main()
{
    n = gi() ; rep( i, 1, n ) 
    a[i].x = gi(), a[i].y = gi(), a[i].z = gi(), a[i].id = i ;
    sort( a + 1, a + n + 1, cmp1 ) ; zero.x = -inf, zero.y = -inf, zero.z = -inf ;
    int l = 1, r = 1, cnt = 0 ;
    for( l = 1; l <= n; l = r + 1 ) {
    	while( a[r + 1].z == a[l].z && r + 1 <= n ) ++ r ; 
    	de[++ cnt] = solve1( l, r ) ; 
	}
	sort( de + 1, de + cnt + 1, cmp1 ) ;
	for( l = 1; l <= cnt + 1; ++ l ) if( de[l].id != 0 ) break ; 
	for( ; l < cnt; l += 2 ) D[++ num] = (Del){ de[l].id, de[l + 1].id } ;
	rep( i, 1, num ) printf("%d %d\n", D[i].x, D[i].y ) ;
    return 0 ;
}