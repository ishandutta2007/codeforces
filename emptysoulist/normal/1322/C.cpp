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
const int N = 5e5 + 5 ; 
const int P = 998244353 ; 
int n, m, w[N], S[N], Ans ;
vector<int> G[N] ;
map<int, int> a ;
int gcd( int x, int y ) {
	return ( x == 0 ) ? y : gcd( y % x, x ) ;
}
void solve() {
	a.clear(), n = gi(), m = gi(), Ans = 0 ; int x, y ;
	rep( i, 1, n ) w[i] = gi(), S[i] = 0, G[i].clear() ;
	rep( i, 1, m ) x = gi(), y = gi(), G[y].push_back(x) ;
	rep( i, 1, n  ) sort( G[i].begin(), G[i].end() ) ;
	rep( i, 1, n ) for( int k : G[i] ) S[i] = ( S[i] * 233 + k ) % P ;
	rep( i, 1, n ) a[S[i]] += w[i] ;
	rep( i, 1, n ) if( S[i] ) {
		Ans = ( Ans ) ? gcd( Ans, a[S[i]] ) : a[S[i]] ;
	}
	printf("%lld\n", Ans ) ;
}
signed main()
{
	int T = gi() ;
	while( T-- ) solve() ;
	return 0 ;
}