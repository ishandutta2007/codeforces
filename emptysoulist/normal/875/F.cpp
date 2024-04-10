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
int n, m, cnt, d[N], fa[N] ; 
struct E {
	int fr, to, w ; 
} e[N << 1] ;
bool cmp( E x, E y ) { return x.w > y.w ; }
int fd(int x) { return (x == fa[x]) ? x : fa[x] = fd(fa[x]) ; }
signed main()
{
	n = gi(), m = gi() ; int x, y, z ; 
	rep( i, 1, m ) x = gi(), y = gi(), z = gi(), e[++ cnt] = (E){ x, y, z } ;
	sort(e + 1, e + m + 1, cmp) ;
	rep( i, 1, n ) fa[i] = i ; int Ans = 0 ; 
	rep( i, 1, m ) {
		int u = e[i].fr, v = e[i].to ; 
		u = fd(u), v = fd(v) ; 
		if( d[u] && d[v] ) continue ; 
		if( u == v ) d[u] = 1, Ans += e[i].w ; 
		else fa[u] = v, d[v] |= d[u], Ans += e[i].w ; 
	}
	cout << Ans << endl ; 
	return 0 ;
}