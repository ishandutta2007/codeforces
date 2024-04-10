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
const int N = 2e6 + 5 ; 
int f[N], n, c[N], d[N], limit = 1, m, Ans ; 
int lowbit( int x ) {
	return x & ( -x ) ;
}
int fpow( int x, int k ) {
	int ans = 1, base = x ; 
	while( k ) {
		if( k & 1 ) ans = ans * base % P ; 
		base = base * base % P, k >>= 1 ; 
	} return ans ; 
}
void FWT( int *a, int type ) { //or
	for( re int k = 1; k < limit; k <<= 1 )
	for( re int i = 0; i < limit; i += ( k << 1 ) )
	for( re int j = i; j < i + k; ++ j )
		a[j] += a[j + k] ;
}
signed main()
{
	n = gi() ; int x ; 
	rep( i, 1, n ) x = gi(), ++ c[x], m = max( m, x ) ; 
	while( limit <= m ) limit <<= 1 ; 
	FWT( c, 1 ), d[0] = 1 ; 
	for( re int i = 0; i < limit; ++ i ) {
		if( !d[i] ) d[i] = - d[i ^ lowbit(i)] ; 
		Ans = ( Ans + d[i] * ( fpow( 2, c[i] ) - 1 ) % P + P ) % P ; 
	}
	printf("%I64d\n", Ans ) ;
	return 0 ;
}