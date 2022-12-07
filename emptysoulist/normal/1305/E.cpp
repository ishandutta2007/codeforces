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
const int N = 5000 + 5 ; 
const int Inf = 1e8 ;
const int inf = 1e9 ;
int n, m, a[N], top, ans ; 
signed main()
{
	n = gi(), m = gi() ; 
	rep( i, 1, n ) {
		a[i] = i ;
		if( ans + ( i - 1 ) / 2 > m ) break ; 
		ans += ( i - 1 ) / 2 ;
		++ top ;
	}
	if( top == n ) {
		if( ans < m ) {
			puts("-1") ; exit(0) ;
		} else {
			rep( i, 1, n ) printf("%I64d ", a[i] ) ;
			puts("") ; exit(0) ;
		}
	}
	int u = m - ans ; 
	a[top + 1] = top + top - 2 * u + 1 ;
	int Use = a[top + 1] + 1, Kt = Inf ;
	for( re int i = top + 2; i <= n; ++ i ) {
		a[i] = Kt, Kt += Use ;
	}
	rep( i, 1, n ) printf("%I64d ", a[i] ) ;
	puts("") ;
	return 0 ;
}