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
const int N = 3000 + 5 ; 
int n, m ; 
long long sum[N], Ans ; 
vector<long long> f[N] ; 
void solve(int l, int r, vector<long long> dp) {
	if(l == r) {
		for(re int i = 0; i < min(m, (int)f[l].size()); ++ i) 
			Ans = max( Ans, dp[m - i - 1] + f[l][i]) ;
		return ; 
	}
	int mid = (l + r) >> 1 ; 
	vector<long long> g ; g = dp ; 
	for(re int i = mid + 1; i <= r; ++ i) {
		int u = f[i].size() ; long long s = sum[i] ; 
		for(re int j = m; j >= u; -- j )
			g[j] = max(g[j], g[j - u] + s) ;
	}
	solve(l, mid, g) ;
	g = dp ;
	for(re int i = l; i <= mid; ++ i) {
		int u = f[i].size() ; long long s = sum[i] ; 
		for(re int j = m; j >= u; -- j )
			g[j] = max(g[j], g[j - u] + s) ;
	}
	solve(mid + 1, r, g) ; 
} 
signed main()
{
	n = gi(), m = gi() ; int x, y ; 
	rep( i, 1, n ) {
		x = gi() ; 
		rep( j, 1, x ) y = gi(), sum[i] += 1ll * y, f[i].pb(y) ; 
		if( x >= m ) {
			long long z = 0 ;
			for(re int j = 0; j < m; ++ j) z += f[i][j] ; 
			Ans = max( Ans, z ) ;
		}
		for(re int j = 1; j < f[i].size(); ++ j) f[i][j] += f[i][j - 1] ; 
	}
	vector<long long> dp ; 
	dp.resize(m + 1) ; 
	solve(1, n, dp) ; 
	cout << Ans << endl ; 
	return 0 ;
}