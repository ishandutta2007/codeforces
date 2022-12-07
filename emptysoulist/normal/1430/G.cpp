#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define pb push_back
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 20 ; 
const int inf = 1e16 + 7 ; 
int n, m, cnt, f[N], a[N][N], b[N], w[N], g[1 << 18], bit[1 << 18] ;
long long dp[1 << 18], fr[1 << 18], sum[1 << 18] ; 
bool vis[1 << 18] ; 
vector<int> G[N] ;
void print(int S) {
	if( S == 0 ) return ; 
	print(fr[S]) ;
	++ cnt ; int u = (S ^ fr[S]) ;
	rep( j, 1, n ) {
		if((1 << (j - 1)) & u) b[j] = cnt ; 
	}
}
signed main()
{
	n = gi(), m = gi() ; int x, y, z ; 
	rep( i, 1, m ) {
		x = gi(), y = gi(), z = gi() ; 
		a[x][y] = 1, f[x] += z, f[y] -= z ; 
		G[x].pb(y) ; 
	}
	int lim = (1 << n) - 1 ; 
	rep( i, 0, lim ) {
		rep( j, 1, n ) if( (1 << (j - 1)) & i ) sum[i] += f[j], ++ bit[i] ;  
		rep( j, 1, n ) if( (1 << (j - 1)) & i ) w[j] = 1 ; 
		rep( j, 1, n ) if( (1 << (j - 1)) & i ) {
			for(int v : G[j]) if( w[v] ) vis[i] = 1 ;
			for(int v : G[j]) g[i] |= (1 << (v - 1)) ; 
		}
		rep( j, 1, n ) w[j] = 0 ; 
	}
	memset( dp, 63, sizeof(dp) ) ;
	dp[0] = 0 ;
	rep( S, 1, lim ) {
		for(re int i = S; ; i = (i - 1) & S ) {
			if( vis[i ^ S] || (g[i] & (i ^ S)) ) {
				if( i == 0 ) break ; 
				continue ; 
			}
			if( i == S ) continue ; 
			if( dp[S] > dp[i] + sum[lim ^ i] ) {
				dp[S] = dp[i] + sum[lim ^ i] ;
				fr[S] = i ; 
			}
			if( i == 0 ) break ; 
			continue ; 
		}
	}
	print(lim) ; 
	rep( j, 1, n ) printf("%d ", b[j] ) ;  
	return 0 ;
}