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
const int N = 1e6 + 5 ;
const int P = 998244353 ; 
int n, vis[N], Ans ;
vector<int> a[N] ; 
int fpow( int x, int k ) {
	int ans = 1, base = x ; 
	while( k ) {
		if( k & 1 ) ans = ans * base % P ; 
		base = base * base % P, k >>= 1 ; 
	} return ans ; 
} 
signed main()
{
	n = gi() ; int x, y, Inv = fpow( n, P - 2 ) ; 
	rep( i, 1, n ) {
		x = gi() ; rep( j, 1, x ) y = gi(), a[i].push_back(y), ++ vis[y] ;
	}
	rep( i, 1, n ) {
		int ans = 0, tx = Inv * fpow( a[i].size(), P - 2 ) % P ;
		for( re int j = 0; j < a[i].size(); ++ j ) {
			int k = a[i][j] ; 
			ans = ( ans + ( tx * ( vis[k] * Inv % P ) ) % P ) % P ; 
		}
		Ans = ( Ans + ans ) % P ; 
	}
	printf("%I64d\n", Ans ) ;
	return 0 ;
}