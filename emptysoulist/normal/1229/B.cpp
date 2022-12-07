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
const int N = 1e5 + 5 ; 
const int P = 1e9 + 7 ; 
int n, Ans, a[N], dep[N] ; 
vi G[N] ; 
struct node {
	int l, r, w ; 
} ;
vector<node> f[N] ; 
void add(int x, int y) { G[x].pb(y), G[y].pb(x) ; }
int gcd(int x, int y) {
	if(!x || !y) return x + y ; 
	return gcd(y % x, x) ; 
}
void dfs(int x, int fa) {
	vector<node> g = f[fa] ; dep[x] = dep[fa] + 1 ; 
	int siz = (int)g.size() - 1, bef = a[x] ; 
	for(re int i = siz; i >= 0; -- i)
	g[i].w = gcd(g[i].w, bef), bef = g[i].w ; 
	g.push_back((node){dep[x], dep[x], a[x]}) ;
	node t ; t.w = -1 ; 
	for(node z : g) {
		if(z.w == t.w) t.r = z.r ; 
		else { if(~t.w) f[x].pb(t) ; t = z ; }
	}
	if(~t.w) f[x].pb(t) ; 
	for(node z : f[x]) Ans = (Ans + (z.w) % P * (z.r - z.l + 1) ) % P ; 
	for(int v : G[x]) if(v ^ fa) dfs(v, x) ; 
}
signed main()
{
	n = gi() ; int x, y ; 
	rep( i, 1, n ) a[i] = gi() ; 
	rep( i, 2, n ) x = gi(), y = gi(), add(x, y) ; 
	dfs(1, 1), cout << Ans << endl ; 
	return 0 ;
}