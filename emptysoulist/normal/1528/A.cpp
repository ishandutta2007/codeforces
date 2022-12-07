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
int n, L[N], R[N], dp[N][2] ; 
vi G[N] ; 
void dfs(int x, int fa) {
	for(int v : G[x]) {
		if(v == fa) continue ; 
		dfs(v, x) ; 
		dp[x][0] += max(dp[v][0] + abs(L[v] - L[x]), dp[v][1] + abs(R[v] - L[x])) ; 
		dp[x][1] += max(dp[v][0] + abs(L[v] - R[x]), dp[v][1] + abs(R[v] - R[x])) ; 
	} 
}
signed main()
{
	int t = gi() ; 
	while( t-- ) {
		n = gi() ; int u, v ; 
		rep( i, 1, n ) L[i] = gi(), R[i] = gi() ; 
		rep( i, 2, n ) u = gi(), v = gi(), G[u].pb(v), G[v].pb(u) ; 
		dfs(1, 1) ; 
		cout << max(dp[1][1], dp[1][0]) << endl ; 
		rep( i, 1, n ) G[i].clear(), dp[i][0] = dp[i][1] = 0 ; 
	}
	return 0 ;
}