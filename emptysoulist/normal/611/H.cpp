#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define vi vector<int>
#define pb push_back
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int inf = 1e9 + 7 ; 
const int N = 2e5 + 5 ; 
const int M = 100 + 5 ; 
int n, m, a[10], c[10][10], bg[10], fr[10] ; 
int Id(int x, int y) { return (x - 1) * m + y ; }
struct Max_Flow {
	struct E {
		int to, next, w ; 
	} e[M << 1] ;
	int cnt, S, T, dep[M], head[M], cur[M] ; 
	void add(int x, int y, int z) {
		e[++ cnt] = (E){ y, head[x], z }, head[x] = cnt,
		e[++ cnt] = (E){ x, head[y], 0 }, head[y] = cnt ; 
	}
	queue<int> q ; 
	bool bfs() {
		memset( dep, 0, sizeof(dep) ), q.push(S), dep[S] = 1 ; 
		while( !q.empty() ) {
			int u = q.front() ; q.pop() ; 
			Next( i, u ) {
				int v = e[i].to ; 
				if( !dep[v] && e[i].w ) 
				dep[v] = dep[u] + 1, q.push(v) ; 
			}
		} return (dep[T] != 0) ; 
	}
	int dfs(int x, int dist) {
		if( x == T ) return dist ; int flow = 0 ; 
		for(re int &i = cur[x]; i; i = e[i].next ) {
			int v = e[i].to ;
			if( (dep[v] == dep[x] + 1) && e[i].w ) {
				int di = dfs(v, min(dist, e[i].w)) ;
				e[i].w -= di, e[i ^ 1].w += di,
				flow += di, dist -= di ;
				if( !dist ) return flow ; 
			}
		} return flow ; 
	}
	int dinic() {
		int ans = 0 ;
		while(bfs()) {
			memcpy(cur, head, sizeof(head)) ;
			while(int di = dfs(S, inf)) ans += di ;
		} return ans ; 
	}
	void init() { memset( head, 0, sizeof(head) ), cnt = 1 ; }
	void out() {
		rep( x, 1, m ) {
			int u = m * m + x ; 
			Next( i, u ) {
				int v = e[i].to ; 
				if( !e[i].w || (v == T) ) continue ; 
				rep( j, 1, x ) if(((j - 1) * m + x) == v) 
				while( e[i].w ) printf("%d %d\n", fr[j], bg[x] ), ++ bg[x], -- e[i].w ; 
				rep( j, x + 1, m ) if(((x - 1) * m + j) == v)
				while( e[i].w ) printf("%d %d\n", fr[j], bg[x] ), ++ bg[x], -- e[i].w ; 
			}
		}
	}
} flow ; 
char s[M] ; 
int Num, b[M], vis[M], f[10][10] ; 
void dec(int x, int y) { -- f[x][y], -- f[y][x] ; }
void check() {
	rep( i, 1, m ) vis[i] = 0 ; 
	rep( i, 1, m ) rep( j, 1, m ) f[i][j] = c[i][j] ; 
	for( re int i = 1; i < m - 1; ++ i ) ++ vis[b[i]] ;
	for( re int j = 1; j < m - 1; ++ j ) 
		rep( k, 1, m ) if( vis[k] == 0 ) {
			dec( k, b[j] ), -- vis[k], -- vis[b[j]] ; 
			break ; 
		}
	rep( k, 1, m ) if( !vis[k] ) {
		rep( j, k + 1, m ) if( vis[j] == 0 ) { 
			dec( j, k ) ; break ; 
		} break ; 
	}
	rep( i, 1, m ) rep( j, i, m ) if( f[i][j] < 0 ) return ; 
	flow.init() ; int cost = 0 ; 
	flow.S = 0, flow.T = m * (m + 1) + 1 ; 
	rep( i, 1, m ) rep( j, i, m ) {
		flow.add(flow.S, Id(i, j), f[i][j]), cost += f[i][j] ; 
		flow.add(Id(i, j), i + m * m, inf) ;
		if( i != j ) flow.add(Id(i, j), j + m * m, inf) ; 
	}
	rep( i, 1, m ) flow.add(m * m + i, flow.T, a[i]) ; 
	int ans = flow.dinic() ; if( ans != cost ) return ; 
	flow.out() ; rep( i, 1, m ) rep( j, i, m ) 
		if( f[i][j] < c[i][j] ) printf("%d %d\n", fr[i], fr[j] ) ; 
	exit(0) ; 
}
void Dfs(int x) {
	if( (x == m - 1) || (m == 1) ) return check(), void() ; 
	rep( i, 1, m ) b[x] = i, Dfs(x + 1) ;
} 
signed main()
{
	n = gi() ; int x, y ; 
	rep( i, 2, n ) {
		scanf("%s", s + 1 ), x = strlen(s + 1) ;
		scanf("%s", s + 1 ), y = strlen(s + 1) ; 
		if( x > y ) swap( x, y ) ; ++ c[x][y] ;
	}
	int len = n, z = 1 ; 
	while( len ) len /= 10, ++ m ; 
	rep( i, 1, m ) a[i] = z * 9, bg[i] = z + 1, fr[i] = z, z = z * 10 ; 
	a[m] = (n - z / 10) + 1 ; rep( i, 1, m ) -- a[i] ; 
	Dfs(1), puts("-1") ; 
	return 0 ;
}