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
const int inf = 1e9 + 7 ; 
const int N = 7000 + 5 ; 
int n, m, h, Ans, S, T, idx, cnt, head[N] ;
int dep[N], cur[N], vis[N] ; 
struct E {
	int to, next, w ; 
} e[N << 1] ; 
void add(int x, int y, int z) {
	e[++ cnt] = (E){ y, head[x], z }, head[x] = cnt,
	e[++ cnt] = (E){ x, head[y], 0 }, head[y] = cnt ; 
}
queue<int> q ; 
int Id(int x, int y) { return y * n + x ; }
bool bfs() {
	rep( i, S, T ) dep[i] = 0 ; dep[S] = 1, q.push(S) ; 
	while(!q.empty()) {
		int u = q.front() ; q.pop() ; 
		Next( i, u ) {
			int v = e[i].to ; 
			if(!dep[v] && e[i].w) 
			dep[v] = dep[u] + 1, q.push(v) ; 
		}
	} return (dep[T] != 0) ;
}
int dfs(int x, int dist) {
	if( x == T ) return dist ; int flow = 0 ; 
	for( int &i = cur[x]; i; i = e[i].next ) {
		int v = e[i].to ; 
		if( (dep[v] == dep[x] + 1) && e[i].w ) {
			int di = dfs(v, min(dist, e[i].w)) ;
			e[i].w -= di, e[i ^ 1].w += di, flow += di, dist -= di ;
			if(!dist) return flow ; 
		}
	} return flow ; 
}
int min_cut() {
	int ans = 0 ; 
	while( bfs() ) {
		memcpy(cur, head, sizeof(head)) ;
		while(int di = dfs(S, inf)) ans += di ; 
	} return ans ; 
}
signed main()
{
	n = gi(), h = gi(), m = gi(), Ans = n * h * h ; 
	idx = n * (h + 1), S = 0, T = idx + m + 10, cnt = 1 ; 
	rep( i, 1, n ) rep( j, 1, h ) 
		add(Id(i, j), Id(i, j - 1), inf), add(S, Id(i, j), 2 * j - 1) ; 
	int l, r, x, c ; 
	rep( i, 1, m ) {
		l = gi(), r = gi(), x = gi() + 1, c = gi() ; 
		if( x > h ) continue ; 
		rep( j, l, r ) add(Id(j, x), idx + i, inf) ;
		add(idx + i, T, c) ; 
	}
	Ans -= min_cut() ; 
	cout << Ans << endl ; 
	return 0 ;
}