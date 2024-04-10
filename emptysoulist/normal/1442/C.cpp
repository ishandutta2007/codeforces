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
const int P = 998244353 ; 
const int N = 2e5 + 5 ; 
const int inf = 1e8 + 7 ; 
const int Inf = 1e7 + 9 ; 
int fpow(int x, int k) {
	int ans = 1, base = x ;
	while(k) {
		if(k & 1) ans = 1ll * ans * base % P ;
		base = 1ll * base * base % P, k >>= 1 ;
	} return ans ;
}
int n, m, dis[N][20][2], vis[N][20][2], f[N] ;
int Ans, Vis[N][2] ; 
struct Node {
	int k, b ; 
} Dis[N][2] ;
vector<int> G[N][2] ; 
struct node {
	int id, k, p ; 
} ;
queue<node> q ; 
void add(int x, int y) {
	G[x][0].pb(y), G[y][1].pb(x) ; 
}
void Dij() {
	rep( i, 0, 18 ) rep( x, 1, n ) 
	dis[x][i][0] = dis[x][i][1] = inf,
	vis[x][i][0] = vis[x][i][1] = 0 ; 
	dis[1][0][0] = 0 ; 
	q.push((node){1, 0, 0}) ;
	while( !q.empty() ) {
		node s = q.front() ; q.pop() ; 
		if( vis[s.id][s.k][s.p] ) continue ; 
		vis[s.id][s.k][s.p] = 1 ; 
		int u = s.id ; 
		for(int v : G[u][s.p]) {
			if( dis[v][s.k][s.p] > dis[u][s.k][s.p] + 1 ) 
				dis[v][s.k][s.p] = dis[u][s.k][s.p] + 1,
				q.push((node){v, s.k, s.p}) ; 
		}
		for(int v : G[u][s.p ^ 1]) {
			if( dis[v][s.k + 1][s.p ^ 1] > dis[u][s.k][s.p] + 1 ) 
				dis[v][s.k + 1][s.p ^ 1] = dis[u][s.k][s.p] + 1,
				q.push((node){v, s.k + 1, s.p ^ 1}) ; 
		}
	}
	int ans = -1 ; 
	for(int i = 0; i <= 18; ++ i) {
		int di = min( dis[n][i][0], dis[n][i][1] ) + f[i] ;
		if( vis[n][i][0] || vis[n][i][1] ) {
			if( ans == -1 ) ans = di ; 
			else ans = min( ans, di ) ;
		}
	}
	if( ans != -1 ) Ans = ans ; 
}
struct zmy {
	int id, k, b, p ; 
	bool operator < (const zmy& x) const {
		return ( k == x.k ) ? b > x.b : k > x.k ; 
	}
} ;
priority_queue<zmy> Q ; 
void SPFA() {
	rep( x, 1, n ) Dis[x][0] = Dis[x][1] = (Node){n + 100, 0} ; 
	rep( x, 1, n ) {
		if( vis[x][18][0] ) 
			Dis[x][0] = (Node){ 18, dis[x][18][0] },
			Q.push((zmy){x, 18, Dis[x][0].b, 0}) ; 
		if( vis[x][18][1] ) 
			Dis[x][1] = (Node){ 18, dis[x][18][1] }, 
			Q.push((zmy){x, 18, Dis[x][1].b, 1}) ; 
		Vis[x][0] = Vis[x][1] = 0 ; 
	}
	while( !Q.empty() ) {
		zmy s = Q.top() ; Q.pop() ;
		if( Vis[s.id][s.p] ) continue ; 
		int u = s.id, p = s.p ; 
		Vis[u][p] = 1 ; 
		for(int v : G[u][p] ) {
			if( Dis[v][p].k > Dis[u][p].k ) {
				Dis[v][p].k = Dis[u][p].k,
				Dis[v][p].b = Dis[u][p].b + 1 ; 
				Q.push((zmy){v, Dis[v][p].k, Dis[v][p].b, p}) ; 
			} 
			if( Dis[v][s.p].k == Dis[u][s.p].k ) {
				if( Dis[v][p].b > Dis[u][p].b + 1 ) {
					Dis[v][p].b = Dis[u][p].b + 1 ; 
					Q.push((zmy){v, Dis[v][p].k, Dis[v][p].b, p}) ; 
				}
			}
		}
		int kk = Dis[u][p].k + 1, bb = Dis[u][p].b + 1 ; 
		for(int v : G[u][p ^ 1]) {
			if( (Dis[v][p ^ 1].k > kk) || ((Dis[v][p ^ 1].k == kk) && (Dis[v][p ^ 1].b > bb)) ) {
				Dis[v][p ^ 1].k = kk, Dis[v][p ^ 1].b = bb ; 
				Q.push((zmy){v, Dis[v][p ^ 1].k, Dis[v][p ^ 1].b, p ^ 1}) ; 
			}
		}
	}
	if( Dis[n][0].k > Dis[n][1].k ) swap( Dis[n][0], Dis[n][1] ) ;
	else if( (Dis[n][0].k == Dis[n][1].k) && (Dis[n][0].b > Dis[n][1].b)) 
	swap( Dis[n][0], Dis[n][1] ) ;
	if( Ans != -1 ) {
		if( Dis[n][0].k >= 25 ) return ; 
		Ans = min( Ans, (1 << Dis[n][0].k) - 1 + Dis[n][0].b ) ; 
	}
	else {
		Ans = fpow(2, Dis[n][0].k) + Dis[n][0].b - 1 ; 
		Ans %= P ; 
	}
}
signed main()
{
	n = gi(), m = gi() ; int x, y ; 
	rep( i, 1, m ) 
		x = gi(), y = gi(), add(x, y) ; 
	f[0] = 0 ; 
	rep( i, 1, 18 ) f[i] = f[i - 1] + (1 << (i - 1)) ; 
	Ans = -1 ; Dij() ; 
	SPFA() ; 
	cout << Ans << endl ; 
	return 0 ;
}