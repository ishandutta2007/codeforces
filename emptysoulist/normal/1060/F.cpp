#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define pb push_back
#define re register
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 100 + 5 ; 
long double f[N][N], g[N], d[N], fac[N], C[N][N], ans[N] ; 
int n, sz[N] ; vector<int> G[N] ; 
void add(int x, int y) {
	G[x].pb(y), G[y].pb(x) ; 
}
void Dfs(int x, int fa) {
	sz[x] = 1, f[x][0] = 1 ; 
	for(int v : G[x]) {
		 if( v == fa ) continue ; 
		Dfs(v, x) ; 
		rep( j, 0, n ) d[j] = g[j] = 0 ; 
		rep( j, 0, sz[v] ) rep( k, 1, sz[v] ) {
			if( k <= j ) g[j] += f[v][k - 1] * 0.5 ; 
			else if( j != 0 ) g[j] += f[v][j] ; 
		}
		g[0] = fac[sz[v]] ; 
		int m = sz[x] + sz[v] - 1 ; 
		rep( j, 0, sz[v] ) rep( k, 0, sz[x] - 1 ) 
		d[j + k] += C[j + k][j] * C[m - (j + k)][sz[v] - j] * f[x][k] * g[j] ; 
		rep( j, 0, n ) f[x][j] = d[j] ; 
		sz[x] += sz[v] ; 
	}
} 
void solve(int x) {
	memset( f, 0, sizeof(f) ) ; 
	Dfs(x, x), ans[x] = f[x][n - 1] / fac[n - 1] ;
}
signed main()
{
	n = gi() ; int x, y ; 
	rep( i, 2, n ) x = gi(), y = gi(), add(x, y) ;
	C[0][0] = 1, fac[0] = 1 ; 
	rep( i, 1, n ) fac[i] = 1.0 * fac[i - 1] * i ; 
	rep( i, 1, n ) rep( j, 0, n ) 
	(!j) ? C[i][j] = 1 : C[i][j] = C[i - 1][j - 1] + C[i - 1][j] ; 
	rep( i, 1, n ) solve(i) ; 
	rep( i, 1, n ) printf("%.10Lf\n", ans[i] ) ;  
	return 0 ;
}