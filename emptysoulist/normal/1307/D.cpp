#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 2e5 + 5 ;
int n, m, S, cnt, a[N], vis[N], dis[2][N], head[N], pre[2][N], nxt[2][N] ; 
struct E {
	int to, next ; 
} e[N] ;

// max( min( x.a + y.b, x.b + y.a ) + 1 ) 
void add( int x, int y ) {
	e[++ cnt] = (E){ y, head[x] }, head[x] = cnt ; 
	e[++ cnt] = (E){ x, head[y] }, head[y] = cnt ; 
}
queue<int> q ; 
void bfs( int x, int k ) {
	q.push(x) ; dis[k][x] = 0 ;
	while( !q.empty() ) {
		int u = q.front() ; q.pop() ; 
		Next( i, u ) {
			int v = e[i].to ; 
			if( dis[k][v] > dis[k][u] + 1 )
			dis[k][v] = dis[k][u] + 1, q.push(v) ;
		}
	}
}
bool cmp( int x, int y ) {
	return ( dis[0][x] - dis[1][x] ) < ( dis[0][y] - dis[1][y] ) ; 
}
signed main()
{
	n = gi(), m = gi(), S = gi() ; int x, y ;
	rep( i, 1, S ) a[i] = gi() ; 
	rep( i, 1, m ) x = gi(), y = gi(), add( x, y ) ;
	memset( dis, 63, sizeof(dis) ) ;
	bfs( 1, 0 ), bfs( n, 1 ) ;
	sort( a + 1, a + S + 1, cmp ) ;
	int ans = 0, bef = dis[0][a[1]] ;
	rep( i, 2, S ) {
		ans = max( ans, bef + dis[1][a[i]] + 1 ) ;
		bef = max( bef, dis[0][a[i]] ) ;
	}
	ans = min( ans, dis[0][n] ) ;
	printf("%lld\n", ans ) ;
	return 0 ;
}