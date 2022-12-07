#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int inf = 1e8 + 7 ; 
const int N = 1e4 + 5 ; 
const int K = (1 << 11) + 1 ; 
struct E {
	int to, next, w ; 
} e[N << 1], es[2][271][N << 1] ; 
struct S {
	int u, v, w ; 
} s[15] ; 
int n, m, tk, S = 1, T = n, cnt, D, Cnt[1025], Hd[1025][N], fr[N], ef[N] ;
int head[N], dep[N], cur[N], f[K], g[K], bit[K] ; 
queue<int> q ; 
int Id[K] ; 
void add(int x, int y, int z) {
	e[++ cnt] = (E){ y, head[x], z }, head[x] = cnt,
	e[++ cnt] = (E){ x, head[y], 0 }, head[y] = cnt ;
}
bool bfs() {
	rep(i, 1, n) dep[i] = 0 ; q.push(S), dep[S] = 1 ; 
	while( !q.empty() ) {
		int u = q.front() ; q.pop() ; 
		Next( i, u ) {
			int v = e[i].to ; 
			if( e[i].w && !dep[v] ) 
			dep[v] = dep[u] + 1, q.push(v) ; 
		}
	} return (dep[T] != 0) ; 
}
int dfs(int x, int dist) {
	if( x == T ) return dist ; int flow = 0 ; 
	for(int &i = cur[x]; i; i = e[i].next) {
		int v = e[i].to ; 
		if( e[i].w && (dep[v] == dep[x] + 1) ) {
			int di = dfs(v, min(e[i].w, dist)) ;
			dist -= di, flow += di, e[i].w -= di, e[i ^ 1].w += di ; 
			if( !dist ) break ;  
		}
	} return flow ; 
}
int dinic() {
	int ans = 0 ; 
	while(bfs()) {
		rep( i, 1, n ) cur[i] = head[i] ; 
		while(int di = dfs(S, inf)) ans += di ; 
	} return ans ; 
} int que[N] ; 
int Bfs() {
	rep(i, 1, n) dep[i] = 0 ; que[1] = S, dep[S] = 1 ; 
	for( register int he = 1, ed = 1; he <= ed; ++ he ) {
		int u = que[he] ; 
		for( register int i = head[u]; i; i = e[i].next ) {
			register int v = e[i].to ; 
			if( e[i].w && !dep[v] ) 
			dep[v] = dep[u] + 1, fr[v] = u, ef[v] = i, que[++ ed] = v ; 
			if( dep[T] ) break ; 
		}
	} if( !dep[T] ) return 0 ; 
	int mi = 25, u = T ; 
	while(u != S) mi = min( e[ef[u]].w, mi ), u = fr[u] ; u = T ; 
	while(u != S) e[ef[u]].w -= mi, e[ef[u] ^ 1].w += mi, u = fr[u] ; 
	return mi ; 
}
int Idx ; 
int Get_flow() {
	int ans = 0; 
	while(int di = Bfs()) ans += di, Idx ++ ; 
	return ans ; 
}
signed main()
{
	n = gi(), m = gi(), tk = gi(), D = gi() ; 
	int x, y, z ; cnt = 1 ; 
	rep( i, 1, tk ) s[i].u = gi(), s[i].v = gi(), s[i].w = gi() ; 
	for(re int i = tk + 1; i <= m; ++ i) 
		x = gi(), y = gi(), z = gi(), add(x, y, z) ; 
	S = 1, T = n, f[0] = dinic() ; 
	rep( j, 1, cnt ) es[0][0][j] = e[j] ; 
	rep( i, 1, n ) Hd[0][i] = head[i] ; 
	Cnt[0] = cnt ; int lim = (1 << tk) - 1 ; Id[0] = 0 ; 
	rep( k, 1, tk ) {
		int num = 0 ; 
		for(int i = 1; i <= lim; ++ i ) {
			if( (__builtin_popcountll(i)) != k ) continue ; 
			Id[i] = ++ num ; 
			rep( j, 1, tk ) if( (1 << (j - 1)) & i ) bit[i] = max(bit[i], j - 1) ; 
			int iS = (i ^ (1 << bit[i])), uf = bit[i] + 1 ; cnt = Cnt[iS] ; 
			rep( j, 1, cnt ) e[j] = es[(k & 1) ^ 1][Id[iS]][j] ; 
			rep( j, 1, n ) head[j] = Hd[iS][j] ;
			add(s[uf].u, s[uf].v, 25) ; 
			f[i] = Get_flow() + f[iS] ;
			rep( j, 1, n ) Hd[i][j] = head[j] ; Cnt[i] = cnt ; 
			rep( j, 1, cnt ) es[k & 1][num][j] = e[j] ; 
			rep( j, 1, cnt ) e[j] = es[0][269][j] ; 
		}
	}
	while( D-- ) {
		rep( i, 1, tk ) s[i].w = gi() ; g[0] = 0 ; int ans = inf ; 
		rep( i, 1, lim ) 
			g[i] = g[i ^ (1 << bit[i])] + s[bit[i] + 1].w ; 
		rep( i, 0, lim ) ans = min( ans, f[i] + g[i ^ lim] ) ; 
		printf("%d\n", ans ) ; 
	}
	return 0 ;
}