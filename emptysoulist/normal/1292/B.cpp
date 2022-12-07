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
const int inf = 3e16 + 5 ;
const int M = 100 + 5 ; 
int X0, Y0, ax, ay, bx, by ;
int a[M], b[M], Dec, num ;
int abc( int x ) {
	return ( x > 0 ) ? x : -x ; 
} 
signed main()
{
	a[0] = gi(), b[0] = gi(), ax = gi(), ay = gi(), bx = gi(), by = gi() ;
	int XS = gi(), YS = gi(), T = gi(), cnt = 0 ;
	for( re int i = 1; i <= 100; ++ i ) {
		a[i] = a[i - 1] * ax + bx, cnt = i,
		b[i] = b[i - 1] * ay + by ;
		if( max( a[i], b[i] ) >= inf ) break ;
	}
	for( re int i = 0; i <= cnt; ++ i ) {
		Dec = abc( XS - a[i] ) + abc( YS - b[i] ) ;
		if( Dec > T ) continue ; 
		int us = 1 ; 
		for( re int j = i + 1; j <= cnt; ++ j ) {
			Dec += ( abc( a[j] - a[j - 1] ) + abc( b[j] - b[j - 1] ) ) ;
			if( Dec > T ) break ;
			++ us ;
		}
		int us2 = 1, Del = abc( XS - a[i] ) + abc( YS - b[i] ) ;
		for( re int j = i - 1; j >= 0; -- j ) {
			Del += ( abc( a[j + 1] - a[j] ) + abc( b[j + 1] - b[j] ) ) ;
			if( Del > T ) break ;
			++ us2 ;
		}
		num = max( num, max( us, us2 ) ) ;
	}
	printf("%I64d\n", num ) ;
	return 0 ;
}