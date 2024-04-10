#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
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
int n, m, cnt, top, vis[N], s[N], w[N] ;
int head[N], deg[N], a[N], dp[N], go[N] ; 
vector<int> f[N] ;
struct E {
	int to, next ; 
} e[N * 16] ;
int gcd( int a, int b ) {
	return ( a == 0 ) ? b : gcd( b % a, a ) ;
}
int ax, ay ; 
int exgcd( int a, int b ) {
	if( a == 0 ) {
		ax = 0, ay = 1 ; return b ; 
	}
	int k = exgcd( b % a, a ) ;
	int tx = ay - ( b / a ) * ax, ty = ax ;
	ax = tx, ay = ty ; return k ; 
}
void add( int x, int y ) {
	e[++ cnt] = (E){ y, head[x] }, head[x] = cnt ;
}
queue<int> q ; 
void dfs( int x ) {
	if( dp[x] ) return ; dp[x] = w[x] ; 
	Next( i, x ) {
		int v = e[i].to ; dfs(v) ;
		if( dp[x] < dp[v] + w[x] ) dp[x] = dp[v] + w[x], go[x] = v ; 
	}
}
signed main()
{	
	n = gi(), m = gi() ; int x ; 
	rep( i, 1, n ) x = gi(), vis[x] = 1 ; 
	for( re int i = 1; i < m; ++ i ) {
		if( vis[i] ) continue ;
		int k = gcd( i, m ) ; f[k].push_back(i), ++ w[k] ; 
		if( s[k] ) continue ; s[k] = 1 ; 
		for( re int j = 2 * k; j < m; j += k ) add( k, j ), ++ deg[j] ;
	}
	for( re int i = 1; i < m; ++ i ) if( s[i] && !deg[i] ) q.push(i) ;
	int Id = 0, ans = 0 ;
	while( !q.empty() ) {
		int u = q.front() ; q.pop() ; dfs(u) ;
		if( ans < u ) ans = dp[u], Id = u ;
	}
	for( re int i = Id; i; i = go[i] )
	for( re int j = 0; j < f[i].size(); ++ j ) a[++ top] = f[i][j] ; 
	if( !vis[0] ) a[++ top] = 0 ; printf("%d\n", top ) ;
	if( top == 0 ) exit(0) ; printf("%d ", a[1] ) ;
	for( re int i = 2; i <= top; ++ i ) {
		if( a[i] == 0 ) printf("%d\n", a[i] ) ;
		else {
			int k = exgcd( a[i - 1], m ), dx = m / k, tp = a[i] / k ; 
			while( ax < 0 ) ax += dx ; ax %= dx ; 
			ax = ax * tp, printf("%d ", ax % m ) ;
		}
	}
	return 0 ;
}