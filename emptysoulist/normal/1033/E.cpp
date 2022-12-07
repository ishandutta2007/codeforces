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
const int N = 2005 ; 
int n, num, cnt, go[N], fa[N] ; 
struct node {
	int x, y ; 
} p[N] ; 
vector<int> G[N] ; 
int fd(int x) { return (fa[x] == x) ? x : fa[x] = fd(fa[x]) ; }
void Merge(int x, int y) { int u = fd(x), v = fd(y) ; fa[u] = v ; }
void merge(int x, int y) { 
	int u = fd(x), v = fd(y) ; 
	if(u != v) 
		-- cnt, p[++ num] = (node){x, y}, fa[u] = v,
		Merge(x + 2 * n, y + n), Merge(x + n, y + 2 * n) ; 
}
int a[N][N] ; 
int Query(vi S) {
	if(S.empty()) return 0 ; 
	printf("? %d\n", (int)S.size()) ; int tot = 0 ; 
	for(int v : S) printf("%d ", v) ; puts("") ; cout.flush() ; 
	tot = gi() ; 
	return tot ; 
}
int check(vi S, int k) {
	int tot = Query(S) ; S.pb(k) ; 
	int rot = Query(S) ; return rot - tot ; 
} 
void link(int x, int y) { G[x].pb(y), G[y].pb(x) ; }
int Fat[N] ; 
void DFS(int x, int Fa) {
	Fat[x] = Fa ; 
	for(int v : G[x]) if(v ^ Fa) DFS(v, x) ; 
}
void solve(vi S) {
	rep( i, 1, num ) link(p[i].x, p[i].y) ; 
	int l = 1, r = S.size(), L = 1, R = 1 ; vi f ; 
	while(l <= r) {
		int mid = (l + r) >> 1 ; f.clear() ; 
		for(int j = 1; j <= mid; ++ j) f.pb(S[j - 1]) ; 
		if(Query(f)) R = mid, r = mid - 1 ; 
		else l = mid + 1 ; 
	}
	l = 1, r = R - 1 ; 
	while(l <= r) {
		int mid = (l + r) >> 1 ; f.clear() ; 
		for(int j = mid; j <= R; ++ j) f.pb(S[j - 1]) ; 
		if(Query(f)) L = mid, l = mid + 1 ; 
		else r = mid - 1 ; 
	} 
	DFS(S[L - 1], S[L - 1]) ; 
	vector<int> ans ; int u = S[R - 1], v = S[L - 1] ; 
	while(u != v) {
		ans.pb(u), u = Fat[u] ; 
	} ans.pb(v) ; 
	printf("N %d\n", (int)ans.size()) ; 
	for(int o : ans) printf("%d ", o ) ; 
	exit(0) ; 
}
int Find(vector<int> F, int x) {
	int l = 1, r = F.size(), ans = 0 ; 
	while(l <= r) {
		int mid = (l + r) >> 1 ; 
		vector<int> ff ; ff.clear() ; 
		rep( j, 1, mid ) ff.pb(F[j - 1]) ; 
		if(check(ff, x)) ans = mid, r = mid - 1 ; 
		else l = mid + 1 ; 
	} 
	if(!ans) return 0 ; 
	return F[ans - 1] ; 
}
int vis[N] ; 
void dfs(int x) {
	vis[x] = 1 ; vector<int> F ; 
	while(1) {
		F.clear() ; 
		for(int i = 1; i <= n; ++ i) if(!vis[i]) F.pb(i) ; 
		if(F.empty()) break ; 
		go[x] = Find(F, x) ; 
		if(go[x]) merge(x, go[x]), dfs(go[x]) ; 
		else break ; 
	}
}
signed main() 
{
	n = gi(), cnt = n ; 
	rep( i, 1, 3 * n ) fa[i] = i ; 
	dfs(1) ; 
	int B = fd(1 + n) ; 
	vector<int> b, w ; 
	rep( i, 1, n ) 
		if(fd(i + n) == B) b.pb(i) ; 
		else w.pb(i) ; 
	int BB = Query(b), WW = Query(w) ; 
	if(BB) solve(b) ; 
	if(WW) solve(w) ; 
	printf("Y ") ; printf("%d\n", (int)b.size()) ;
	for(int v : b) printf("%d ", v) ; puts("") ; 
	return 0 ; 
}