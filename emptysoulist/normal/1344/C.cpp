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
int n, m, dp[N], dp2[N], deg[N], vis[N] ; 
vector<int> G[N], e[N] ; 
void add( int x, int y ) {
	G[x].push_back(y), e[y].push_back(x) ; 
}
queue<int> q ; 
signed main()
{
	n = gi(), m = gi() ; int x, y ; 
	rep( i, 1, m ) x = gi(), y = gi(), add( y, x ) ; 
	rep( i, 1, n ) {
		for( int j : G[i] ) ++ deg[i] ;
		if( !deg[i] ) q.push(i) ; 
	}
	rep( i, 1, n ) dp[i] = i ;
	while( !q.empty() ) {
		int u = q.front() ; q.pop(), vis[u] = 1 ;  
		for( int j : e[u] ) {
			dp[j] = min( dp[j], dp[u] ), -- deg[j] ;
			if( !deg[j] ) q.push(j) ; 
		}
	}
	int flag = 0 ; 
	rep( i, 1, n ) if( !vis[i] ) flag = 1 ;
	if( flag ) {
		puts("-1") ; exit(0) ; 
	}
	rep( i, 1, n ) {
		for( int j : e[i] ) ++ deg[i] ;
		if( !deg[i] ) q.push(i) ;
	} 
	rep( i, 1, n ) dp2[i] = i ;
	while( !q.empty() ) {
		int u = q.front() ; q.pop() ;
		for( int j : G[u] ) {
			dp2[j] = min( dp2[j], dp2[u] ), -- deg[j] ;
			if( !deg[j] ) q.push(j) ;
		}
	}
	flag = 0 ;
	rep( i, 1, n ) {
		if( min( dp[i], dp2[i] ) == i ) ++ flag ; 
	}
	cout << flag << endl ; 
	rep( i, 1, n ) 
	if( min( dp[i], dp2[i] ) == i ) printf("A") ;
	else printf("E") ; 
	return 0 ;
}