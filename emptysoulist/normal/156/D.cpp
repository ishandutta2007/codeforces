#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( int i = (t); i >= (s); -- i )
#define mp make_pair
#define pi pair<int, int>
#define pb push_back
#define vi vector<int>
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 1e5 + 5 ; 
int n, m, vis[N], p, num, K ; 
vi G[N] ; 
void add(int x, int y) { G[x].pb(y), G[y].pb(x) ; }
void dfs(int x) {
	if(vis[x]) return ; num ++, vis[x] = 1 ; 
	for(int v : G[x]) dfs(v) ; 
}
signed main()
{
	n = gi(), m = gi(), p = gi() ; int x, y ; 
	rep( i, 1, m ) x = gi(), y = gi(), add(x, y) ; 
	int ans = 1 ; 
	rep( i, 1, n ) if(!vis[i]) ++ K, dfs(i), ans = ans * num % p, num = 0 ; 
	if(K == 1) cout << 1 % p << endl ; 
	else {
		for(int i = 1; i <= K - 2; ++ i) ans = ans * n % p ; 
		cout << ans % p << endl ; 
	} 
	return 0 ;
}