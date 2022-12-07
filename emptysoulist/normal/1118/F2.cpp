#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
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
const int P = 998244353 ; 
const int N = 3e5 + 5 ; 
int n, m, fa[N], Col[N], Id[N], a[N], dep[N], f[N][2] ; 
vector<int> G[N] ; 
void add(int x, int y) { G[x].pb(y), G[y].pb(x) ; }
void dfs(int x, int ff) {
	dep[x] = dep[ff] + 1, fa[x] = ff, ++ Col[a[x]] ; 
	for(int v : G[x]) if(v ^ ff) dfs(v, x) ; 
}
bool cmp(int x, int y) { return dep[x] > dep[y] ; }
signed main()
{
	n = gi(), m = gi() ; int x, y ; 
	rep( i, 1, n ) a[i] = gi() ;  
	rep( i, 2, n ) x = gi(), y = gi(), add(x, y) ; 
	dfs(1, 1), Col[0] = 0 ;
	rep( i, 1, n ) Id[i] = i ; 
	sort(Id + 1, Id + n + 1, cmp) ; 
	rep( i, 1, n ) {
		int u = Id[i] ; -- Col[a[u]] ; 
		if(a[u] && Col[a[u]]) {
			if(!a[fa[u]]) a[fa[u]] = a[u], ++ Col[a[u]] ; 
			else if(a[fa[u]] != a[u]) { puts("0") ; exit(0) ; }
		}
		if(a[u]) {
			f[u][0] = 0, f[u][1] = 1 ; 
			for(int v : G[u]) {
				if(v == fa[u]) continue ; 
				if(a[u] != a[v]) 
					f[u][1] = f[u][1] * (f[v][1] + f[v][0]) % P ; 
				else
					f[u][1] = f[u][1] * f[v][1] % P ; 
			}
		}
		else {
			f[u][0] = 1, f[u][1] = 0 ; 
			for(int v : G[u]) {
				if(v == fa[u]) continue ; 
				f[u][1] = (f[u][1] * (f[v][1] + f[v][0]) + f[u][0] * f[v][1]) % P,
				f[u][0] = f[u][0] * (f[v][0] + f[v][1]) % P ; 
			}
		}
	} cout << f[1][1] << endl ; 
	return 0 ;
}