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
const int P = 1e9 + 7 ;
const int N = 2e5 + 5 ;
int n, m, sum, Ans, fac[N], inv[N] ; 
int fpow( int x, int k ) {
	int ans = 1, base = x % P ; 
	while( k ) {
		if( k & 1 ) ans = ans * base % P ;
		base = base * base % P, k >>= 1 ;
	} return ans % P ; 
} 
signed main()
{
	n = gi(), m = gi() ; int x ; fac[0] = inv[0] = 1 ;
	rep( i, 1, n ) x = gi(), sum += x, sum %= P ;
	rep( i, 1, n ) fac[i] = fac[i - 1] * i % P, inv[i] = fpow( fac[i], P - 2 ) ;
	if( n == 1 && m == 1 ) { printf("%lld\n", sum ) ; exit(0) ; }
	else if( n == 1 ) { puts("0") ; exit(0) ; }
	-- n, -- m ;
	rep( i, 0, m ) {
		int u = m - i + 1 ;
		int f1 = fpow( u, n - 1 ) * n % P, f2 = fpow( u, n ) ;
		int ff = ( f1 + f2 ) % P ;
		int fm = inv[i] * inv[m - i] % P ;
		if( i & 1 ) Ans = ( Ans - fm * ff % P + P ) % P ;
		else Ans = ( Ans + fm * ff % P ) % P ; 
	} 
	printf("%lld\n", Ans * sum % P ) ;
	return 0 ;
}