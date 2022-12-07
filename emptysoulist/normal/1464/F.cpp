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
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 2e5 + 5 ; 
int n, m, num, dep[N], Id[N], L[N], R[N] ; 
vector<int> G[N] ; 
multiset<pi> S ; 
multiset<pi>::iterator it ; 
void add(int x, int y) { G[x].pb(y), G[y].pb(x) ; }
namespace Sub1 {
	int idx, f[N], top[N], sz[N], son[N] ; 
	int go[N][20] ; 
	void dfs1(int x, int fa) {
		sz[x] = 1, f[x] = fa, dep[x] = dep[fa] + 1, go[x][0] = fa ; 
		rep( i, 1, 17 ) go[x][i] = go[go[x][i - 1]][i - 1] ;
		for(int v : G[x]) {
			if(v == fa) continue ;
			dfs1(v, x), sz[x] += sz[v] ; 
			if(sz[son[x]] <= sz[v]) son[x] = v ; 
		}
	}
	void dfs2(int x, int high) {
		top[x] = high, L[x] = ++ idx, Id[idx] = x ;
		if(son[x]) dfs2(son[x], high) ; 
		for(int v : G[x]) {
			if(v == f[x] || v == son[x]) continue ;
			dfs2(v, v) ; 
		} R[x] = idx ; 
	}
	int LCA(int x, int y) {
		while(top[x] != top[y]) {
			if(dep[top[x]] < dep[top[y]]) swap(x, y) ;
			x = f[top[x]] ; 
		} return (dep[x] < dep[y]) ? x : y ; 
	}
	int Get(int x, int d) {
		int D = dep[x] - d ; 
		drep( i, 0, 17 ) if(dep[go[x][i]] >= D) x = go[x][i] ;
		return x ;  
	}
	int Dis(int x, int y) {
		if(!x || !y) return -1 ; 
		return dep[x] + dep[y] - 2 * dep[LCA(x, y)] ; 
	}
	void init() {
		dfs1(1, 1), dfs2(1, 1) ; 
	}
}
namespace Sub2 {
	int tree[N] ;
	int lowbit(int x) { return (x & (-x)) ; }
	void inc(int x, int k) {
		for(int i = x; i <= n; i += lowbit(i)) tree[i] += k ; 
	}
	int qry(int x) {
		int sum = 0 ;
		for(int i = x; i; i -= lowbit(i)) sum += tree[i] ;
		return sum ; 
	}
	void Add(int x, int y, int type) {
		inc(L[x], type), inc(L[y], type), inc(L[Sub1::LCA(x, y)], -type), num += type ; 
	}
	int query(int x) {
		return ((qry(R[x]) - qry(L[x] - 1)) == num) ;
	}
}
struct node {
	int l, r, len ; 
	void init() { l = r = 0, len = -10 ; }
	node(int _l = 0, int _r = 0, int _len = 0) {
		l = _l, r = _r, len = _len ; 
	}
} tr[N << 2], o ;
node max(node x, node y) {
	return (x.len > y.len) ? x : y ; 
}
node operator + (node x, node y) {
	node ans = max(x, y) ; node u ; 
	if(x.l && y.l) u = node(x.l, y.l, Sub1::Dis(x.l, y.l)), ans = max(ans, u) ;
	if(x.l && y.r) u = node(x.l, y.r, Sub1::Dis(x.l, y.r)), ans = max(ans, u) ; 
	if(x.r && y.l) u = node(x.r, y.l, Sub1::Dis(x.r, y.l)), ans = max(ans, u) ;
	if(x.r && y.r) u = node(x.r, y.r, Sub1::Dis(x.r, y.r)), ans = max(ans, u) ; 
//	printf("+ (%d %d) %d\n", x.len, y.len, ans.len) ; 
	return ans ; 
}
namespace Sub3 {
	int tag[N << 2] ; 
	void build(int x, int l, int r) {
		if(l == r) return tr[x].init(), void() ;
		int mid = (l + r) >> 1 ;
		build(ls(x), l, mid), build(rs(x), mid + 1, r),
		tr[x] = tr[ls(x)] + tr[rs(x)] ; 
	}
	void update(int x, int l, int r, int k, int type) {
		if(l == r) {
			int u = Id[l] ; tag[x] += type ;
			if(tag[x]) tr[x] = node(u, u, 0) ; 
			else tr[x].init() ; 
			return ; 
		} int mid = (l + r) >> 1 ; 
		if(k <= mid) update(ls(x), l, mid, k, type) ;
		else update(rs(x), mid + 1, r, k, type) ;
	//	printf("update %d [%d %d] %d %d %d\n", x, l, r, k, type, tr[x].len ) ;
		tr[x] = tr[ls(x)] + tr[rs(x)] ; 
	//	printf("update %d %d %d\n", tr[x].l, tr[x].r, tr[x].len ) ; 
	}
	node query(int x, int l, int r, int ql, int qr) {
		if(r < ql || qr < l) return o ; 
		if(ql <= l && r <= qr) return tr[x] ; 
		int mid = (l + r) >> 1 ; 
		return query(ls(x), l, mid, ql, qr) + query(rs(x), mid + 1, r, ql, qr) ; 
	}
	void Add(int x, int y) {
		Sub2::Add(x, y, 1) ; int u = Sub1::LCA(x, y) ;
		S.insert(mp(dep[u], u)) ; 
		update(1, 1, n, L[u], 1) ;
	}
	void Del(int x, int y) {
		Sub2::Add(x, y, -1) ; int u = Sub1::LCA(x, y) ;
		S.erase(S.find(mp(dep[u], u))) ; 
		update(1, 1, n, L[u], -1) ; 
	}
	void qry(int d) {
		it = S.end() ; -- it ; 
		int u = (*it).second ; 
		int v = Sub1::Get(u, d) ;
		int x = Sub1::Get(v, d) ; 
		if(!Sub2::query(x)) puts("No") ; 
		else {
			node z = query(1, 1, n, L[x], R[x]) ; 
		//	cout << d << " " << u << " " << v << " " << x << endl ; 
		//	printf("%d %d %d (%d %d)\n", z.l, z.r, z.len, L[x], R[x] ) ;
			int dis = max(Sub1::Dis(z.l, v), Sub1::Dis(z.r, v)) ; 
		//	cout << dis << endl ; 
			if(dis <= d) puts("Yes") ;
			else puts("No") ; 
		}
	}
	void init() { o.init() ; build(1, 1, n) ; }
}
signed main()
{
	n = gi(), m = gi() ; int x, y ; 
	rep( i, 2, n ) x = gi(), y = gi(), add(x, y) ; 
	Sub1::init(), Sub3::init() ; 
	while(m --) {
		int opt = gi() ; x = gi() ; 
		if(opt == 1) y = gi(), Sub3::Add(x, y) ; 
		if(opt == 2) y = gi(), Sub3::Del(x, y) ; 
		if(opt == 3) Sub3::qry(x) ; 
	}
	return 0 ;
}