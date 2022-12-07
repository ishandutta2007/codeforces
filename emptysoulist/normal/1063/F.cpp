#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 1e6 + 5 ; 
const int inf = 1e9 + 7 ; 
const int Inf = 1e8 + 7 ; 
struct SuffixTree {
	int lef, len, lk ; 
	int ch[28] ; 
} t[N] ;
int tr[N << 2], m, n, cnt = 1, bef = 1, rem ; 
int Id[N], idx, L[N], R[N], f[N], fa[N][19], dep[N] ;
char s[N] ;
int node(int l, int len) { t[++ cnt].lk = 1, t[cnt].lef = l, t[cnt].len = len ; return cnt ; } 
int query( int x, int l, int r, int ql, int qr ) {
	if( ql <= l && r <= qr ) return tr[x] ; 
	if( ql > r || qr < l ) return 0 ; 
	int mid = ( l + r ) >> 1 ; 
	return max(query(ls(x), l, mid, ql, qr), query(rs(x), mid + 1, r, ql, qr)) ;
}
void update( int x, int l, int r, int k, int d ) {
	if( l == r ) { tr[x] = d ; return ; }
	int mid = ( l + r ) >> 1 ; 
	if( mid >= k ) update( ls(x), l, mid, k, d ) ; 
	else update( rs(x), mid + 1, r, k, d ) ; 
	tr[x] = max( tr[ls(x)], tr[rs(x)] ) ; 
}
void insert(int x) {
	++ m, s[x] -= 'a' ; int u = s[x], lst = 1 ; ++ rem ; 
	while( rem ) {
		while( rem > t[t[bef].ch[s[m - rem + 1]]].len ) 
		rem -= t[bef = t[bef].ch[s[m - rem + 1]]].len ; 
		int &d = t[bef].ch[s[m - rem + 1]], c = s[t[d].lef + rem - 1] ;
		if( u == c || !d ) {
			t[lst].lk = bef, lst = bef ; 
			if( !d ) d = node( m - rem + 1, inf ) ; 
			else return ;
		} else {
			int np = node(t[d].lef, rem - 1) ;
			t[np].ch[u] = node(m, inf), t[np].ch[c] = d,
			t[d].lef += (rem - 1), t[d].len -= (rem - 1),
			t[lst].lk = d = np, lst = d ; 
		} (bef == 1) ? -- rem : bef = t[bef].lk ;  
	} 
}
void dfs( int x, int ff, int d ) {
	L[x] = ++ idx ; 
	fa[x][0] = ff ; rep( i, 1, 17 ) fa[x][i] = fa[fa[x][i - 1]][i - 1] ; 
	if( t[x].len > Inf ) {
		t[x].len = n + 1 - t[x].lef, d += t[x].len, Id[n - d + 1] = x ; dep[x] = d ; 
		return ; 
	}
	d += t[x].len ; int v ; dep[x] = d ; 
	rep( i, 0, 26 ) if( v = t[x].ch[i] ) dfs( v, x, d ) ; 
	R[x] = idx ; 
}
int Get( int l, int le ) {
	int x = Id[l] ; 
	drep( i, 0, 17 ) if(dep[fa[x][i]] >= le) x = fa[x][i] ; 
	return x ; 
}
signed main()
{
	n = gi(), scanf("%s", s + 1 ), t[0].len = inf, s[++ n] = 'z' + 1 ; 
	rep( i, 1, n ) insert(i) ; -- n ; 
	dfs(1, 1, 0) ; int r = n + 1 ; f[n + 1] = 0 ; t[1].len = 0 ; 
	for( re int i = n; i >= 1; -- i ) {
		for( re int j = f[i + 1] + 1; j > 0; -- j ) {
			int l = i + j ;
			if( r > l ) -- r, update( 1, 1, idx, L[Id[r]], f[r] ) ;
			int u = Get(i, j - 1) ; 
			int mx = query(1, 1, idx, L[u], R[u] ) ; 
			u = Get(i + 1, j - 1) ;
			mx = max( mx, query(1, 1, idx, L[u], R[u]) ) ;
			if( mx >= j - 1 ) { f[i] = j ; break ; }
		}
	}
	int ans = 0 ;
	rep( i, 1, n ) ans = max( ans, f[i] ) ;
	cout << ans << endl ; 
	return 0 ;
}