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
const int N = 3000 + 10;
int n, f[N][N], cnt, fa[N], head[N], sz[N], vis[N][N];
//qwq
struct E {
	int to, next ; 
} e[N << 1] ;
void add( int x, int y ) {
	e[++ cnt] = (E){ x, head[y] }, head[y] = cnt,
	e[++ cnt] = (E){ y, head[x] }, head[x] = cnt ;
}
struct node { int a, fa, b, fb ; } ;
queue<node> ZK ;
void dfs(int u) {
	sz[u] = 1 ;
 	Next( i, u ) {
 		int v = e[i].to ;
		if( v != fa[u] )
    	fa[v] = u, dfs(v), sz[u] += sz[v];
	}
}
int Sz( int x, int y ) { return (fa[x] == y) ? sz[x] : n - sz[y]; }
void pushback(int x, int fx, int y, int fy) {
	if( vis[x][y] ) return ;
	ZK.push({ x, fx, y, fy }) ;
	vis[x][y] = 1, vis[y][x] = 1;
}
void input() {
	n = gi() ;
	for( re int i = 1; i < n; ++ i ) {
	    int u = gi(), v = gi() ;
		add( u, v ), pushback(u, v, v, u);
	} dfs(1) ;
}
void doit() {
	while (ZK.size()) {
		int a = ZK.front().a, fa = ZK.front().fa;
    	int b = ZK.front().b, fb = ZK.front().fb; ZK.pop();
    	Next( i, a ) {
    		int v = e[i].to ;
    	  	if( v != fa ) {
    	    	f[b][v] = f[v][b] = max(f[v][b], f[a][b] + Sz(b, fb) * Sz(v, a)),
    	    	pushback(v, a, b, fb);
    		}
    	}
    	Next( k, b ) {
    		int v = e[k].to ;
			if( v != fb ) {
    	    	f[a][v] = f[v][a] = max(f[v][a], f[a][b] + Sz(a, fa) * Sz(v, b)),
    	    	pushback(v, b, a, fa);
			}
		}
	}
}
void solve() {
	rep( u, 1, n )
    	Next( i, u ) {
    		int v = e[i].to ;
			if( u < v ) 
			f[u][v] = f[v][u] = Sz(u, v) * Sz(v, u);
		}
}
void output() {
	int ans = 0 ;
	rep( i, 1, n ) rep( j, 1, n ) ans = max(ans, f[i][j]);
	printf("%I64d\n", ans ) ;
}
signed main() {
	input(), solve(), doit(), output() ;
	return 0;
}