#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 2e5 + 5 ; 
const int P = 2333333 ; 
int n, m, K, Ty, deg[N], vis[N], ST[N], num ; 
vi G[N] ; 
priority_queue<pair<int, int>> q ; // 
struct hashmap {
	static const int N = 1e6 + 61, P = 999983;
	struct node {
		int next ; long long key ;
	} e[N];
	int head[N], cnt, st[N], top ;
	inline void ins(long long x) {
		int hsh = 1ll * x % P + 1;
		for (int i = head[hsh]; i; i = e[i].next)
			if (e[i].key == x) return ;
		e[++cnt] = (node){head[hsh], x}, head[hsh] = cnt;
		st[++ top] = hsh ; 
	}
	inline void clear() { 
		cnt = 0 ; rep( i, 1, top ) head[st[i]] = 0 ; top = 0 ; 
	}
	inline int query(long long x) {
		int hsh = 1ll * x % P + 1;
		for (int i = head[hsh]; i; i = e[i].next)
			if (e[i].key == x) return 1 ; 
		return 0 ; 
	}
} tab ;
vector<int> ans ; 
void Dfs(int x) {
	vis[x] = 1, ans.pb(x) ; 
	if( Ty ) for(int v : G[x]) if( !vis[v] ) printf("fuck go this %d -> %d\n", x, v ) ; 
	for(int v : G[x]) if(!vis[v]) Dfs(v) ; 
}
void solve() {
	n = gi(), m = gi(), K = gi() ; 
	if( K > 450 ) { puts("-1") ; exit(0) ; }
	int x, y, type = 0 ; 
	rep( i, 1, m ) 
		x = gi(), y = gi(), G[x].pb(y), G[y].pb(x), ++ deg[x], ++ deg[y],
		tab.ins(1ll * x * n + y), tab.ins(1ll * y * n + x) ; 
	rep( i, 1, n ) q.push(mp(-deg[i], i)) ; // printf("??? %d %d\n", deg[i], i ) ;
	int ctt = 0 ; 
	while( !q.empty() ) {
		if( !ans.empty() ) break ; 
		pi u = q.top() ; q.pop() ; 
//		if( Ty && u.se == 54 ) printf("??? fuck %d %d\n", u.fi, u.se ) ; 
		if( vis[u.se] ) continue ; 
		int D = -u.fi ; 
		
		if( D == K - 1 ) {
			num = 0 ; ST[++ num] = u.se ; 
			for(int v : G[u.se]) if( !vis[v] ) ST[++ num] = v ; 
			int flag = 1 ; ctt += K * K ; 
			for(re int i = 1; i < num; ++ i)
			for(re int j = i + 1; j <= num; ++ j) {
				flag &= tab.query(1ll * ST[i] * n + ST[j]) ; 
			}
			if( flag ) { rep( j, 1, num ) ans.pb(ST[j]) ; type = 2 ; break ; } 
		}
		else if( D >= K ) {
		//	if( Ty )printf("???fuck %d %d\n", u.se, D ) ; 
			type = 1, Dfs(u.se) ; break ; 
		}
		vis[u.se] = 1 ; 
		for(int v : G[u.se]) {
			-- deg[v], q.push(mp(-deg[v], v)) ;
		//	if( v == 54 && Ty ) printf("??? fuck del %d %d\n", deg[v], v ) ; 
		}
		if( ctt >= 2e7 ) {
			printf("%d\n", ctt ) ; exit(0) ;  
		}
	}
	if( !type ) puts("-1") ; 
	else {
		if( type == 1 ) printf("1 %d\n", (int)ans.size() ) ;
		else puts("2") ; 
		for(int u : ans) printf("%d ", u ) ; puts("") ;  
	}
	rep( i, 1, n ) G[i].clear(), vis[i] = deg[i] = 0 ; 
	ans.clear() ; tab.clear() ; 
	while( !q.empty() ) q.pop() ; 
}
signed main()
{
	int T = gi() ; 
	while( T-- ) solve() ; 
	return 0 ;
}