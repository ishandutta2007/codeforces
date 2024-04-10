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
int n, m, w[N], deg[N], vis[N], head[N], st[N], Go[N], top, cnt ; 
struct E { int to, next, id ; } e[N << 1] ; 
void add( int x, int y, int id ) {
	e[++ cnt] = (E){ y, head[x], id }, head[x] = cnt,
	e[++ cnt] = (E){ x, head[y], id }, head[y] = cnt ; 
}
queue<int> q ; 
void clear( int x ) {
	Next( i, x ) {
		int v = e[i].id ; 
		if( !vis[v] ) st[++ top] = v, vis[v] = 1 ; 
	}
}
signed main()
{
	n = gi(), m = gi() ; int x, y ; 
	rep( i, 1, n ) w[i] = gi() ; 
	rep( i, 1, m ) x = gi(), y = gi(), add( x, y, i ), ++ deg[x], ++ deg[y] ; 
	rep( i, 1, n ) if( deg[i] <= w[i] ) q.push(i), clear(i), Go[i] = 1 ; 
	while( !q.empty() ) {
		int u = q.front() ; q.pop() ; 
		Next( i, u ) {
			int v = e[i].to ; -- deg[v] ; 
			if( deg[v] <= w[v] && !Go[v] ) 
			Go[v] = 1, q.push(v), clear(v) ; 
		}
	}
	if( top != m ) { puts("DEAD") ; exit(0) ; }
	puts("ALIVE") ;
	drep( i, 1, top ) {
		printf("%d ", st[i] ) ; 
	}
	return 0 ;
}