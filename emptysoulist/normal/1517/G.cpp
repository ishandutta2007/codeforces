#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 2e4 + 5 ;
const int inf = 1e15 + 5 ; 
int n, cnt, S, T, head[N], cur[N], dep[N] ; 
struct E { int to, next, w ; } e[N] ; 
void add( int x, int y, int z ) {
	e[++ cnt] = (E){ y, head[x], z }, head[x] = cnt,
	e[++ cnt] = (E){ x, head[y], 0 }, head[y] = cnt ; 
}
queue<int> q ; 
bool bfs() {
	memset(dep, 0, sizeof(dep)), q.push(S), dep[S] = 1 ; 
	while(!q.empty()) {
		int u = q.front() ; q.pop() ; 
		Next( i, u ) {
			int v = e[i].to ; 
			if(e[i].w && !dep[v]) 
			dep[v] = dep[u] + 1, q.push(v) ;
		}
	}
	return ( dep[T] != 0 ) ;
}
int dfs(int x, int dist) {
	if(x == T) return dist ; int flow = 0 ; 
	for(int &i = cur[x]; i; i = e[i].next) {
		int v = e[i].to ; 
		if( e[i].w && ( dep[v] == dep[x] + 1 ) ) {
			int d = dfs( v, min( dist, e[i].w ) ) ;
			flow += d, dist -= d, e[i].w -= d, e[i ^ 1].w += d ;
			if( dist == 0 ) break ; 
		}
	} return flow ; 
}
int dinic() {
	int ans = 0 ;
	while( bfs() ) {
		memcpy( cur, head, sizeof(head) ) ; int di = 1 ; 
		while( di = dfs( S, inf ) ) ans += di ;
	} return ans ; 
} 
struct node {
	int x, y, type ; 
} p[N] ;
signed main()
{
    n = gi(), cnt = 1, S = 0, T = 2 * n + 1 ; 
    int ANS = 0 ; 
    rep( i, 1, n ) {
		int x = gi(), y = gi(), z = gi() ; ANS += z ; 
		add(i, i + n, z) ; 
		int type = 0 ; 
		int d1 = (x % 2 + 2) % 2, d2 = (y % 2 + 2) % 2 ; 
		if((!d1) && (!d2)) type = 1 ; 
		if(d1 && (!d2)) type = 0 ; 
		if(d1 && d2) type = 3 ; 
		if((!d1) && d2) type = 2 ; 
		p[i] = (node){x, y, type} ;  
		if(type == 0) add(S, i, inf) ; 
		if(type == 3) add(i + n, T, inf) ; 
	} 
	rep( i, 1, n ) {
		rep( j, 1, n ) { 
			if(p[i].type != (p[j].type + 1)) continue ; 
			int d = max(abs(p[i].x - p[j].x), abs(p[i].y - p[j].y)) ; 
			if(d <= 1) add(j + n, i, inf) ; 
		}
	}
	int ans = dinic() ; 
	cout << ANS - ans << endl ; 
	return 0 ; 
}