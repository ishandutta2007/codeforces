#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 2e6 + 5 ;
int n, m, cnt, idnex, head[N], dfn[N], low[N], st[N], top, col[N], idnum ; 
struct E {
	int to, next ; 
} e[N * 2] ;
void add( int x, int y ) {
	e[++ cnt] = (E){ y, head[x] }, head[x] = cnt ; 
}
void tarjan( int x ) {
	dfn[x] = low[x] = ++ idnex, st[++ top] = x ; 
	Next( i, x ) {
		int v = e[i].to ; 
		if( !dfn[v] ) tarjan(v), low[x] = min( low[x], low[v] ) ;
		else low[x] = min( low[x], dfn[v] ) ;
	}
	if( low[x] == dfn[x] ) {
		col[x] = ++ idnum ; 
		while( st[top] != x ) col[st[top --]] = idnum ; 
		-- top ; 
	}
}
void solve() {
	n = gi(), m = gi() ; int x, y, sz = 0 ; 
	rep( i, 1, m ) {
		x = gi(), y = gi() ; 
		if( x != y ) add( x, y ) ;
	}
	rep( i, 1, n ) if( !dfn[i] ) tarjan(i) ;
	rep( i, 1, n ) if( col[i] == 1 ) ++ sz ; 
	if( sz == n ) puts("No") ; 
	else {
		puts("Yes") ; 
		printf("%d %d\n", sz, n - sz ) ;
		rep( i, 1, n ) if( col[i] == 1 ) printf("%d ", i ) ;
		puts("") ; 
		rep( i, 1, n ) if( col[i] != 1 ) printf("%d ", i ) ;
	}
	rep( i, 1, n ) head[i] = dfn[i] = col[i] = low[i] = 0 ; 
	cnt = top = idnum = idnex = 0 ;
}
signed main()
{
	int T = gi() ; 
	while( T-- ) solve() ; 
	return 0 ;
}