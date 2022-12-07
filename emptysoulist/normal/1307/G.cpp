#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( int i = (t); i >= (s); -- i )
#define mp make_pair
#define pi pair<int, int>
#define pb push_back
#define vi vector<int>
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int inf = 1e8 ; 
const int N = 55 ; 
const int M = 2505 ; 
int n, m, cnt, head[N], cur[N], dis[N], vis[N] ; 
struct E {
	int to, next, w, f ; 
} e[M << 1] ;  
void add(int x, int y, int w, int f) {
	e[++ cnt] = (E){ y, head[x], w, f }, head[x] = cnt,
	e[++ cnt] = (E){ x, head[y], 0, -f }, head[y] = cnt ; 
}
queue<int> q ; 
int SPFA() {
	rep( i, 1, n ) dis[i] = inf ; dis[1] = 0, vis[1] = 0, q.push(1) ; 
	while(!q.empty()) {
		int u = q.front() ; q.pop(), vis[u] = 0 ; 
		Next( i, u ) {
			int v = e[i].to ; 
			if(e[i].w && dis[v] > dis[u] + e[i].f) {
				dis[v] = dis[u] + e[i].f ;
				if(!vis[v]) vis[v] = 1, q.push(v) ; 
			}
		}
	} 
	return (dis[n] != inf) ; 
}
int Ans, F[N], mark[N] ; 
int DFS(int x, int dist) {
	if(x == n) return dist ; int flow = 0 ; mark[x] = 1 ; 
	for(int &i = cur[x]; i; i = e[i].next) {
		int v = e[i].to ; 
		if((e[i].w) && (!mark[v]) && (dis[v] == dis[x] + e[i].f)) {
			int di = DFS(v, min(dist, e[i].w)) ; 
			if(di > 0) {
				e[i].w -= di, e[i ^ 1].w += di,
				Ans += di * e[i].f, dist -= di, flow += di ; 
				if(!dist) return flow ; 
			}
		}
	} return flow ; 
}
signed main()
{
	n = gi(), m = gi() ; int x, y, z ; cnt = 1 ; 
	rep( i, 1, m ) 
		x = gi(), y = gi(), z = gi(), add(x, y, 1, z) ; 
	int num = 0 ; 
	while(SPFA()) {
		rep( i, 1, n ) cur[i] = head[i], mark[i] = 0 ; 
		++ num, DFS(1, 1), F[num] = Ans ; 
	} double ans = 0 ; 
	int T = gi() ; 
	while(T--) {
		x = gi() ; ans = inf ; 
		rep( i, 1, num ) ans = min(ans, (1.0 * (x + F[i]) / (1.0 * i))) ; 
		printf("%.7lf\n", ans ) ; 
	}
	return 0 ; 
}