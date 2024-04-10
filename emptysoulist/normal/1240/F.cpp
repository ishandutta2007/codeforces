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
const int N = 205 ; 
const int M = 4005 ; 
map<pair<int, int>, int> Id ; 
struct node { int x, y, col ; } e[M] ; 
int n, m, K, cur[N], deg[N], f[M] ; 
int cnt, vis[M], ans[M], num ; 
struct Edge {
	int to, next, id ; 
} E[M] ;
int sw(int x) { return (1ll * rand() << 16ll ^ rand()) % x + 1 ; }
void add(int x, int y) { 
	E[++ cnt] = (Edge){ y, cur[x], cnt }, cur[x] = cnt, 
	E[++ cnt] = (Edge){ x, cur[y], cnt }, cur[y] = cnt,
	++ deg[x], ++ deg[y] ; 
}
void DFS(int x) { 
	for(int &i = cur[x]; i; i = E[i].next) {
		int v = E[i].to, p = E[i].id ; if(vis[p]) continue ; 
		vis[p] = vis[p ^ 1] = 1, 
		DFS(v), ans[++ num] = Id[mp(x, v)] ; 
	} 
}
signed main()
{
	n = gi(), m = gi(), K = gi() ; int x, y ; 
	rep( i, 1, n ) x = gi() ; 
	rep( i, 1, m ) 
		x = gi(), y = gi(), e[i] = (node){x, y, sw(K)},
		Id[mp(x, y)] = Id[mp(y, x)] = i ; 
	int qwq = 5 ; 
	while(qwq--) {
		rep( u, 1, n ) { 
			while(1) {
				int mi = m + 1, mx = 0 ; 
				rep( i, 1, K ) f[i] = 0 ; 
				rep( j, 1, n ) {
					if(!Id[mp(u, j)]) continue ; 
					int v = Id[mp(u, j)] ; ++ f[e[v].col] ; 
				}
				rep( i, 1, K ) mi = min(mi, f[i]), mx = max(mx, f[i]) ; 
				if(mx - mi <= 2) break ;
				int ip1 = 0, ip2 = 0 ; cnt = 1 ; 
				rep( i, 1, K ) if(f[i] == mi) ip1 = i ;
				rep( i, 1, K ) if(f[i] == mx) ip2 = i ; 
				rep( i, 0, n ) deg[i] = cur[i] = 0 ; 
				rep( i, 1, m ) {
					if(e[i].col == ip1) add(e[i].x, e[i].y) ; 
					if(e[i].col == ip2) add(e[i].x, e[i].y) ; 
				} 
				rep( i, 1, n ) {
					if(deg[i] & 1) add(0, i) ;
					else add(0, i), add(0, i) ; 
				}
				rep( i, 0, cnt ) vis[i] = 0 ; 
				num = 0, DFS(0) ; 
				for(int i = 1; i <= num; ++ i) {
					if(i & 1) e[ans[i]].col = ip1 ; 
					else e[ans[i]].col = ip2 ; 
				}
			}
		}
	}
	rep( i, 1, m ) printf("%d\n", e[i].col ) ; 
	return 0 ;
}