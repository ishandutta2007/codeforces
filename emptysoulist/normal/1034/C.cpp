#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int P = 1e9 + 7 ; 
const int N = 1e6 + 5 ; 
int n, f[N], a[N], sz[N], g[N], ans[N], S ; 
vector<int> E[N] ; 
void dfs( int x, int fa ) {
	sz[x] = a[x] ; 
	for( auto i : E[x] ) dfs( i, x ), sz[x] += sz[i] ;
}
int gcd( int x, int y ) {
	return ( x == 0 ) ? y : gcd( y % x, x ) ; 
}
signed main()
{
	n = gi() ; int x ; 
	rep( i, 1, n ) a[i] = gi() ; 
	rep( i, 2, n ) x = gi(), E[x].push_back(i) ; 
	dfs(1, 1) ; S = sz[1] ; 
	rep( i, 1, n ) {
		g[i] = S / gcd( sz[i], S ) ; 
		for( re int k = g[i]; k <= n; k += g[i] ) ++ f[k] ;
	}
	ans[1] = 1 ; 
	for( re int i = 2; i <= n; ++ i ) {
		if( S % i ) continue ; 
		if( f[i] != i ) continue ; 
		++ ans[i] ; 
		for( re int j = i * 2; j <= n; j += i ) ans[j] += ans[i], ans[j] %= P ; 
	}
	int Ans = 0 ; 
	rep( i, 1, n ) if( ( S % i == 0 ) && ( f[i] == i ) ) Ans = ( Ans + ans[i] ) % P ; 
	cout << Ans << endl ;
	return 0 ;
}