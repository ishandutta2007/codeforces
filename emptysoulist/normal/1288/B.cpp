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
signed main()
{
	int T = gi() ;
	while( T-- ) {
		int A = gi(), B = gi() ; 
		int l1 = 1, L0 = 0 ;
		while( l1 * 10 <= B + 1 ) l1 *= 10, ++ L0 ;
		printf("%I64d\n", A * L0 ) ;
		//a * 10^k = a * (b + 1)
		
	}
	return 0 ;
}