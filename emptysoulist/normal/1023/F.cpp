#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( int i = (t); i >= (s); -- i )
#define mp make_pair
#define pi pair<int, int>
#define pb push_back
#define vi vector<int>
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 5e5 + 5 ; 
int n, cnt, m1, m2, g[N], go[N][20], dep[N], fa[N] ; 
struct E {
	int x, y, z ; 
} e[N << 1], s[N << 1] ;
struct node {
	int id, w ; 
} ; 
vector<node> G[N] ; 
void add(int x, int y, int z) {
	G[x].pb((node){y, z}), G[y].pb((node){x, z}) ; 
}
int fd(int x) {
	return (fa[x] == x) ? x : fa[x] = fd(fa[x]) ; 
}
bool cmp(E x, E y) {
	return x.z < y.z ; 
}
void dfs(int x, int ff) {
	dep[x] = dep[ff] + 1, go[x][0] = ff ; 
	rep( i, 1, 18 ) go[x][i] = go[go[x][i - 1]][i - 1] ; 
	for(auto v : G[x]) {
		if(v.id == ff) continue ; 
		dfs(v.id, x) ; 
		if(!v.w) g[v.id] = 1 ; 
	}
}
int LCA(int x, int y) {
	if(dep[x] < dep[y]) swap(x, y) ;  
	drep( i, 0, 18 ) if(dep[go[x][i]] >= dep[y]) x = go[x][i] ;
	drep( i, 0, 18 ) if(go[x][i] != go[y][i]) x = go[x][i], y = go[y][i] ; 
	return (x == y) ? x : go[x][0] ; 
}
signed main()
{
	n = gi(), m1 = gi(), m2 = gi() ; 
	rep( i, 1, m1 ) e[i].x = gi(), e[i].y = gi() ; 
	rep( i, 1, m2 ) s[i].x = gi(), s[i].y = gi(), s[i].z = gi() ; 
	rep( i, 1, n ) fa[i] = i ; 
	sort(s + 1, s + m2 + 1, cmp) ; 
	rep( i, 1, m1 ) {
		int u = fd(e[i].x), v = fd(e[i].y) ;
		if(u != v) {
			fa[u] = v ; 
			add(e[i].x, e[i].y, 0) ; 
		}
	}
	rep( i, 1, m2 ) { 
		int u = fd(s[i].x), v = fd(s[i].y) ;
		if(u != v) {
			fa[u] = v ; 
			add(s[i].x, s[i].y, s[i].z) ; 
			s[i].z = 0 ; 
		}
	}
	dfs(1, 1) ; 
	int num = 0 ; 
	long long ans = 0 ; 
	rep( i, 1, n ) fa[i] = i ; 
	rep( i, 1, m2 ) {
		if(!s[i].z) continue ; 
		int u = fd(s[i].x), v = fd(s[i].y) ; 
		int d = fd(LCA(s[i].x, s[i].y)) ; 
		while(u != v) {
			if(dep[u] < dep[v]) swap(u, v) ; 
			u = fd(u) ;
			if(g[u]) ans += s[i].z, ++ num ; 
			int bef = u ; 
			u = fd(go[u][0]) ; 
			fa[bef] = d ; 
		}
	}
	if(num < m1) {
		puts("-1") ; 
	}
	else cout << ans << endl ; 
	return 0 ;
}