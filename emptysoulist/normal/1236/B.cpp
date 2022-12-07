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
int n, m ; 
int fpow( int x, int k ) {
    int ans = 1, base = x ; 
    while( k ) {
        if( k & 1 ) ans = 1ll * ( ans * base ) % P ;
        base = 1ll * ( base * base ) % P, k >>= 1; 
    }
    return ans % P ; 
}
signed main()
{
    n = gi(), m = gi() ; 
    printf("%I64d\n", fpow( fpow( 2, m ) - 1, n ) ) ;
	return 0 ;
}