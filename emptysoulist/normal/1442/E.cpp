#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define vi vector<int>
#define pb push_back
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 2e5 + 5 ; 
int n, Ans, col[N], f[N][2] ; 
vi G[N] ; 
void add(int x, int y) { G[x].pb(y), G[y].pb(x) ; }
void dfs(int x, int fa) {
	f[x][0] = f[x][1] = 0 ; 
	if( col[x] == 1 ) f[x][0] = 1 ;
	if( col[x] == 2 ) f[x][1] = 1 ; 
	for(int v : G[x]) {
		if(v == fa) continue ; 
		dfs(v, x) ; 
		rep( i, 0, 1 ) rep( j, 0, 1 ) 
			Ans = max( Ans, f[x][i] + f[v][j] - (i == j) ) ;
		if( col[x] == 1 ) 
			f[x][0] = max( f[x][0], max( f[v][0], f[v][1] + 1 ) ) ; 
		else if( col[x] == 2 ) 
			f[x][1] = max( f[x][1], max( f[v][0] + 1, f[v][1] ) ) ;
		else rep( i, 0, 1 ) f[x][i] = max( f[x][i], f[v][i] ) ; 
	}
}
void solve() {
	n = gi(), Ans = 0 ; int x, y ; 
	rep( i, 1, n ) col[i] = gi() ;
	rep( i, 2, n ) x = gi(), y = gi(), add(x, y) ;
	dfs(1, 1) ; 
	cout << (Ans / 2) + 1 << endl ; 
	rep( i, 1, n ) G[i].clear() ; 
}
signed main()
{
	int T = gi() ; 
	while( T-- ) solve() ; 
	return 0 ;
}