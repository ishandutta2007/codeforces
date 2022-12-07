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
int P = 1e18, l, r ;
signed main()
{
	int A = gi() ; 
	l = A - ( ( P % A ) * 9 % A * 9 ) % A, r = l + P - 1 ;
	printf("%lld %lld", l, r ) ;
	return 0 ;
}