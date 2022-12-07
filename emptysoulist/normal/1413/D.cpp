#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 2e5 + 5 ; 
int n, idx, num, a[N], cnt[N], st[N], top, flag ; 
void out() {
	puts("NO") ; exit(0) ; 
} 
struct node {
	int l, w ; 
} nd[N] ;
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
int tr[N << 2], Id[N << 2], Mi, id ;
void pushup(int x) {
	tr[x] = min( tr[ls(x)], tr[rs(x)] ) ; 
	if( tr[ls(x)] > tr[rs(x)] ) Id[x] = Id[rs(x)] ;
	else Id[x] = Id[ls(x)] ; 
}
void query(int x, int l, int r, int ql, int qr) {
	if( ql <= l && r <= qr ) {
		if( Mi > tr[x] ) Mi = tr[x], id = Id[x] ; 
		return ; 
	}
	if( r < ql || qr < l ) return ; 
	int mid = (l + r) >> 1 ; 
	query(ls(x), l, mid, ql, qr),
	query(rs(x), mid + 1, r, ql, qr) ; 
}
void update(int x, int l, int r, int k, int w) {
	if( l == r ) return Id[x] = l, tr[x] = w, void() ;
	int mid = (l + r) >> 1 ;
	if( mid >= k ) update(ls(x), l, mid, k, w) ;
	else update(rs(x), mid + 1, r, k, w) ;  
	pushup(x) ; 
}
signed main()
{
	n = gi() ; 
	int m = 2 * n ;
	char c ; int x ; 
	rep( i, 1, m ) {
		c = getchar() ; 
		if( c == '-' ) {
			x = gi() ; 
			a[st[top]] = x ; 
			-- top ;
			if( cnt[x] ) out() ;
			cnt[x] = 1 ; 
			++ idx, nd[idx] = (node){num, x} ; 
		}
		else {
			++ num ; 
			st[++ top] = num ;
			getchar() ; 
		}
	}
	for(re int i = 1; i <= n; ++ i) {
		if( cnt[i] ) continue ;
		a[st[top]] = i, -- top ; 
	}
	rep( i, 1, n ) update(1, 1, n, i, a[i]) ;
	rep( i, 1, n ) {
		int l = nd[i].l, ww = nd[i].w ;
		if(!l) out() ; 
		Mi = n + 1, id = 0 ;
		query(1, 1, n, 1, l) ;
		if( Mi != ww ) out() ;
		update(1, 1, n, id, n + 1) ; 
	}
	printf("YES\n", n ) ;
	rep( i, 1, n ) printf("%d ", a[i] ) ; 
	return 0 ;
}