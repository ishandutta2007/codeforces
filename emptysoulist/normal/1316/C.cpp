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
const int N = 2e6 + 5 ; 
int n, m, p, a[N], b[N] ; 
vector<int> G, F ; 
signed main()
{
	n = gi(), m = gi(), p = gi() ; 
	rep( i, 1, n ) a[i - 1] = gi() % p ;
	rep( i, 1, m ) b[i - 1] = gi() % p ; 
	int tmp = 0 ;
	for( re int i = 0; i <= n; ++ i ) 
	if( a[i] ) {
		tmp = i ; break ; 
	}
	for( re int j = 0; j <= m; ++ j ) {
		if( b[j] ) {
			printf("%lld\n", tmp + j ) ; break ; 
		}
	}
	return 0 ;
}