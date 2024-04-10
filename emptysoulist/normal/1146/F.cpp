#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define vi vector<int>
#define int long long
#define pb push_back
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int P = 998244353 ; 
const int N = 2e5 + 5 ; 
int n, dp[N][4], Dp[N] ; 
vi G[N] ; 
void add(int x, int y) { G[x].pb(y) ; }
void dfs(int x) {
	dp[x][0] = 1 ; int fl = 0 ; 
	for(int v : G[x]) {
		dfs(v), fl = 1 ; 
		dp[x][2] = (dp[x][2] * Dp[v] % P + (dp[x][1] + dp[x][2]) * (dp[v][1] + dp[v][2])) % P ; //0 + 1
		dp[x][1] = (dp[x][1] * Dp[v] % P + dp[x][0] * (dp[v][1] + dp[v][2])) % P ; //0 + 1
		dp[x][0] = dp[x][0] * Dp[v] % P ; //0
	}
	if( !fl ) dp[x][0] = 0, dp[x][2] = 1 ; 
	Dp[x] = (dp[x][0] + dp[x][2]) % P ; 
}
signed main()
{
	n = gi() ; int x ; 
	rep( i, 2, n ) x = gi(), add(x, i) ; 
	dfs(1) ; 
	cout << Dp[1] << endl ; 
	return 0 ;
}