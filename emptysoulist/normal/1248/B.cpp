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
const int N = 1e5 + 5 ; 
int n, S, A[N] ;
signed main()
{
	n = gi() ; rep( i, 1, n ) A[i] = gi(), S += A[i] ; 
	sort( A + 1, A + n + 1 ) ;
	int cnt = n / 2, rS = 0 ; 
	rep( i, 1, cnt ) rS += A[i] ; 
	printf("%I64d\n", rS * rS + ( S - rS ) * ( S - rS ) ) ;
	return 0 ;
}
//S