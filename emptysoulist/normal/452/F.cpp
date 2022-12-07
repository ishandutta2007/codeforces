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
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 3e5 + 5 ; 
const int P = 998244353 ; 
const int F = 233 ; 
int n, p[N], fac[N], flag ; 
struct Tr {
	int lw, rw, len ; 
} tr[N << 2] ;
void pushup(int x) {
	tr[x].len = tr[ls(x)].len + tr[rs(x)].len ; 
	tr[x].lw = (tr[ls(x)].lw * fac[tr[rs(x)].len] + tr[rs(x)].lw) % P,
	tr[x].rw = (tr[ls(x)].rw + tr[rs(x)].rw * fac[tr[ls(x)].len]) % P ; 
}
void change(int x, int l, int r, int k) {
	if(l == r) return tr[x].lw = tr[x].rw = 1, void() ; 
	int mid = (l + r) >> 1 ; 
	if(k <= mid) change(ls(x), l, mid, k) ;
	else change(rs(x), mid + 1, r, k) ; 
	pushup(x) ; 
}
int Lquery(int x, int l, int r, int ql, int qr) {
	if(ql <= l && r <= qr) return tr[x].lw ; 
	if(l > qr || r < ql) return 0 ; 
	int mid = (l + r) >> 1, rr = min( max(0ll, qr - mid), tr[rs(x)].len ) ; 
	int lq = Lquery(ls(x), l, mid, ql, qr), rq = Lquery(rs(x), mid + 1, r, ql, qr) ; 
	int ff = (lq * fac[rr] + rq) % P ; 
	return ff ; 
}
int Rquery(int x, int l, int r, int ql, int qr) {
	if(ql <= l && r <= qr) return tr[x].rw ; 
	if(l > qr || r < ql) return 0 ; 
	int mid = (l + r) >> 1, ll = min( max(0ll, mid - ql + 1), tr[ls(x)].len ) ; 
	int lq = Rquery(ls(x), l, mid, ql, qr), rq = Rquery(rs(x), mid + 1, r, ql, qr) ; 
	int ff = (lq + fac[ll] * rq) % P ;
	return ff ; 
}
void build(int x, int l, int r) {
	if(l == r) return tr[x].len = 1, void() ; 
	int mid = (l + r) >> 1 ; 
	build(ls(x), l, mid), build(rs(x), mid + 1, r), pushup(x) ; 
}
signed main()
{
	n = gi(), fac[0] = 1 ; 
	rep( i, 1, n ) p[i] = gi() ; 
	rep( i, 1, n ) fac[i] = fac[i - 1] * F % P ;
	build(1, 1, n) ;  
	for(re int i = 1; i <= n; ++ i) {
		change(1, 1, n, p[i]) ; 
		if(p[i] != 1 && p[i] != n) { 
			int u = p[i], len = min(u - 1, n - u) ; 
			if(Lquery(1, 1, n, u - len, u) != Rquery(1, 1, n, u, u + len)) flag = 1 ; 
		} 
	}
	if(flag) puts("YES") ; 
	else puts("NO") ; 
	return 0 ;
}