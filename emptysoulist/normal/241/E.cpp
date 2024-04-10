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
const int N = 2000 + 5 ; 
const int M = 5000 + 5 ;
struct E {
	int to, next, w ;
} e[M * 2] ;
int n, m, cnt, head[N], dis[N], pax[N], Fr[M], Ed[M], vis[N], tim[N] ; 
void add( int x, int y, int z  ) {
	e[++ cnt] = (E){ y, head[x], z }, head[x] = cnt ;
}
void dfs( int x ) {
	pax[x] = 1 ;
	Next( i, x ) if( !pax[e[i].to]  ) dfs( e[i].to ) ;
}
void dfs2( int x ) {
	pax[x] += 2 ;
	Next( i, x ) if( pax[e[i].to] < 2 ) dfs2( e[i].to ) ;
}
queue<int> q ; 
void SPFA() {
	q.push(1), memset( dis, -63, sizeof(dis) ), dis[1] = 0 ;
	while( !q.empty() ) {
		int u = q.front() ; q.pop(), vis[u] = 0 ;
		Next( i, u ) {
			int v = e[i].to ; 
			if( dis[v] < dis[u] + e[i].w ) {
				dis[v] = dis[u] + e[i].w ;
				if( !vis[v] ) q.push(v), vis[v] = 1, ++ tim[v] ;
				if( tim[v] > n + 10 ) puts("No"), exit(0) ;
			}
		}
	}
}
signed main()
{
	n = gi(), m = gi() ; 
	rep( i, 1, m ) Fr[i] = gi(), Ed[i] = gi(), add( Fr[i], Ed[i], 0 ) ;
	dfs( 1 ), memset( head, 0, sizeof(head) ), cnt = 0, memset( e, 0, sizeof(e) ) ;
	rep( i, 1, m ) add( Ed[i], Fr[i], 0 ) ;
	dfs2( n ), memset( head, 0, sizeof(head) ), cnt = 0, memset( e, 0, sizeof(e) ) ;
	
	rep( i, 1, m ) if( pax[Fr[i]] == 3 && pax[Ed[i]] == 3 ) 
	add( Fr[i], Ed[i], 1 ), add( Ed[i], Fr[i], -2 ) ;
	SPFA() ; printf("Yes\n" ) ;
	
	rep( i, 1, m ) {
		if( pax[Fr[i]] == 3 && pax[Ed[i]] == 3 ) printf("%d\n", dis[Ed[i]] - dis[Fr[i]] ) ;
		else printf("%d\n", 1 ) ;
	}
	return 0 ;
}