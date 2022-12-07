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
const int N = 2500 + 5 ;
int n, cnt ;
struct Vec {
	int x, y ;	
	Vec( int xx = 0, int yy = 0 ) { x = xx, y = yy ; }
} p[N], b[N << 1] ;
Vec operator + ( Vec a, Vec b ) { return Vec( a.x + b.x, a.y + b.y ) ; } 
Vec operator - ( Vec a, Vec b ) { return Vec( a.x - b.x, a.y - b.y ) ; }
int operator * ( Vec a, Vec b ) { return a.x * b.y - a.y * b.x ; }
bool cmp( Vec a, Vec b ) {
	int ain = ( a.y < 0 ) | ( ( a.x > 0 ) & ( a.y == 0 ) ) ;
	int bin = ( b.y < 0 ) | ( ( b.x > 0 ) & ( b.y == 0 ) ) ;
	if( ain != bin ) return ain < bin ;
	return a * b > 0 ;
}
int C( int x, int y ) {
	int fx = 1, fy = 1 ; 
	for( re int i = 1; i <= y; ++ i ) fx *= ( x - i + 1 ), fy *= i ;
	return fx / fy ; 
}
signed main()
{
	n = gi() ; int X = C( n, 5 ), Y = 0 ; 
	rep( i, 1, n ) p[i].x = gi(), p[i].y = gi() ;
	rep( i, 1, n ) {
		cnt = 0 ;
		rep( j, 1, n ) if( i != j ) b[++ cnt] = p[j] - p[i] ;
		sort( b + 1, b + cnt + 1, cmp ) ;
		rep( j, 1, cnt ) b[j + cnt] = b[j] ;
		int lastp = 1 ; 
		for( re int j = cnt + 1; j <= ( cnt << 1 ); ++ j ) {
			while( lastp + cnt <= j || b[lastp] * b[j] < 0 ) ++ lastp ; 
			//<0 
			Y += C( j - lastp, 3 ) ; 
		}
	}
	printf("%lld\n", X * 5 - Y ) ;
	return 0 ;
}