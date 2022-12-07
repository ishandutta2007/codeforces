#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 2e5 + 5 ; 
int n, m, vis[N], L[N], R[N] ; 
char s[N], w[N] ; 
queue<int> Q ; 
signed main()
{
	n = gi(), m = gi(), scanf("%s", s + 1 ), memset( vis, -1, sizeof(vis) ) ;
	rep( i, 1, n ) L[i] = i - 1, R[i] = i + 1, w[i] = s[i] ; L[1] = n, R[n] = 1 ; 
	rep( i, 1, n ) if( s[L[i]] == s[i] || s[R[i]] == s[i] ) vis[i] = 0, Q.push(i) ;
	while( !Q.empty() ) {
		int u = Q.front() ; Q.pop() ;
		if( vis[L[u]] == -1 ) vis[L[u]] = vis[u] + 1, Q.push(L[u]) ;
		if( vis[R[u]] == -1 ) vis[R[u]] = vis[u] + 1, Q.push(R[u]) ;
	}
	rep( i, 1, n ) {
		if( vis[i] > m || vis[i] == -1 ) ( m & 1 ) ? printf("%c", 'W' + 'B' - s[i] ) : printf("%c", s[i] ) ;
		else ( vis[i] & 1 ) ? printf("%c", 'W' + 'B' - s[i] ) : printf("%c", s[i] ) ;
	}
	return 0 ;
}