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
const int N = 3e5 + 5 ;
const int inf = 1e7 + 7 ;
int n, m, fac[N], P ;
signed main()
{
	fac[0] = 1 ; n = gi(), P = gi() ;
	rep( i, 1, n ) fac[i] = fac[i - 1] * i % P ;
	int sum = 0, Ans = 0 ;
	rep( i, 1, n ) {
		sum = ( sum + fac[i] * fac[n - i] % P * ( n - i + 1 ) % P ) % P ;
		Ans = ( Ans + sum ) % P ; 
	}
	printf("%I64d\n", Ans ) ;
	return 0 ;
}