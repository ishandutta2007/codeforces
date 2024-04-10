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
const int P = 998244353 ; 
const int N = 8e5 + 5 ; 
int n, f[N], g[N], ans[N] ; 
int fpow( int x, int k ) {
	int ans = 1, base = x ;
	while( k ) {
		if( k & 1 ) ans = 1ll * ans * base % P ; 
		base = 1ll * base * base % P, k >>= 1 ;
	} return ans % P ; 
} 
signed main()
{
	n = gi() ; 
	rep( i, 1, n ) f[i] = fpow( 10, n - i + 1 ) * ( n - i + 1 ) ; 
	rep( i, 1, n )
		ans[i] = f[i] - 2ll * f[i + 1] + f[i + 2], ans[i] = ( ans[i] + P + P ) % P ;
	rep( i, 1, n ) printf("%I64d ", ( ans[i] + P ) % P ) ;
	return 0 ;
}