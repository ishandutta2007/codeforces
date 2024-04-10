// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define int long long
#define ls(x) tr[x].l
#define rs(x) tr[x].r
int read() {
	char cc = getchar(); int cn = 0, flus = 1;
	while(cc < '0' || cc > '9') {  if( cc == '-' ) flus = -flus;  cc = getchar();  }
	while(cc >= '0' && cc <= '9')  cn = cn * 10 + cc - '0', cc = getchar();
	return cn * flus;
}
const int N = 1e5 + 5 ; 
int n, c[N], head[N], tot, cnt, Ans[N], rt[N] ; 
struct E {
	int to, next ; 
} e[N * 2] ;
struct Tr {
	int l, r, mx, sum ; 
} tr[N * 20] ;
void add( int x, int y ) {
	e[++ cnt] = (E){ y, head[x] }, head[x] = cnt , 
	e[++ cnt] = (E){ x, head[y] }, head[y] = cnt ; 
}
void pushup( int x ) {
	if( tr[ls(x)].mx == tr[rs(x)].mx ) tr[x].mx = tr[ls(x)].mx, tr[x].sum = tr[ls(x)].sum + tr[rs(x)].sum ; 
	else {
		tr[x].mx = max( tr[ls(x)].mx, tr[rs(x)].mx ) ;
		tr[x].sum = ( tr[ls(x)].mx > tr[rs(x)].mx ) ? tr[ls(x)].sum : tr[rs(x)].sum ; 
	}
}
void merge( int &lx, int rx, int l, int r ) {
	if( !lx || !rx ) { lx = lx + rx ; return ; }
	if( l == r ) { tr[lx].mx += tr[rx].mx, tr[lx].sum = l ;  return ; }
	int mid = ( l + r ) >> 1 ; 
	merge( ls(lx), ls(rx), l, mid ), merge( rs(lx), rs(rx), mid + 1, r ) ;
	pushup(lx) ; 
}
void ins( int &x, int l, int r, int wh ) {
	if( !x ) x = ++ tot ; 
	if( l == r ) {
		tr[x].sum = l, tr[x].mx = 1 ; return ; 
	}
	int mid = ( l + r ) >> 1 ; 
	if( mid >= wh ) ins( ls(x), l, mid, wh ) ;
	else ins( rs(x), mid + 1, r, wh ) ;
	pushup(x) ; 
}
void dfs( int x, int fa ) {
	ins( rt[x], 1, n, c[x] ) ;
	Next( i, x ) {
		int v = e[i].to ; if( v == fa ) continue ;
		dfs( v, x ), merge( rt[x], rt[v], 1, n ) ;
	}
	Ans[x] = tr[rt[x]].sum ; 
}
signed main()
{
	n = read() ; rep( i, 1, n ) c[i] = read() ; int x, y ; 
	rep( i, 2, n ) x = read(), y = read(), add( x, y ) ;
	dfs( 1, 1 ) ; rep( i, 1, n ) printf("%lld ", Ans[i] ) ;
	return 0;
}