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
const int inf = 1e9 + 7 ; 
const int M = 100 + 5 ; 
const int N = 1e5 + 5 ; 
struct E {
	int to, next, w, f ; 
} e[N << 1] ; 
int n, Ans, Num, cnt, S, T, A[M][M], deg[N], vis[N], mark[N], head[N], cur[N], dis[N] ; 
int C2(int x) { return x * (x - 1) / 2 ; }
void add( int x, int y, int z, int f ) {
	e[++ cnt] = (E){ y, head[x], z, f }, head[x] = cnt,
	e[++ cnt] = (E){ x, head[y], 0, -f }, head[y] = cnt ; 
}
queue<int> q ; 
int spfa() {
	rep( i, S, T ) dis[i] = inf, vis[i] = 0 ; q.push(S), vis[S] = 1, dis[S] = 0 ; 
	while( !q.empty() ) {
		int u = q.front() ; q.pop() ; vis[u] = 0 ; 
		Next( i, u ) {
			int v = e[i].to ; 
			if( dis[v] > dis[u] + e[i].f && e[i].w ) {
				dis[v] = dis[u] + e[i].f ; 
				if( !vis[v] ) q.push(v), vis[v] = 1 ; 
			}
		}
	} return ( dis[T] < inf ) ; 
}
int dfs(int x, int dist) {
	mark[x] = 1 ; if( x == T ) return dist ; int flow = 0 ; 
	for( re int &i = cur[x]; i; i = e[i].next ) {
		int v = e[i].to ; 
		if( dis[v] == dis[x] + e[i].f && e[i].w && !mark[v] ) {
			int di = dfs(v, min(dist, e[i].w) ) ;
			e[i].w -= di, e[i ^ 1].w += di, dist -= di, flow += di ; 
			Ans += di * e[i].f ; if( !dist ) break ; 
		}
	} return flow ; 
}
void zkwflow() {
	while( spfa() ) {
		rep( i, S, T ) cur[i] = head[i] ; mark[T] = 1 ; 
		while( mark[T] ) { rep( i, S, T ) mark[i] = 0 ; dfs( S, inf ) ; } 
	} 
}
int Id( int x, int y ) { return (x - 1) * n + y ; } 
int Id2( int x ) { return x + n * n + 1 ; }
signed main()
{
	n = gi(), Num = n * (n - 1) * (n - 2) / 6 ; int m = gi() ; 
	S = 0, T = n * n + n + 10, cnt = 1 ; 
	rep( i, 1, n ) rep( j, 1, n ) A[i][j] = 2 ; 
	rep( i, 1, n ) A[i][i] = 0 ;
	rep( i, 1, m ) {
		int x = gi(), y = gi() ; 
		A[x][y] = 1, A[y][x] = 0 ; 
	}
	rep( i, 1, n ) rep( j, 1, n ) {
		if( A[i][j] == 1 ) ++ deg[i] ; 
		if( A[i][j] == 2 && (i < j) ) 
			add(S, Id(i, j), 1, 0), add(Id(i, j), Id2(i), 1, 0 ), add(Id(i, j), Id2(j), 1, 0) ; 
	}
	rep( i, 1, n ) {
		Num -= C2(deg[i]) ; 
		for( re int j = deg[i]; j < n; ++ j ) add(Id2(i), T, 1, j) ; 
	} zkwflow() ; 
	rep( i, 1, n ) rep( j, 1, n ) {
		if( A[i][j] == 2 && (i < j) ) {
			int u = Id(i, j), win = 0 ;
			Next( i, u ) {
				int v = e[i].to ; if( v == S ) continue ;
				if( !e[i].w ) {	win = v - n * n - 1 ; break ; }
			}
			if( win == i ) A[i][j] = 1, A[j][i] = 0 ; 
			else A[j][i] = 1, A[i][j] = 0 ; 
		}
	}
	rep( i, 1, n ) {
		rep( j, 1, n ) printf("%d", A[i][j] ) ; puts("") ; 
	}
	return 0 ;
}