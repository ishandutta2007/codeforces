#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( int i = (t); i >= (s); -- i )
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
const int N = 5e5 + 5 ; 
int n, m, num, cnt, Id[N], Ans[N], dis[N], A[N], head[N], L[N], R[N] ; 
struct E { int to, next, w ; } e[N << 1] ; 
struct node { int l, r, id ; } q[N] ; 
vector<node> Q[N] ; 
map<pi, int> St ; 
void add(int x, int y, int z) {
	e[++ cnt] = (E){ y, head[x], z }, head[x] = cnt,
	e[++ cnt] = (E){ x, head[y], z }, head[y] = cnt ; 
	St[mp(x, y)] = St[mp(y, x)] = z ; 
}
set<int> S ; 
set<int>::iterator it ; 
void dfs(int x, int fa) {
	L[x] = n + 1, R[x] = 0 ; 
	dis[x] = dis[fa] + St[mp(x, fa)] ; 
	vector<int> Go ; 
	Next( i, x ) if(e[i].to ^ fa) Go.pb(e[i].to) ; 
	sort(Go.begin(), Go.end()) ; 
	if(Go.empty()) { A[++ num] = x, L[x] = R[x] = Id[x] = num, S.insert(x) ; }
	else {
		for(int v : Go) dfs(v, x), 
		L[x] = min(L[v], L[x]), R[x] = max(R[x], R[v]) ; 
	}
}
struct Tr {
	int w, tag ; 
} tr[N << 2] ; 
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
const int inf = 1e16 ; 
void pushup(int x) {
	tr[x].w = min(tr[ls(x)].w, tr[rs(x)].w) ; 
}
void pushmark(int x) {
	int d = tr[x].tag ; 
	tr[ls(x)].tag += d, tr[ls(x)].w += d,
	tr[rs(x)].tag += d, tr[rs(x)].w += d,
	tr[x].tag = 0 ; 
}
void build(int x, int l, int r) {
	if(l == r) return tr[x].w = dis[A[l]], void() ; 
	int mid = (l + r) >> 1 ; 
	build(ls(x), l, mid), build(rs(x), mid + 1, r) ; 
	pushup(x) ; 
}
void update(int x, int l, int r, int ql, int qr, int k) {
//	printf("update %lld [%lld %lld] [%lld %lld] %lld\n", x, l, r, ql, qr, k ) ; 
	if(r < ql || l > qr || ql > qr) return ; 
	if(ql <= l && r <= qr) return tr[x].w += k, tr[x].tag += k, void() ; 
	int mid = (l + r) >> 1 ; pushmark(x) ; 
	update(ls(x), l, mid, ql, qr, k),
	update(rs(x), mid + 1, r, ql, qr, k) ; 
	pushup(x) ; 
}
int query(int x, int l, int r, int ql, int qr) {
//	printf("%lld [%lld %lld] %lld %lld\n", x, l, r, ql, qr ) ; 
	if(r < ql || l > qr) return inf ; 
	if(ql <= l && r <= qr) return tr[x].w ; 
	int mid = (l + r) >> 1 ; pushmark(x) ; 
	return min(query(ls(x), l, mid, ql, qr), query(rs(x), mid + 1, r, ql, qr)) ; 
} 
void DFS(int x, int fa) {
//	printf("DFS %lld %lld %lld\n", x, L[x], R[x] ) ; 
	if(x != fa) {
		int d = St[mp(x, fa)] ; 
		update(1, 1, num, L[x], R[x], -d),
		update(1, 1, num, 1, L[x] - 1, d),
		update(1, 1, num, R[x] + 1, num, d) ; 
	}
	for(node z : Q[x]) Ans[z.id] = query(1, 1, num, z.l, z.r) ; 
	Next( i, x ) if(e[i].to ^ fa) DFS(e[i].to, x) ; 
	if(x != fa) {
		int d = St[mp(x, fa)] ; 
		update(1, 1, num, L[x], R[x], d),
		update(1, 1, num, 1, L[x] - 1, -d),
		update(1, 1, num, R[x] + 1, num, -d) ; 
	}
}
signed main()
{
	n = gi(), m = gi() ; int x, p ; 
	rep( i, 2, n ) x = gi(), p = gi(), add(i, x, p) ; 
	dfs(1, 1) ; 
	rep( i, 1, m ) {
		x = gi() ; int l = gi(), r = gi() ; 
		it = S.lower_bound(l) ; int ll = (*it) ; 
		it = S.upper_bound(r) ; -- it ; int rr = (*it) ; 
		q[i].id = i, q[i].l = Id[ll], q[i].r = Id[rr] ; 
	//	printf("%lld %lld %lld (%lld %lld)\n", x, ll, rr, q[i].l, q[i].r ) ; 
		Q[x].pb(q[i]) ; 
	}
	build(1, 1, num), DFS(1, 1) ; 
	rep( i, 1, m ) printf("%lld\n", Ans[i] ) ; 
	return 0 ;
}