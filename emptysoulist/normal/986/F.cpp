#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int inf = 1e15 + 7 ; 
const int N = 3.5e7 + 5 ; 
const int M = 1e5 + 5 ; 
const int K = 15 ; 
int n, m, tk, ans[M], st[K], dis[M] ;
int vis[M], num, top, p[N / 10] ; 
bool isp[N] ; 
struct node {
	int id, w, k ; 
} Q[M] ; 
bool cmp(node x, node y) { return x.k < y.k ; }
void init(int x) {
	for(re int i = 2; i <= x; ++ i) {
		if(!isp[i]) p[++ top] = i ;
		for(re int j = 1; j <= top && p[j] * i <= x; ++ j) {
			isp[i * p[j]] = 1 ; 
			if(i % p[j] == 0) break ; 
		}
	}
}
void Make(int x) {
	num = 0 ;
	for(re int i = 1; i <= top && p[i] <= sqrt(x); ++ i) {
		if( x % p[i] ) continue ; 
		while( x % p[i] == 0 ) x /= p[i] ; 
		st[++ num] = p[i] ; 
	}
	if( x != 1 ) st[++ num] = x ;  
}
queue<int> q ; 
void SPFA() {
	rep( i, 0, st[1] ) dis[i] = inf, vis[i] = 0 ; 
	dis[0] = 0, q.push(0) ; 
	while(!q.empty()) {
		int u = q.front() ; q.pop(), vis[u] = 0 ;
		rep( i, 2, num ) {
			int v = (u + st[i]) % st[1] ; 
			if( dis[v] > dis[u] + st[i] ) {
				dis[v] = dis[u] + st[i] ;
				if(!vis[v]) vis[v] = 1, q.push(v) ; 
			}
		}
	}
} 
void Dij() {
	sort( st + 1, st + num + 1 ), SPFA() ; 
}
void exgcd(int a, int b, int &x, int &y) {
	if(!b) { x = 1, y = 0 ; return ; }
	exgcd(b, a % b, y, x), y -= (a / b) * x;
}
int get(int v, int a, int b) {
	int x, y ; exgcd(a, b, x, y);
	x = ((v % b) * x % b + b) % b;
	return (v - x * a >= 0) ;
}
signed main()
{
	m = gi() ; init(N - 5) ;
	rep( i, 1, m ) Q[i].id = i, Q[i].w = gi(), Q[i].k = gi() ; 
	sort(Q + 1, Q + m + 1, cmp) ; 
	for(re int l = 1, r; l <= m; l = r) {
		r = l, Make(Q[l].k) ; 
		if( num >= 3 ) Dij() ; 
		while( Q[r].k == Q[l].k ) {
			if( num >= 3 ) ans[Q[r].id] = (Q[r].w >= dis[Q[r].w % st[1]]) ;
			if( num == 1 ) ans[Q[r].id] = ((Q[r].w % st[1]) == 0) ; 
			if( num == 2 ) ans[Q[r].id] = get(Q[r].w, st[1], st[2]) ;
			if( Q[r].k == 1 ) ans[Q[r].id] = 0 ; 
			++ r ; 
		}
	}
	rep( i, 1, m ) (ans[i]) ? puts("YES") : puts("NO") ; 
	return 0 ;
}