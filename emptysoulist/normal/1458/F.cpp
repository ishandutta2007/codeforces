#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define file(a) freopen(#a".in", "r", stdin), freopen(#a".out", "w", stdout)
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 2e5 + 5 ; 
struct E {
	int to, next ; 
} e[N << 1] ; 
int n, cnt, Ans, idx, head[N], dfn[N], L[N] ; 
int sz[N], dep[N], son[N], f[N], Top[N] ; 
void add(int x, int y) {
	e[++ cnt] = (E){ y, head[x] }, head[x] = cnt,
	e[++ cnt] = (E){ x, head[y] }, head[y] = cnt ; 
}
void dfs(int x, int fa) {
	dep[x] = dep[fa] + 1, f[x] = fa, sz[x] = 1 ; 
	Next( i, x ) {
		int v = e[i].to ; if(v == fa) continue ; 
		dfs(v, x), sz[x] += sz[v] ; 
		if(sz[v] >= sz[son[x]]) son[x] = v ; 
	}
}
void dfs2(int x, int high) {
	Top[x] = high, dfn[x] = ++ idx, L[idx] = x ; 
	if(son[x]) dfs2(son[x], high) ;
	Next( i, x ) {
		int v = e[i].to ; if(v == f[x] || v == son[x]) continue ; 
		dfs2(v, v) ; 
	} 
}
int LCA(int x, int y) {
	while(Top[x] != Top[y]) {
		if(dep[Top[x]] < dep[Top[y]]) swap(x, y) ; 
		x = f[Top[x]] ; 
	} return (dep[x] < dep[y]) ? x : y ; 
}
int Dis(int x, int y) { return dep[x] + dep[y] - 2 * dep[LCA(x, y)] ; }
int kth(int x, int k) {
	while(dep[x] - dep[Top[x]] < k) 
		k -= (dep[x] - dep[Top[x]] + 1), x = f[Top[x]] ; 
	return L[dfn[x] - k] ; 
} 
int find(int u, int v, int k) {
	int lca = LCA(u, v) ; 
	if(k <= dep[u] - dep[lca]) return kth(u, k) ;
	else return kth(v, Dis(u, v) - k) ;
}
struct node {
	int id, r ; 
	node(int _id = 0, int _r = 0) { id = _id, r = _r ; }
} nxt[N], pre[N] ;
int g[N] ; 
node operator + (node x, node y) {
	node ans = node(0, 0) ; 
	int dist = Dis(x.id, y.id) ; 
	if(dist + x.r <= y.r) return y ; 
	if(dist + y.r <= x.r) return x ; 
	ans.r = (x.r + y.r + dist) / 2 ; 
	ans.id = find(x.id, y.id, ans.r - x.r) ; 
	return ans ; 
}
bool sub(node x, node y) { // x in y ? or not
	int dist = Dis(x.id, y.id) ; 
	return (dist + x.r <= y.r) ; 
}
namespace DFZ {
	int dis[N][20], Sum, root, vis[N] ; 
	int w[N], sum[N], sumf[N], fth[N], dp[N] ; 
	void getrt(int x, int fa) {
		sz[x] = 1, dp[x] = 0 ; 
		Next( i, x ) {
			int v = e[i].to ; if(v == fa || vis[v]) continue ; 
			getrt(v, x), sz[x] += sz[v], dp[x] = max(dp[x], sz[v]) ; 
		} dp[x] = max(dp[x], Sum - sz[x]) ; 
		if(dp[x] <= dp[root]) root = x ; 
	}
	void Getd(int x, int fa) {
		sz[x] = 1 ; 
		Next( i, x ) {
			int v = e[i].to ; if(v == fa || vis[v]) continue ; 
			sz[x] += sz[v] ; 
		}
	}
	void solve(int x, int ft) {
		fth[x] = ft, vis[x] = 1, Getd(x, x) ;
		Next( i, x ) {
			int v = e[i].to ; if(vis[v]) continue ; 
			dp[root = 0] = Sum = sz[v], getrt(v, v) ; 
			solve(root, x) ;
		}
		int d = 1, u = fth[x] ; 
		while(u) dis[x][d] = Dis(x, u), ++ d, u = fth[u] ; 
	}
	void update(int x, int k) {
		int d = 1, u = fth[x], bef = x ; 
		while(u) {
			int di = dis[x][d] ; 
			w[u] += k, sum[u] += k * di, sumf[bef] += k * di,
			++ d, bef = u, u = fth[u] ; 
		} w[x] += k ; 
	}
	int query(int x) {
		int d = 1, u = fth[x], bef = x, ans = sum[x] ; 
		while(u) {
			int di = dis[x][d] ; 
			ans += sum[u] - sumf[bef], ans += (w[u] - w[bef]) * di, 
			++ d, bef = u, u = fth[u] ; 
		} return ans ; 
	}
	void build() {
		dfs(1, 1), dfs2(1, 1) ; 
		dp[0] = Sum = 2 * n + 1 ; 
		getrt(1, 1), solve(root, 0) ; 
	}
}
void solve(int l, int r) {
	if(l == r) return ; 
	int mid = (l + r) >> 1 ; g[mid] = 0 ; 
	pre[mid] = node(mid, 0), nxt[mid + 1] = node(mid + 1, 0) ; 
	for(re int i = mid - 1; i >= l; -- i)
	pre[i] = node(i, 0), pre[i] = pre[i] + pre[i + 1] ; 
	for(re int i = mid + 2; i <= r; ++ i)
	nxt[i] = node(i, 0), nxt[i] = nxt[i] + nxt[i - 1] ; 
	for(re int i = mid + 1; i <= r; ++ i) g[i] = g[i - 1] + nxt[i].r ; 
	int ans = 0, ll = mid + 1, rr = mid + 1 ; 
	for(re int i = mid; i >= l; -- i) {
		while(rr <= r && !sub(pre[i], nxt[rr])) //rr is the first element j, prei in nxtj
			DFZ::update(nxt[rr].id,  1), ++ rr ;
		while(ll < rr && sub(nxt[ll], pre[i])) //ll is the first element j, not in prei
			DFZ::update(nxt[ll].id, -1), ++ ll ; 
		ans += g[r] - g[rr - 1] ; 
		ans += (ll - 1 - mid) * pre[i].r ;
		ans += (DFZ::query(pre[i].id) + (g[rr - 1] - g[ll - 1]) + (rr - ll) * pre[i].r) / 2 ; 
	}
	while(ll < rr) DFZ::update(nxt[ll].id, -1), ++ ll ; 
	Ans += ans, solve(l, mid), solve(mid + 1, r) ; 
}
signed main()
{
	n = gi() ; int x, y ; 
	rep( i, 2, n ) x = gi(), y = gi(), add(x, n + i), add(n + i, y) ; 
	DFZ::build(), solve(1, n) ; 
	cout << Ans << endl ; 
	return 0 ;
}