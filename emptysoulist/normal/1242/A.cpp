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
int n, top, num[150] ; 
int Get( int x ) {
	for( re int i = 2; i <= sqrt(x); ++ i ) {
		if( x % i ) continue ; 
		num[++ top] = i ;
		while( x % i == 0 ) x /= i ; 
	}
	if( x != 1 ) num[++ top] = x ; 
}
signed main()
{
	n = gi() ; 
	Get(n) ;
	if( top != 1 ) {
		printf("%I64d\n", 1ll ) ;
	}
	else printf("%I64d\n", num[top] ) ;
	return 0 ;
}