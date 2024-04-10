#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define mp make_pair
#define pi pair<int, int>
#define pb push_back
#define vi vector<int>
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int inf = 1e15 ; 
const int N = 2e5 + 5 ; 
int n, q, p[N], a[N], b[N], fa[N], st[N], top, ls[N] ; 
int d[N], dep[N], f[N][20], ans[N], col[N], sum[N], Rev[N] ; 
int ans2[N], beg[N], Mi[N] ; 
int Get(int x, int y) { return ans[x] - ans[y] ; }
int Get2(int x, int y) { return ans2[x] - ans2[y] ; }
int GetId(int x, int depth) {
	drep( i, 0, 18 ) if(dep[f[x][i]] >= depth) x = f[x][i] ; 
	return x ; 
}
int LCA(int x, int y) {
	if(dep[x] < dep[y]) swap(x, y) ; 
	drep( i, 0, 18 ) if(dep[f[x][i]] >= dep[y]) x = f[x][i] ; 
	drep( i, 0, 18 ) if(f[x][i] != f[y][i]) x = f[x][i], y = f[y][i] ;
	return (x == y) ? x : f[x][0] ; 
}
set<int> S ; 
set<int>::iterator it ; 
vector<int> G[N] ; 
long long NUM ; 
int DIS(int x, int y) {
	if(x > y) swap(x, y) ; int lca = LCA(x, y) ; 
	if(lca == y) return Get(x, y) ; 
	int u = GetId(x, dep[lca] + 1), v = GetId(y, dep[lca] + 1) ; 
	if(u > v) swap(u, v), swap(x, y) ;
	int ret = Get(x, u) + Rev[v] - sum[u] + Get2(y, v) + a[ls[v]] + Get(Mi[y], y) ;
	return ret ; 
}
void DFS(int x) {
	Mi[x] = x ; 
	for(int v : G[x]) DFS(v), Mi[x] = min(Mi[x], Mi[v]) ; 
}
signed main()
{
	n = gi(), q = gi() ; 
	rep( i, 1, n ) p[i] = gi() ; 
	rep( i, 1, n ) a[i] = gi() ; 
	rep( i, 1, n ) b[i] = gi() ; 
	p[n + 1] = n + 1, st[++ top] = n + 1, dep[n + 1] = 1 ; 
	for(int i = n; i >= 1; -- i) {
		while(p[i] > p[st[top]]) -- top ; 
		fa[i] = st[top], G[st[top]].pb(i), dep[i] = dep[fa[i]] + 1 ; 
		d[i] = min(b[i], a[i] + Get(i + 1, fa[i])) ; 
		ans[i] = d[i], f[i][0] = fa[i] ; 
		rep( j, 1, 18 ) f[i][j] = f[f[i][j - 1]][j - 1] ;
		ans[i] += ans[fa[i]], st[++ top] = i ; 
	}
	for(int i = n + 1; i >= 1; -- i) {
		sort(G[i].begin(), G[i].end()) ; int bef = 0 ; 
		for(int v : G[i]) {
			if(!bef) sum[v] = 0, beg[i] = v ; 
			else 
				sum[v] = sum[bef] + a[bef] + Get(bef + 1, v),
				Rev[v] = sum[bef], ls[v] = bef ; 
			bef = v ; 
		}
	} DFS(n + 1) ; 
	for(int i = n; i >= 1; -- i) {
		int ll = Mi[fa[i]], rr = Mi[i] ; 
		int u = GetId(ll, dep[i]) ; 
		if(i == beg[fa[i]]) ans2[i] = 0 ; 
		else ans2[i] = Get(ll, u) + Rev[i] - sum[u] + a[ls[i]] ; 
		ans2[i] += ans2[fa[i]] ; 
	} S.insert(1), S.insert(n + 1), NUM = Get(1, n + 1) ; 
	while(q--) {
		int x = gi() ; col[x] ^= 1 ;
		if(x == 1) printf("%lld\n", NUM) ; 
		else {
			if(!col[x]) S.erase(x) ; 
			int las = 0, nxt = 0 ; 
			it = S.upper_bound(x), nxt = *it, -- it, las = *it ;  
			if(col[x]) NUM -= DIS(las, nxt), NUM += DIS(las, x), NUM += DIS(x, nxt), S.insert(x) ; 
			else NUM += DIS(las, nxt), NUM -= DIS(las, x), NUM -= DIS(x, nxt) ; 
			printf("%lld\n", NUM) ; 
		}
	}
	return 0 ;
}