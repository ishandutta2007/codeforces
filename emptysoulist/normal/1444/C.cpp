#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 1e6 + 5 ; 
int n, m, k, cnt, num, vis[N], c[N], fa[N], sz[N] ; 
int Ans ; 
struct node {
	int u, v ; 
} e[N] ; 
vi G[N] ; 
vector<node> f[N] ; 
map<pair<int, int>, int> Id ; 
int fd(int x) {
	return (x == fa[x]) ? x : fd(fa[x]) ; 
}
void merge(int x, int y) {
	int u = fd(x), v = fd(y) ;
	if( u == v ) return ; 
	if( sz[u] > sz[v] ) swap(u, v) ;
	fa[u] = v, sz[v] += sz[u] ; 
}
int st[N], stf[N], top ; 
int ft[N], ftf[N] ; 
void Merge(int x, int y) {
	int u = fd(x), v = fd(y) ;
	if( u == v ) return ; 
	if( sz[u] > sz[v] ) swap(u, v) ;
	st[++ top] = u, stf[top] = fa[u], 
	ft[top] = v, ftf[top] = sz[v] ;
	fa[u] = v, sz[v] += sz[u] ; 
}
void solve() {
	for(auto z : Id) {
		int ip = z.second ; 
		pair<int, int> t = z.first ; 
		if( vis[t.first] || vis[t.second] ) continue ; 
		int flag = 0 ; 
		for(node u : f[ip]) {
			int x = u.u, y = u.v ; 
			Merge(x + n, y), Merge(x, y + n) ; 
			if( fd(x) == fd(x + n) ) flag = 1 ;
			if( fd(y) == fd(y + n) ) flag = 1 ; 
		}
		Ans -= flag ; 
		while( top ) 
			fa[st[top]] = stf[top], 
			sz[ft[top]] = ftf[top],
			-- top ; 
	}
}
signed main()
{
	n = gi(), m = gi(), k = gi() ; 
	rep( i, 1, n ) c[i] = gi(), G[c[i]].pb(i) ; 
	rep( i, 1, 2 * n ) fa[i] = i, sz[i] = 1 ; 
	rep( i, 1, m ) {
		e[i].u = gi(), e[i].v = gi() ; 
		int x = e[i].u, y = e[i].v ; 
		if( c[x] == c[y] ) {
			merge(x + n, y), merge(x, y + n) ; 
			if(fd(x) == fd(x + n)) vis[c[x]] = 1 ; 
			if(fd(y) == fd(y + n)) vis[c[x]] = 1 ; 
		}
		else {
			if(c[x] > c[y]) swap(x, y) ; 
			if( !Id[mp(c[x], c[y])] ) Id[mp(c[x], c[y])] = ++ cnt ; 
			int z = Id[mp(c[x], c[y])] ; 
			f[z].pb((node){x, y}) ; 
		}
	}
	Ans = 0 ; 
	rep( i, 1, k ) if( !vis[i] ) ++ Ans ; 
	Ans = (Ans * (Ans - 1)) / 2 ; 
	solve() ; 
	cout << Ans << endl ; 
	return 0 ;
}