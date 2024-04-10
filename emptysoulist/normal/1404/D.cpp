#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define pb push_back
const int N = 1e6 + 5 ; 
vector<int> G[N], Hx[N] ; int n, p, vis[N] ; 
void solve1() {
	puts("First") ; 
	rep( i, 1, n ) cout << i << " " ;
	rep( i, 1, n ) cout << i << " " ;
	puts("") ; 
	cin >> p ; 
} 
void add(int x, int y) { G[x].pb(y), G[y].pb(x) ; }
void dfs(int x, int type) {
	vis[x] = type ; 
	for(int v : G[x]) {
		if( vis[v] != -1 ) continue ; 
		dfs(v, type ^ 1) ; 
	}
}
void solve2() {
	puts("Second") ; int x ; 
	rep( i, 1, n ) add(i, i + n) ;
	rep( i, 1, n + n ) cin >> x, Hx[x].pb(i) ;
	rep( i, 1, n ) add( Hx[i][0], Hx[i][1] ) ;
	memset( vis, -1, sizeof(vis) ) ; 
	rep( i, 1, n ) if( vis[i] == -1 ) dfs(i, 0) ;
	int ans = 0 ; n = n + n ; 
	rep( i, 1, n ) if( vis[i] == 0 ) ans += i, ans %= n ; 
	if( ans == 0 ) {
		rep( i, 1, n ) if( vis[i] == 0 ) printf("%d ", i ) ;
	}
	else {
		rep( i, 1, n ) if( vis[i] == 1 ) printf("%d ", i ) ; 
	} puts(""), cin >> p ; 
}
signed main()
{
	fflush(stdout) ;
	cin >> n ;  
	if( n & 1 ) solve2() ;
	else solve1() ; 
	return 0 ;
}