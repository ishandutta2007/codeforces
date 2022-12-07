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
const int inf = 1e9 ; 
const int Inf = 1e8 ; 
const int N = 4e5 + 5 ; 
int head[N], n, q, m, rem, cnt = 1, bef = 1, st[N], top ; 
struct E { int to, next, w ; } e[N << 1] ; 
struct SuffixTree { int ch[30], lef, len, lk ; } t[N] ;
char s[N] ; 
int node(int l, int len) {
	++ cnt, t[cnt].len = len, t[cnt].lef = l, t[cnt].lk = 1 ; 
	return cnt ; 
} 
void insert(int x) {
	++ m, ++ rem, s[x] -= 'a' ; int u = s[x], lst = 1 ; 
	while(rem) {
		while( rem > t[t[bef].ch[(int)s[m - rem + 1]]].len )
		rem -= t[bef = t[bef].ch[(int)s[m - rem + 1]]].len ; 
		int &d = t[bef].ch[(int)s[m - rem + 1]], c = s[t[d].lef + rem - 1] ; 
		if(!d || c == u) {
			t[lst].lk = bef, lst = bef ; 
			if(!d) d = node(m, inf) ; 
			else break ; 
		}
		else {
			int np = node(t[d].lef, rem - 1) ; 
			t[d].lef += (rem - 1), t[d].len -= (rem - 1) ;
			t[np].ch[c] = d, t[np].ch[u] = node(m, inf) ;
			t[lst].lk = d = np, lst = d ; 
		} (bef == 1) ? -- rem : bef = t[bef].lk ; 
	}
}
int idx, dfn[N], dis[N], Fa[N], sz[N], son[N], Dep[N], Top[N], Id[N] ; 
void DFS(int x, int fa, int dep) {
	sz[x] = 1, Dep[x] = Dep[fa] + 1, Fa[x] = fa ; 
	if(t[x].len > Inf) {
		t[x].len = n - t[x].lef + 1, dep += t[x].len, dis[x] = dep ; 
		Id[n - dep + 1] = x ; return ; 
	} dep += t[x].len, dis[x] = dep ; 
	rep( i, 0, 26 ) {
		int v = t[x].ch[i] ; if(!v) continue ; 
		DFS(v, x, dep), sz[x] += sz[v] ;
		if(sz[son[x]] <= sz[v]) son[x] = v ; 
	}
}
void DFS2(int x, int high) {
	Top[x] = high, dfn[x] = ++ idx ; 
	if(son[x]) DFS2(son[x], high) ; 
	rep( i, 0, 26 ) {
		int v = t[x].ch[i] ; if((!v) || (v == son[x])) continue ; 
		DFS2(v, v) ; 
	}
}
int LCA(int x, int y) {
	while(Top[x] != Top[y]) {
		if(Dep[Top[x]] < Dep[Top[y]]) swap(x, y) ; 
		x = Fa[Top[x]] ; 
	} return (Dep[x] < Dep[y]) ? x : y ; 
}
bool cmp(int x, int y) { return dfn[x] < dfn[y] ; }
void add(int x, int y, int z) { e[++ cnt] = (E){ y, head[x], z }, head[x] = cnt ; }
void Add(int x, int y) { add(x, y, dis[y] - dis[x]) ; }
void ins(int x) {
	if(st[top] == 1) { st[++ top] = x ; return ; }
	int lca = LCA(st[top], x) ; if(lca == x) return ; 
	while((top > 1) && (dfn[st[top - 1]] > dfn[lca])) Add(st[top - 1], st[top]), -- top ; 
	if(dfn[lca] < dfn[st[top]]) Add(lca, st[top]), -- top ; 
	if(dfn[lca] > dfn[st[top]]) st[++ top] = lca ; 
	st[++ top] = x ; 
}
int fA[N], fB[N] ; long long Ans ; 
void dfs(int x, int fa) {
	Next( i, x ) {
		int v = e[i].to ; 
		dfs(v, x), fA[x] += fA[v], fB[x] += fB[v] ; 
		head[v] = fA[v] = fB[v] = 0 ; 
	}
	Ans += 1ll * fA[x] * fB[x] * (dis[x] - dis[fa]) ; 
}
signed main()
{
	n = gi(), q = gi(), scanf("%s", s + 1) ; 
	s[++ n] = 'z' + 1, t[0].len = inf ; 
	rep( i, 1, n ) insert(i) ; 
	-- n, DFS(1, 0, 0), DFS2(1, 1) ;
	cnt = 0 ; vi A, B, C ; 
	while(q--) {
		int l1 = gi(), l2 = gi(), lim = l1 + l2 ; 
		A.resize(l1 + 1), B.resize(l2 + 1), cnt = 0 ; 
		rep( i, 1, l1 ) A[i] = gi(), A[i] = Id[A[i]], ++ fA[A[i]] ; 
		rep( i, 1, l2 ) B[i] = gi(), B[i] = Id[B[i]], ++ fB[B[i]] ; 
		rep( i, 1, l1 ) C.pb(A[i]) ;
		rep( i, 1, l2 ) C.pb(B[i]) ; 
		sort(C.begin(), C.end(), cmp) ; 
		st[top = 1] = 1 ; 
		for(int i = 0; i < lim; ++ i) ins(C[i]) ; 
		while(top > 1) Add(st[top - 1], st[top]), -- top ; 
		dfs(1, 1), printf("%lld\n", Ans ), Ans = 0 ; 
		A.clear(), B.clear(), C.clear(), fA[1] = fB[1] = head[1] = 0 ; 
	}
	return 0 ;
}