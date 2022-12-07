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
const int N = 2e5 + 5 ; 
int n, m, a[N], Ans ; 
int fpow( int x, int k ) {
	int ans = 1, base = x ;
	while( k ) {
		if( k & 1 ) ans = ans * base % m ;
		base = base * base % m, k >>= 1 ;
	} return ans ; 
}
signed main()
{
	n = gi(), m = gi() ; Ans = 1 ; 
	rep( i, 1, n ) a[i] = gi() ;
	if( n > m + 2 ) {
		puts("0") ; exit(0) ; 
	}
	sort( a + 1, a + n + 1 ) ;
	for( re int i = 2; i <= n; ++ i ) {
		for( re int j = 1; j < i; ++ j ) {
			Ans = ( Ans * ( m + a[i] % m - a[j] % m ) ) % m ;
		}
	}
	cout << Ans << endl ;
	return 0 ;
}