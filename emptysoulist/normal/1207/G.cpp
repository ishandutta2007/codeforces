#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define pb push_back
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 8e5 + 5 ; 
struct AC {
	int fail, ch[27], go[27] ; 
} t[N] ; 
int n, m, Id[N], Q[N], ans[N], L[N], R[N], fa[N], cnt ; 
queue<int> q ; vector<int> G[N], W[N] ; 
string s[N] ; 
void add( int x, int y ) { G[x].pb(y) ; }
void Bfs() {
	int u = 1 ; 
	rep(i, 0, 25) if(t[0].ch[i]) q.push(t[0].ch[i]) ; 
	while( !q.empty() ) {
		int u = q.front() ; q.pop() ; add(t[u].fail, u) ; 
		rep( i, 0, 25 ) {
			int x = t[u].ch[i] ; 
			if( x ) t[x].fail = t[t[u].fail].ch[i], q.push(x) ; 
			else t[u].ch[i] = t[t[u].fail].ch[i] ; 
		}
	}
}
int tree[N], idx ; 
void Add( int x, int k ) { for( re int i = x; i <= idx; i += (i & (-i)) ) tree[i] += k ; }
int qry(int x) { int sum = 0 ; for( re int i = x; i; i -= (i & (-i)) ) sum += tree[i] ; return sum ; }
void dfs( int x ) { L[x] = ++ idx ; for( int u : G[x] ) dfs(u) ; R[x] = idx ; }
void Dfs( int x ) {
//	printf("Dfs %d [%d %d]\n", x, L[x], R[x] ) ; 
	if( x ) Add( L[x], 1 ) ; 
	for(int i : W[x]) ans[i] = qry(R[Q[i]]) - qry(L[Q[i]] - 1) ;// printf("%d %d [%d %d] %d\n", i, Q[i], L[Q[i]], R[Q[i]], ans[i] ); 
	rep( i, 0, 25 ) if( t[x].go[i] ) Dfs(t[x].go[i]) ; 
	if( x ) Add( L[x], -1 ) ;
}
signed main()
{
	n = gi() ; int opt, u ; char c ; Id[0] = 0 ; 
	rep( i, 1, n ) {
		opt = gi() ; 
		if( opt == 1 ) {
			c = getchar() - 'a' ;
			if( !t[0].ch[c] ) t[0].ch[c] = ++ cnt, Id[i] = cnt ; 
			else Id[i] = t[0].ch[c] ; 
		}
		else {
			u = Id[gi()], c = getchar() - 'a' ;
//			printf("insert %d %c\n", u, c + 'a' ) ;
			if( !t[u].ch[c] ) t[u].ch[c] = ++ cnt, Id[i] = cnt ; 
			else Id[i] = t[u].ch[c] ; 
		}
//		printf("Pass %d %d\n", i, Id[i] ) ; 
	}
	rep( i, 0, cnt ) rep( j, 0, 25 ) t[i].go[j] = t[i].ch[j] ; 
	m = gi() ; 
	rep( i, 1, m ) {
		opt = gi(), cin >> s[i], W[Id[opt]].pb(i) ; 
		int u = 0 ; 
		for(int j = 0; j < s[i].size(); ++ j) {
			int x = s[i][j] - 'a' ; 
			if(!t[u].ch[x]) t[u].ch[x] = ++ cnt ; 
			u = t[u].ch[x] ; 
		} Q[i] = u ; 
	//	printf("%d %d\n", i, Q[i] ) ; 
	}
//	printf("TAT %d\n", t[0].ch[0] ) ; 
	Bfs(), dfs(0) ; 
//	printf("TAT %d\n", t[0].ch[0] ) ; 
	Dfs(0) ; 
	rep( i, 1, m ) printf("%d\n", ans[i] ) ; 
	return 0 ;
}