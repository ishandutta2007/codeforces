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
int A[N], B[N], n, m ;
signed main()
{
	int T = gi() ; 
	while( T-- ) {
		n = gi() ; int rA = 0, rB = 0, Ans = 0 ; 
		rep( i, 1, n ) A[i] = gi(), ( A[i] & 1 ) ? ++ rA : ++ rB ; 
		m = gi() ; 
		rep( i, 1, m ) B[i] = gi(), Ans += ( B[i] & 1 ) ? rA : rB ; 
		printf("%I64d\n", Ans ) ;
	}
	return 0 ;
}