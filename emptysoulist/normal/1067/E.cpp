#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define vi vector<int>
#define pb push_back
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 5e5 + 5 ; 
const int P = 998244353 ; 
int n, Ans, sz[N], fac[N], f[N][2] ; 
vi G[N] ; 
void add(int x, int y) { G[x].pb(y), G[y].pb(x) ; }
void dfs(int x, int fa) {
	sz[x] = 1, f[x][0] = 1 ; 
	for(int v : G[x]) {
		if( v == fa ) continue ; 
		dfs(v, x), sz[x] += sz[v] ; 
		f[x][0] = f[x][0] * (f[v][0] + f[v][1] + f[v][1]) % P ; 
	}
	f[x][1] = (fac[sz[x] - 1] - f[x][0] + P) % P ; 
	Ans = (Ans + f[x][1] * fac[n - sz[x]]) % P ; 
}
signed main()
{
	n = gi() ; int x, y ; 
	rep( i, 2, n ) x = gi(), y = gi(), add(x, y) ; 
	fac[0] = 1 ; 
	rep( i, 1, n ) fac[i] = fac[i - 1] * 2 % P ; 
	dfs(1, 1) ; 
	cout << Ans * 2 % P << endl ; 
	return 0 ;
}