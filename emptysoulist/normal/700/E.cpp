#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( int i = (t); i >= (s); -- i )
#define mp make_pair
#define pi pair<int, int>
#define pb push_back
#define vi vector<int>
const int N = 8e5 + 5 ; 
int n, m, A[N] ; 
char ch[N] ; 
struct SAM {
	int son[N][26], par[N], len[N], cnt, lst;
	void init() { lst = cnt = 1; }
	int rt[N], cn, ls[N * 10], rs[N * 10], T[N * 10] ; 
	void add( int& rt, int l, int r, int p ) {
		if( !rt ) rt = ++ cn ; ++ T[rt] ;
		if( l == r ) return;
		int m = l + r >> 1 ;
		if( p <= m ) add( ls[rt], l, m, p ) ;
		else add( rs[rt], m + 1, r, p ) ; 
	}
	vi G[N] ;
	void addall() { rep( i, 2, cnt ) G[par[i]].pb(i) ; }
	void ins(int x, int i) {
		int cur = ++ cnt, p = lst ;
		len[cur] = len[lst] + 1 ;
		while( p && !son[p][x] ) son[p][x] = cur, p = par[p] ;
		if(!p) par[cur] = 1 ;
		else {
			int q = son[p][x] ;
			if( len[q] == len[p] + 1 ) par[cur] = q ;
			else {
				int ct = ++ cnt ;
				len[ct] = len[p] + 1, par[ct] = par[q] ; 
				memcpy( son[ct], son[q], sizeof(son[ct]) ) ;
				par[q] = par[cur] = ct ;
				for(; son[p][x] == q; p = par[p]) son[p][x] = ct ;
			}
		} lst = cur, add( rt[cur], 1, n, i) ;
	}
	int merge( int u, int v, int l, int r ) {
		if( !u || !v ) return u + v ;
		int cur = ++ cn , m = l + r >> 1 ; T[cur] = T[u] + T[v] ;
		if( l == r ) return cur ;
		ls[cur] = merge( ls[u], ls[v], l, m ), rs[cur] = merge( rs[u], rs[v], m + 1, r ) ;
		return cur ;
	}
	int que( int rt, int l, int r, int L, int R ) {
		if( !rt ) return 0 ; if( L <= l && R >= r ) return 1 ;
		int m = l + r >> 1 , ans = 0 ;
		if( L <= m ) ans |= que( ls[rt], l, m, L, R ) ;
		if( R > m ) ans |= que( rs[rt],  m + 1, r, L, R ) ;
		return ans ;
	}
	int yusland( int rt, int l, int r ) {
		if( l == r ) return l;
		int m = l + r >> 1 ;
		if( rs[rt] ) return yusland( rs[rt], m + 1, r ) ;
		if( ls[rt] ) return yusland( ls[rt], l, m ) ;
	}
	int g[N][20];
	void dfs(int u) {
		for( int v : G[u] ) {
			g[v][0] = u ;
			rep( k, 1, 18 ) 
			if( g[g[v][k - 1]][k - 1] ) g[v][k] = g[g[v][k - 1]][k - 1] ; 
			else break ;
			dfs(v), rt[u] = merge(rt[u], rt[v], 1, n) ;
		}
	}
	int jump( int u, int l, int r ) {
		for(int k = 18; k >= 0; -- k) {
			int v = g[u][k];
			if(!v || (l + len[v] - 1 <= r - 1 && que( rt[v], 1, n, l + len[v] - 1, r - 1 ))) 
				continue;
			u = g[u][k];
		} return par[u];
	}
	int dp[N], ans = 0 ;
	void sol(int u) {
		if( u != 1 ) {
			int ps = yusland( rt[u], 1, n ) , v = jump( u, ps - len[u] + 1, ps );
			dp[u] = dp[v] + 1;
		} ans = max(ans, dp[u]) ;
		for( int v : G[u] ) sol(v) ;
	}
} S ; 
signed main() {
    cin >> n, scanf("%s", ch + 1) ; 
	S.init();
	rep( i, 1, n ) S.ins( ch[i] - 'a' , i );
	S.addall(), S.dfs(1), S.sol(1) ;
	cout << S.ans << endl ;
}