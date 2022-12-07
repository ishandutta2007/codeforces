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
const int N = 2e5 + 5 ; 
struct AC { int ch[27], fail ; } t[N] ; 
struct node {  int l, x, id, type ; } p[N] ;
int n, Q, num, maxn, cnt, kss, idx, vis[N], L[N], R[N], tree[N], Ans[N], Pos[N] ; 
string s[N] ; queue<int> q ; vector<int> G[N] ; vector<node> pos[N], Id[N] ; 
void Add( int x, int k ) { for( re int i = x; i <= maxn; i += (i & (-i)) ) tree[i] += k ; }
int qry(int x) { int sum = 0 ; for( re int i = x; i; i -= (i & (-i)) ) sum += tree[i] ; return sum ; }
void add( int x, int y ) { G[x].pb(y) ; }
void insert( int id, string c ) {
	int u = 0, x ; 
	for( re int i = 0; i < c.size(); ++ i ) {
		x = c[i] - 'a' ; if( !t[u].ch[x] ) t[u].ch[x] = ++ cnt ; 
		u = t[u].ch[x] ; 
	} Pos[id] = u ; 
}
void Bfs() {
	rep( i, 0, 25 ) if( t[0].ch[i] ) q.push(t[0].ch[i]) ; 
	while( !q.empty() ) {
		int u = q.front() ; q.pop(), add( t[u].fail, u ) ; 
		rep( i, 0, 25 ) {
			int x = t[u].ch[i] ;
			if( !x ) t[u].ch[i] = t[t[u].fail].ch[i] ;
			else t[x].fail = t[t[u].fail].ch[i], q.push(x) ; 
		}
	}
}
void Dfs( int x ) { 
	L[x] = ++ idx ; 
	for( int v : G[x] ) Dfs(v) ; 
	R[x] = idx ; 
}
void solve( int x ) {
	int u = 0 ; 
	for( re int i = 0; i < s[x].size(); ++ i ) 
		u = t[u].ch[s[x][i] - 'a'], Add( L[u], 1 ) ; 
	u = 0 ; int sum = 0 ; 
	for( auto i : pos[x] ) Id[i.l].pb(i) ;
	rep( i, 1, n ) {
		sum += ( qry(R[Pos[i]]) - qry(L[Pos[i]] - 1) ) ;
		for( auto j : Id[i] ) Ans[j.id] += j.type * sum ; 
	}
	rep( i, 0, n ) Id[i].clear() ; 
	for( re int i = 0; i < s[x].size(); ++ i ) 
		u = t[u].ch[s[x][i] - 'a'], Add( L[u], -1 ) ; 
}
int Go( int x ) {
	int u = 0, sum = 0 ;
	for( re int i = 0; i < s[x].size(); ++ i ) {
		int c = s[x][i] - 'a' ; 
		u = t[u].ch[c], sum += qry(L[u]) ; 
	} return sum ; 
}
signed main()
{
	n = gi(), Q = gi(), num = 400 ; 
	rep( i, 1, n ) {
		cin >> s[i] ; 
		int len = s[i].size() ; 
		if( len >= num ) vis[i] = 1 ; 
		insert(i, s[i]) ; 
	} Bfs(), Dfs(0) ; maxn = cnt + 5 ; int x, y, z ; 
	rep( i, 1, Q ) {
		x = gi(), y = gi(), z = gi() ; 
		if( !vis[z] ) p[++ kss] = (node){x - 1, z, i, -1}, p[++ kss] = (node){y, z, i, 1} ; 
		else pos[z].pb((node){x - 1, z, i, -1}), pos[z].pb((node){y, z, i, 1}) ;
	}
	rep( i, 1, n ) if( vis[i] ) solve(i) ; 
	rep( i, 1, kss ) Id[p[i].l].pb(p[i]) ; 
	rep( i, 1, n ) {
		Add(L[Pos[i]], 1), Add(R[Pos[i]] + 1, -1) ; 
		for( auto j : Id[i] ) Ans[j.id] += j.type * Go(j.x) ; 
	}
	rep( i, 1, Q ) printf("%lld\n", Ans[i] ) ; 
	return 0 ;
}