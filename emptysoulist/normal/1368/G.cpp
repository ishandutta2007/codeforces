#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define vi vector<int>
#define pb push_back
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 2e5 + 5 ; 
int n, m, lim, cnt, Ans, L[N], R[N], g[N] ; 
vi a[N], G[N] ; 
char s[N] ; 
void add(int x, int y) { G[y].pb(x) ; }
struct Tr {
	int mi, w, tag ; 
} tr[N << 2] ; 
int Id(int x, int y) {
	if( x < 1 || y < 1 || x > n || y > m ) return 0 ; 
	return (x - 1) * m + y ; 
}
void pushup(int x) {
	tr[x].mi = min(tr[ls(x)].mi, tr[rs(x)].mi), tr[x].w = 0;
	if(tr[x].mi == tr[ls(x)].mi) tr[x].w += tr[ls(x)].w ;
	if(tr[x].mi == tr[rs(x)].mi) tr[x].w += tr[rs(x)].w ; 
}
void pushmark(int x) {
	int u = tr[x].tag ; tr[x].tag = 0 ; 
	tr[ls(x)].mi += u, tr[rs(x)].mi += u, 
	tr[ls(x)].tag += u, tr[rs(x)].tag += u ; 
}
void update(int x, int l, int r, int ql, int qr, int k) {
	if( ql <= l && r <= qr ) return tr[x].mi += k, tr[x].tag += k, void() ;
	if( l > qr || r < ql ) return ; 
	int mid = (l + r) >> 1 ; pushmark(x) ; 
	update(ls(x), l, mid, ql, qr, k), update(rs(x), mid + 1, r, ql, qr, k),
	pushup(x) ; 
}
void dfs(int x) {
	L[x] = ++ cnt ; 
	for(int v: G[x]) dfs(v) ;
	R[x] = cnt ; 
}
void build(int x, int l, int r) {
	tr[x].w = r - l + 1 ; 
	if( l == r ) return ;
	int mid = (l + r) >> 1 ; 
	build(ls(x), l, mid), build(rs(x), mid + 1, r) ;  
}
void Dfs(int x) {
	if(x) {
		update(1, 1, cnt, L[g[x]], R[g[x]], 1) ; 
		Ans += (cnt - tr[1].w) ;
	}
	for(int v : G[x]) Dfs(v) ;
	if(x) update(1, 1, cnt, L[g[x]], R[g[x]], -1) ;
}
signed main()
{
	n = gi(), m = gi(), lim = n * m ; 
	rep( i, 1, n ) {
		scanf("%s", s + 1 ), a[i].pb(0) ; 
		rep( j, 1, m ) {
			if(s[j] == 'L') a[i].pb(1) ;
			if(s[j] == 'R') a[i].pb(2) ;
			if(s[j] == 'U') a[i].pb(3) ;
			if(s[j] == 'D') a[i].pb(4) ; 
		}
	}
	rep( i, 1, n ) rep( j, 1, m ) {
		int u = Id(i, j) ; 
		if(a[i][j] == 1) add(u, Id(i, j + 2)), g[u] = Id(i, j + 1) ;
		if(a[i][j] == 2) add(u, Id(i, j - 2)), g[u] = Id(i, j - 1) ;
		if(a[i][j] == 3) add(u, Id(i + 2, j)), g[u] = Id(i + 1, j) ;
		if(a[i][j] == 4) add(u, Id(i - 2, j)), g[u] = Id(i - 1, j) ;
	}
	dfs(0), build(1, 1, cnt), Dfs(0) ;
	cout << Ans / 2 << endl ; 
	return 0 ;
}