#include<bits/stdc++.h>
using namespace std;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define inf 123456789
#define ls(x) x * 2
#define rs(x) x * 2 + 1
int read() {
	char cc = getchar(); int cn = 0, flus = 1;
	while(cc < '0' || cc > '9') {  if( cc == '-' ) flus = -flus;  cc = getchar();  }
	while(cc >= '0' && cc <= '9')  cn = cn * 10 + cc - '0', cc = getchar();
	return cn * flus;
}
const int N = 1e6 + 5 ; 
int n, m, cnt, num, top, idnex, a[N], st[N] ; 
int head[N], dep[N], L[N], R[N], ans[N] ; 
struct E {
	int to, next ; 
} e[N] ;
struct Tr {
	int mx, ad ; 
} tr[N * 4];
void input() {
	n = read(), m = read() ; 
	rep( i, 1, n ) a[i] = read() ; 
}
void add( int x, int y ) {
	e[++ cnt] = (E){ y, head[x] }, head[x] = cnt ;
}
void dfs( int x ) {
	L[x] = ++ idnex ;
	Next( i, x ) dep[e[i].to] = dep[x] + 1, dfs(e[i].to) ;
	R[x] = idnex ; 
}
void init() {
	++ n, a[n] = inf ; 
	rep( i, 1, n ) {
		while( top && a[st[top]] < a[i] ) add( i, st[top] ), -- top ; 
		st[++ top] = i ; 
	}
	dfs( n ); 
}
void pushup( int x ) {
	if( tr[x].ad ) {
		tr[ls(x)].mx += tr[x].ad, tr[ls(x)].ad += tr[x].ad ;
		tr[rs(x)].mx += tr[x].ad, tr[rs(x)].ad += tr[x].ad ;
		tr[x].ad = 0 ; 
	}
}
void update( int x, int l, int r, int ql, int qr, int ad ) {
	if( l > qr || r < ql ) return ; 
	if( l >= ql && r <= qr ) {
		tr[x].mx += ad, tr[x].ad += ad; return ;  
	}
	pushup(x) ; int mid = ( l + r ) >> 1 ; 
	update( ls(x), l, mid, ql, qr, ad ),
	update( rs(x), mid + 1, r, ql, qr, ad ) ;
	tr[x].mx = max( tr[ls(x)].mx, tr[rs(x)].mx ) ; 
}
void solve() { 
	for( int i = n - 1; i > 0; -- i ) {
		if( i + m < n ) update( 1, 1, n, L[i + m], R[i + m], -1 ) ;
		update( 1, 1, n, L[i], L[i], dep[i] ) ; 
		if( i + m <= n ) ans[++ num] = tr[1].mx ; 
	}
	for( int i = num; i > 0; -- i ) printf("%d ", ans[i] ) ;
}
signed main()
{
	input(), init(), solve() ;
	return 0;
}