#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( int i = (t); i >= (s); -- i )
#define pi pair<int, int>
#define pb push_back
#define vi vector<int>
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 5e5 + 5 ; 
int n, m, cnt, num, qwq, p[N], q[N], head[N], deg[N], vis[N], op[N] ; 
struct E { int to, next ; } e[N << 1] ; 
struct node { int x, y ; } s[N << 1] ;
void add(int x, int y) {
	e[++ cnt] = (E){ y, head[x] }, head[x] = cnt,
	e[++ cnt] = (E){ x, head[y] }, head[y] = cnt ; 
}
vector<int> G[N], son[N] ; 
set<int> S ; 
set<int>::iterator it ; 
queue<int> Q ;
void ADD(int x, int y) { G[x].pb(y), G[y].pb(x) ; }
int DFS(int x, int fa) {
	int flag = 0, ip = 0 ; 
	if(x != fa) {
		for(int v : G[x]) {
			if(v == fa) continue ; 
			int z = DFS(v, x) ; 
			if(!z) son[x].pb(v), flag = 1 ; 
		}
	} 
	else {
		for(int v : G[x]) {
			if(v == fa) continue ; 
			int z = DFS(v, x) ; 
			if(!z) son[x].pb(v), flag = 1 ; 
			else ip = v ; 
		} if(!flag) son[ip].pb(x) ; 
	}  return flag ; 
} 
signed main()
{
	int T = gi() ; 
	while(T--) {
		n = gi(), m = gi() ; 
		rep( i, 1, m ) { 
			int x = gi(), y = gi() ; 
			s[++ num] = (node){ x, y }, ++ deg[x], ++ deg[y] ; 
		} 
		rep( i, 1, n ) if(deg[i] == n - 1)
			p[i] = q[i] = ++ qwq, op[i] = 1 ; 
		rep( i, 1, num ) 
			if((deg[s[i].x] != n - 1) && (deg[s[i].y] != n - 1))
				add(s[i].x, s[i].y) ; 
		rep( i, 1, n ) if(deg[i] != n - 1) S.insert(i) ; 
		rep( u, 1, n ) {
			if(op[u]) continue ; 
			op[u] = 1, Q.push(u) ; 
			S.erase(u) ; vector<int> DEL ; 
			while(!Q.empty()) {
				int x = Q.front() ; Q.pop() ; 
				Next( i, x ) vis[e[i].to] = 1 ; 
				for(it = S.begin(); it != S.end(); ++ it) {
					int v = (*it) ; if(vis[v]) continue ; 
					Q.push(v), DEL.pb(v), op[v] = 1, ADD(x, v) ; 
				} 
				for(int v : DEL) S.erase(v) ; DEL.clear() ; 
				Next( i, x ) vis[e[i].to] = 0 ; 
			} DFS(u, u) ; 
		} 
		S.clear() ; 
		rep( i, 1, n ) {
			if(deg[i] == n - 1) continue ; 
			if(son[i].empty()) continue ; 
			int l = qwq + 1, r = qwq + son[i].size() + 1 ; 
			p[i] = l, q[i] = r, ++ qwq ; 
			for(int v : son[i]) 
				p[v] = ++ qwq, q[v] = qwq - 1 ; 
		} int ans = 0 ; 
		rep( i, 1, n ) if(deg[i] != n - 1) ++ ans ; 
		rep( i, 1, n ) printf("%d ", p[i] ) ; puts("") ; 
		rep( i, 1, n ) printf("%d ", q[i] ) ; puts("") ; 
		qwq = cnt = num = 0 ; 
		rep( i, 1, n ) head[i] = op[i] = deg[i] = p[i] = q[i] = 0 ; 
		rep( i, 1, n ) G[i].clear(), son[i].clear() ; 
	}
	return 0 ;
}