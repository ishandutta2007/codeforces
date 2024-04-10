#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define int long long
#define D(x) ( 1 << ( x - 1 ) )
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 2e5 + 5 ; 
const int M = 17 ;
int n, m, cnt, a[N], A[N], num[M], go[N], vis[N], pre[N] ;
int ok[1 << 16], las[1 << 16], fa[M], fb[M], c ;
bool dp[1 << 16] ; 
map<int, int> Id ;
void Init( int x, int id ) {
	a[++ cnt] = id, A[cnt] = x, Id[x] = cnt ;
}
void dfs( int x ) {
	if( !x ) return ;
	if( vis[x] == c ) {
		int w = 1 << ( a[x] - 1 ) ; 
		for( int y = pre[x]; y != x; y = pre[y] ) {
			if( w & ( 1 << ( a[y] - 1 ) ) ) return ;
			w |= ( 1 << a[y] - 1 ) ;
		} 
		dp[w] = 1, ok[w] = x ; return ;
	} 
	if( vis[x] ) return ; 
	vis[x] = c, pre[go[x]] = x, dfs( go[x] ) ;
}
void Dfs( int x ) {
	if( ok[x] ) {
		int u = ok[x], y = u ;
		while(1) {
			fa[a[go[u]]] = A[go[u]], fb[a[go[u]]] = a[u], u = go[u] ;
			if( u == y ) break ;
		}
		return ; 
	}
	Dfs( x ^ las[x] ), Dfs( las[x] ) ;
}
signed main()
{
	m = gi() ; int x, sz, sum = 0 ; 
	rep( i, 1, m ) {
		sz = gi() ; rep( j, 1, sz ) x = gi(), Init( x, i ), num[i] += x ;
	} 
	rep( i, 1, m ) sum += num[i] ;
	if( sum % m != 0 ) { puts("No") ; exit(0) ; }
	sum /= m ; 
	rep( i, 1, cnt ) go[i] = Id[A[i] + sum - num[a[i]]] ;
	rep( i, 1, cnt ) if( !vis[i] ) ++ c, dfs(i) ;
	int maxm = ( 1 << m ) - 1 ; dp[0] = 1 ;
	for( re int i = 1; i <= maxm; ++ i ) {
		if( dp[i] ) continue ;
		for( re int j = i; j; j = ( j - 1 ) & i ) {
			dp[i] = dp[j] & dp[i - j], las[i] = j ;
			if( dp[i] ) break ;
		}
	} 
	if( !dp[maxm] ) { puts("No") ; exit(0) ; }
	puts("Yes") ; Dfs( maxm ) ;
	rep( i, 1, m ) printf("%I64d %I64d\n", fa[i], fb[i] ) ;
	return 0 ;
}