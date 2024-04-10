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
#define ls(x) tr[x].l
#define rs(x) tr[x].r
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int P = (1ll << 60) - 1 ; 
const int N = 6e5 + 5 ; 
int n, m, cnt, dep[N], head[N], col[N], a[N], rt[N] ; 
int f[N][19] ; 
struct E {
	int to, next ; 
} e[N << 1] ; 
struct Tr {
	int l, r, w ; 
} tr[N * 25] ;   
void add(int x, int y) {
	e[++ cnt] = (E){ y, head[x] }, head[x] = cnt,
	e[++ cnt] = (E){ x, head[y] }, head[y] = cnt ; 
}
void insert(int &x, int u, int l, int r, int k, int w) {
	x = ++ cnt, tr[x] = tr[u], tr[x].w ^= w ;
	if(l == r) return ; int mid = (l + r) >> 1 ; 
	if(k <= mid) insert(ls(x), ls(u), l, mid, k, w) ;
	else insert(rs(x), rs(u), mid + 1, r, k, w) ; 
}
void dfs(int x, int fa) {
	dep[x] = dep[fa] + 1, f[x][0] = fa ;
	insert(rt[x], rt[fa], 1, n, a[x], col[a[x]]) ; 
	rep( i, 1, 18 ) f[x][i] = f[f[x][i - 1]][i - 1] ; 
	Next( i, x ) {
		int v = e[i].to ; if(v == fa) continue ;
		dfs(v, x) ; 
	}
}
int LCA(int x, int y) {
	if(dep[x] < dep[y]) swap(x, y) ;
	drep( i, 0, 18 ) if(dep[f[x][i]] >= dep[y]) x = f[x][i] ;
	drep( i, 0, 18 ) if(f[x][i] != f[y][i]) x = f[x][i], y = f[y][i] ;
	return (x == y) ? x : f[x][0] ; 
} 
int Sub(int x, int l, int r, int k) {
	if(!k) return 0 ; if(l == r) return tr[x].w ; 
	int mid = (l + r) >> 1 ; 
	if(k <= mid) return Sub(ls(x), l, mid, k) ;
	else return tr[ls(x)].w ^ Sub(rs(x), mid + 1, r, k) ;  
}
int check(int x, int y, int lca, int ff, int l, int r, int k, int w) { 
	if(l == r) { 
		int z = (tr[x].w ^ tr[y].w ^ tr[lca].w ^ tr[ff].w) ;
		return (z ^ w) ? l : -1 ; 
	} 
	int mid = (l + r) >> 1 ; 
	int S = (tr[ls(x)].w ^ tr[ls(y)].w ^ tr[ls(lca)].w ^ tr[ls(ff)].w) ; 
	if(mid <= k) return check(rs(x), rs(y), rs(lca), rs(ff), mid + 1, r, k, w ^ S) ;
	if(S ^ w) return check(ls(x), ls(y), ls(lca), ls(ff), l, mid, k, w) ; 
	else return check(rs(x), rs(y), rs(lca), rs(ff), mid + 1, r, k, w ^ S) ; 
}
int query(int x, int y, int l, int r) {
	int lca = LCA(x, y), ff = f[lca][0] ; 
	int d = Sub(rt[x], 1, n, l - 1) ^ Sub(rt[y], 1, n, l - 1) ; 
	d ^= Sub(rt[lca], 1, n, l - 1), d ^= Sub(rt[ff], 1, n, l - 1) ; 
	int rr = check(rt[x], rt[y], rt[lca], rt[ff], 1, n, l - 1, d) ;
	return (rr <= r) ? rr : -1 ; 
}
int sw() { return (((1ull * rand() << 48ll) ^ (1ull * rand() << 32ll) ^ (1ull * rand() << 16ll) ^ rand()) & P) ; }
signed main() 
{
	n = gi(), m = gi() ; int x, y, l, r ; 
	rep( i, 1, n ) a[i] = gi() ; 
	rep( i, 2, n ) x = gi(), y = gi(), add(x, y) ; 
	rep( i, 1, n ) col[i] = sw() ; 
	cnt = 0, dfs(1, 0) ; 
	rep( i, 1, m ) {
		x = gi(), y = gi(), l = gi(), r = gi() ; 
		printf("%lld\n", query(x, y, l, r)) ; 
	}
	return 0 ;
}