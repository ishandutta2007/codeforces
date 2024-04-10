#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define pb push_back
#define pi pair<int, int>
#define mp make_pair
#define fi first
#define se second
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 100 + 5 ; 
int n, t[N], vis[N] ; 
struct Bit {
	bitset<105> a ; int id ; 
	bool operator < (const Bit &x) const {
		drep( i, 0, n ) if( x.a[i] != a[i] ) return a[i] < x.a[i] ; 
		return 0 ; 
	}
	int count() {
		drep( i, 0, n ) if( a[i] ) return i ;
		return -1 ; 
	}
} f[N] ; 
struct E { int x, y ; } e[N] ;
map<pi, int> col ; 
priority_queue<Bit> q ; 
vector<int> G[N] ; 
void add(int x, int y) { G[x].pb(y), G[y].pb(x) ; }
bool check(vector<Bit> g) {
	for(auto z : g) q.push(z) ; 
	if( q.empty() ) return 1 ; 
	for(re int i = n; i >= 0; -- i) {
		if( !t[i] ) continue ; 
		Bit u = q.top() ; q.pop() ; 
		int now = u.count() ; 
		if( now > i ) break ; 
		else if( now == i ) u.a[now] = 0, q.push(u) ; 
		if( q.empty() ) return 1 ; 
	}
	while( !q.empty() ) q.pop() ; 
	return 0 ; 
}
void Rebuilt(int x, vector<Bit> g) {
	for(auto z : g) q.push(z) ; 
	if( q.empty() ) return ; 
	for(re int i = n; i >= 0; -- i) {
		if( !t[i] ) continue ; 
		Bit u = q.top() ; q.pop() ; 
		int now = u.count() ; 
		if( now == i ) u.a[now] = 0, q.push(u) ;
		else col[mp(u.id, x)] = col[mp(x, u.id)] = i ; 
		if( q.empty() ) return ; 
	}
	while( !q.empty() ) q.pop() ; 
}
void dfs(int x, int fa) {
	vector<Bit> g ; f[x].id = x ; 
	for(int v : G[x]) {
		if( fa == v ) continue ; 
		dfs(v, x), g.pb(f[v]) ; 
	}
	rep( i, 0, n ) t[i] = 1 ; 
	drep( i, 0, n ) { t[i] = 0 ; if( !check(g) ) t[i] = 1 ; }
	rep( i, 0, n ) f[x].a[i] = t[i] ; 
	Rebuilt(x, g) ;
}
int mx ; pi id ;  
void Dfs(int x, int fa) {
	for(int v : G[x]) {
		if( vis[v] || v == fa ) continue ; 
		int k = col[mp(x, v)] ; 
		if( k > mx ) mx = k, id = mp(x, v) ; 
		Dfs(v, x) ; 
	} 
}
void solve(int x, int fa) {
	mx = -1, Dfs(x, fa) ; 
	if( mx == -1 ) { printf("! %d\n", x ) ; fflush(stdout) ; exit(0) ; }
	printf("? %d %d\n", id.fi, id.se ) ; fflush(stdout) ;
	int r = gi() ; 
	if( r == id.fi ) vis[id.se] = 1, solve(id.fi, id.fi) ;
	else vis[id.fi] = 1, solve(id.se, id.se) ; 
}
signed main()
{
	n = gi() ; int x, y ; 
	rep( i, 2, n ) x = gi(), y = gi(), e[i] = (E){ x, y }, add(x, y) ; 
	dfs(1, 1), solve(1, 1) ; 
	return 0 ;
}