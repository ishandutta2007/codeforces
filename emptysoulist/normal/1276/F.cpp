#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( int i = (t); i >= (s); -- i )
const int inf = 1e9 ; 
const int Inf = 1e8 ; 
const int N = 2e5 + 5 ; 
int n, rt[N] ; long long ans[N], Ans ; 
char sf[N], us[N] ; 
struct SuffixTree {
	struct SufTree { int lef, len, lk, ch[30] ; } t[N] ;
	int idx, M, cnt, Dep[N], dfn[N], Id[N], s[N], dep[N] ; 
	int fd[N], ind[N], f[N][20] ; long long F ; 
	int node(int l, int len) { ++ cnt, t[cnt].lef = l, t[cnt].len = len ; return cnt ; }
	void build(char *a, int l) {
		t[0].len = inf, M = l, a[++ l] = 'z' + 1 ; 
		rep( i, 1, l ) s[i] = a[i] - 'a' + 1 ; 
		cnt = 1 ; int rem = 0, m = 0, bef = 1 ; 
		rep( o, 1, l ) {
			int u = s[o], lst = 1 ; ++ m, ++ rem ; 
			while(rem) {
				while(rem > t[t[bef].ch[s[m - rem + 1]]].len )
				rem -= t[bef = t[bef].ch[s[m - rem + 1]]].len ; 
				int &d = t[bef].ch[s[m - rem + 1]], c = s[t[d].lef + rem - 1] ; 
				if(!d || u == c) {
					t[lst].lk = bef, lst = bef ; 
					if(!d) d = node(m - rem + 1, inf) ; 
					else break ;
				} else {
					int np = node(t[d].lef, rem - 1) ; 
					t[d].lef += (rem - 1), t[d].len -= (rem - 1),
					t[np].ch[c] = d, t[np].ch[u] = node(m, inf),
					t[lst].lk = d = np, lst = np ; 
				} (bef == 1) ? -- rem : bef = t[bef].lk ; 
			} 
		}
	}
	void clear() {
		rep( i, 1, cnt ) {
			Dep[i] = dep[i] = ind[i] = Id[i] = dfn[i] = 0 ;
			t[i].lef = t[i].len = t[i].lk = 0 ; 
			rep( j, 0, 17 ) f[i][j] = 0 ; 
			rep( j, 0, 27 ) t[i].ch[j] = 0 ; 
		} idx = cnt = F = 0 ; 
	}
	void DFS(int x, int fa) {
		f[x][0] = fa, dfn[x] = ++ idx, Dep[x] = Dep[fa] + 1, Id[idx] = x ; 
		rep( i, 1, 17 ) f[x][i] = f[f[x][i - 1]][i - 1] ; 
		if(t[x].len >= Inf) {
			t[x].len = M - t[x].lef + 1, dep[x] = dep[fa] + t[x].len ;
			F += t[x].len, fd[idx] = dep[x], ind[M - dep[x] + 1] = x ; return ;
		} dep[x] = dep[fa] + t[x].len, F += t[x].len, fd[idx] = dep[x] ; 
		rep( i, 1, 27 ) if(t[x].ch[i]) DFS(t[x].ch[i], x) ; 
	} 
	int LCA(int x, int y) {
		if(Dep[x] < Dep[y]) swap(x, y) ; 
		drep( i, 0, 17 ) if(Dep[f[x][i]] >= Dep[y]) x = f[x][i] ; 
		drep( i, 0, 17 ) if(f[x][i] != f[y][i]) x = f[x][i], y = f[y][i] ;
		return (x == y) ? x : f[x][0] ; 
	}
	int lca(int l1, int l2) { return dep[LCA(Id[l1], Id[l2])] ; }
} T1, uT ; 
set<int> S[N] ; set<int>::iterator it ; 
void merge(int x, int y) {
	if(S[rt[x]].empty() && S[rt[y]].empty()) return ; 
	if(S[rt[x]].size() < S[rt[y]].size()) swap(rt[x], rt[y]) ; 
	for(int v : S[rt[y]]) {
		it = S[rt[x]].lower_bound(v) ; int nxt = 0, pre = 0 ; 
		if(it != S[rt[x]].end()) nxt = (*it), ans[rt[x]] -= uT.lca(v, nxt) ; 
		if(it != S[rt[x]].begin()) -- it, pre = (*it), ans[rt[x]] -= uT.lca(v, pre) ; 
		if(pre && nxt) ans[rt[x]] += uT.lca(pre, nxt) ; 
		S[rt[x]].insert(v), ans[rt[x]] += uT.fd[v] ; 
	} 
}
void solve(int x) {
	int flag = 0, d = T1.dep[x] ; 
	rep( i, 1, 27 ) if(T1.t[x].ch[i]) 
		solve(T1.t[x].ch[i]), flag = 1, merge(x, T1.t[x].ch[i]) ; 
	if(!flag && (d <= n - 2) && (d > 0))
		S[x].insert(uT.dfn[uT.ind[d + 2]]), ans[x] = n - d - 1 ; 
	Ans += 1ll * ans[rt[x]] * T1.t[x].len ;  
}
signed main()
{
	scanf("%s", sf + 1), n = strlen(sf + 1), Ans = 2 ; 
	rep( i, 2, n ) us[i - 1] = sf[i] ; uT.build(us, n - 1) ;
	uT.DFS(1, 1), Ans += uT.F, uT.clear() ; 
	rep( i, 1, n - 1 ) us[i] = sf[i] ; uT.build(us, n - 1) ;
	uT.DFS(1, 1), Ans += uT.F, uT.clear() ; 
	rep( i, 1, n ) us[i] = sf[i] ; 
	uT.build(us, n), uT.DFS(1, 1), Ans += uT.F ; 
	rep( i, 1, n ) us[n - i + 1] = sf[i] ; 
	T1.build(us, n), T1.DFS(1, 1) ;
	rep( i, 1, T1.cnt ) rt[i] = i ; 
	solve(1), cout << Ans << endl ; 
	return 0 ;
}