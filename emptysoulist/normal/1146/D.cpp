#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define int long long
#define vi vector<int>
#define pb push_back 
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 2e5 + 5 ; 
int m, n, a, b, g, Ans, D, f[N], sz[N], vis[N] ; 
vi G[N] ; 
void add(int x, int y) { G[x].pb(y) ; } 
int S(int x) { return (x * (x + 1)) / 2 ; }
int Sum(int x) {
	int ans = 0 ;
	for(re int j = 0; j < g; ++ j) ans += S((x - j) / g) ; 
	return ans ; 
}
void Dfs(int x) {
	if( !vis[x] ) vis[x] = 1, D += sz[x] ;
	for(int v : G[x]) if(!vis[v]) Dfs(v) ; 
}
signed main()
{
	m = gi(), a = gi(), b = gi(), n = a + b ; 
	vis[0] = 1 ; 
	rep( i, 0, n ) {
		++ sz[i % a] ;
		if( i >= b ) add(i % a, (i - b) % a) ;
		if( vis[i % a] ) ++ D, Dfs(i % a) ; 
		f[i] = D ; 
	}
	g = __gcd(a, b) ; 
	if( m <= n ) {
		rep( i, 0, m ) Ans += f[i] ;
		cout << Ans << endl ; exit(0) ;  
	}
	rep( i, 0, n ) Ans += f[i] ;
	Ans += Sum(m) - Sum(n), Ans += (m - n) ; 
	cout << Ans << endl ; 
	return 0 ;
}