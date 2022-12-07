#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define pb push_back
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int P = 998244353 ; 
const int N = 3000 + 5 ; 
int n, cnt, a[1505][1505], ans[N], fa[N], sz[N], eg[N], L[N], R[N], fl[N] ; 
int num, dp[1505][1505], Id[N] ; 
struct E {
	int fr, to, w ; 
} e[N * N] ;
vector<int> G[N] ; 
vector<int> rr[N] ; 
bool cmp( E x, E y ) {
	return x.w < y.w ; 
}
int fd(int x) {
	return (x == fa[x]) ? x : fa[x] = fd(fa[x]) ; 
}
void inc(int x) {
	++ eg[x] ; 
	if( eg[x] == sz[x] * (sz[x] - 1) / 2 ) fl[x] = 1 ; 
}
void Dfs(int x){
	if( x <= n ) {
		L[x] = R[x] = ++ num ; return ; 
	}
	L[x] = n + 1 ; 
	for(int v : G[x]) {
		Dfs(v) ; 
		L[x] = min( L[x], L[v] ) ;
	}
	R[x] = num ;
	if( fl[x] ) rr[R[x]].pb(L[x]) ; 
}
signed main()
{
	n = gi() ; 
	rep( i, 1, n ) rep( j, 1, n ) a[i][j] = gi() ; 
	rep( i, 1, n ) for(int j = i + 1; j <= n; ++ j)
	e[++ cnt] = (E){ i, j, a[i][j] } ;
	sort(e + 1, e + cnt + 1, cmp) ; 
	rep( i, 1, n ) fl[i] = 1, rr[i].pb(i) ; 
	rep( i, 1, n ) fa[i] = i, sz[i] = 1, eg[i] = 0 ; 
	int idx = n ; 
	rep( i, 1, cnt ) {
		int x = e[i].fr, y = e[i].to ; 
		int u = fd(x), v = fd(y) ;
		if( u == v ) inc(u) ; 
		else {
			++ idx ; G[idx].pb(u), G[idx].pb(v) ; 
			fa[u] = idx, fa[v] = idx, fa[idx] = idx ; 
			sz[idx] = sz[u] + sz[v], 
			eg[idx] = eg[v] + eg[u], 
			inc(idx) ; 
		}
	}
	Dfs(idx) ;
	dp[0][0] = 1 ; 
	for(re int i = 1; i <= n; ++ i) {
		for(re int k = 1; k <= n; ++ k) {
			for(int v : rr[i])
			dp[i][k] = (dp[i][k] + dp[v - 1][k - 1]) % P ; 
		}
	}
	rep( i, 1, n ) printf("%lld ", dp[n][i] ) ; puts("") ; 
	return 0 ;
}