#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define vi vector<int>
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
#define pb push_back
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 1e6 + 5 ; 
const int inf = 1e18 + 7 ; 
int n, m, p, a[N], S ; 
struct Tr {
	int sum, len ; vi f ; 
} tr[N << 2] ; 
void pushup(int x) {
	vi l = tr[ls(x)].f, r = tr[rs(x)].f ;
	vi c ; c.resize(tr[x].len + 1) ;
	rep( i, 0, tr[x].len ) c[i] = inf ; int j = 0 ; 
	for(int i = 0; i < l.size(); ++ i) {
		int d = i * p - tr[ls(x)].sum ; if(j) -- j ; 
		for(; j < r.size(); ++ j) {
			int res = max( l[i], r[j] + d ) ;
			c[i + j] = min( c[i + j], res ) ; 
			if( i != (l.size() - 1) ) {
				int mx = l[i + 1] - d ; 
				if( mx <= r[j] ) { if(j) -- j ; break ; }
			}
		}
	} tr[x].f = c, tr[x].sum = tr[ls(x)].sum + tr[rs(x)].sum ; 
}
void build(int x, int l, int r) {
	tr[x].len = r - l + 1 ; 
	if( l == r ) { tr[x].sum = a[l], tr[x].f.pb(-inf), tr[x].f.pb(p - a[l]) ; return ; }
	int mid = (l + r) >> 1 ; 
	build(ls(x), l, mid), build(rs(x), mid + 1, r), pushup(x) ; 
}
void query(int x, int l, int r, int ql, int qr) {
	if( ql <= l && r <= qr ) {
		int res = upper_bound(tr[x].f.begin(), tr[x].f.end(), S) - tr[x].f.begin() - 1 ;
		S = S + tr[x].sum - res * p ; return ; 
	}
	if( qr < l || ql > r ) return ; 
	int mid = (l + r) >> 1 ; 
	query(ls(x), l, mid, ql, qr), query(rs(x), mid + 1, r, ql, qr) ; 
}
void Q(int l, int r) {
	S = 0, query(1, 1, n, l, r), printf("%lld\n", S ) ; 
}
signed main()
{
	n = gi(), m = gi(), p = gi() ; 
	rep( i, 1, n ) a[i] = gi() ; 
	build(1, 1, n) ; int l, r ; 
	while( m -- ) l = gi(), r = gi(), Q(l, r) ;
	return 0 ;
}