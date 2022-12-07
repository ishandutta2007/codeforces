// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
int read() {
	char cc = getchar(); int cn = 0, flus = 1;
	while(cc < '0' || cc > '9') {  if( cc == '-' ) flus = -flus;  cc = getchar();  }
	while(cc >= '0' && cc <= '9')  cn = cn * 10 + cc - '0', cc = getchar();
	return cn * flus;
}
const int N = 500000 + 5 ; 
struct E {
	int to, next, w ; 
} e[N * 2] ;
struct node {
	int id, w ; 
} rev[N] ;
int tot, cnt, Ans[N], head[N], n, q, son[N], sz[N], vis[N], dep[N], w[N] ; 
bool dw[N][27] ; 
char sc[N] ; 
vector<node> Q[N] ; 
void add( int x, int y ) {
	e[++ cnt] = (E){ y, head[x] }, head[x] = cnt ; 
}
void dfs( int x, int fa ) {
	sz[x] = 1 ; dep[x] = dep[fa] + 1 ; 
	Next( i, x ) {
		int v = e[i].to ; 
		dfs( v, x ), sz[x] += sz[v] ; 
		if( sz[v] > sz[son[x]] ) son[x] = v ; 
	}
}
void doit( int x, int fa ) {
	dw[dep[x]][w[x]] ^= 1 ; rev[++ tot] = (node){ dep[x], w[x] } ; 
	Next( i, x ) {
		int v = e[i].to ; 
		if( vis[v] ) continue ; 
		doit( v, x ) ; 
	}
}
void solve( int x, int fa ) {
	Next( i, x ) {
		int v = e[i].to ; if( v == son[x] ) continue ; 
		solve( v, x ) ; 
		while( tot ) dw[rev[tot].id][rev[tot].w] = 0, -- tot ;
	}
	if( son[x] ) solve( son[x], x ), vis[son[x]] = 1;
	doit( x, fa ), vis[son[x]] = 0 ; 
	int siz = Q[x].size() - 1 ; 
	rep( i, 0, siz ) {
		int u = Q[x][i].id, Dp = Q[x][i].w, ans = 0 ;
		rep( j, 1, 26 ) ans += dw[Dp][j] ;
		Ans[u] = ( ans <= 1 ) ;  
	}
}
signed main()
{
	n = read(), q = read() ; int x, y ; 
	rep( i, 2, n ) x = read(), add( x, i ) ;
	scanf("%s", sc + 1 ) ;
	rep( i, 1, n ) w[i] = sc[i] - 'a' + 1 ; 
	rep( i, 1, q ) x = read(), y = read(), Q[x].push_back((node){ i, y }) ; 
	dfs( 1, 1 ), solve( 1, 0 ) ; 
	rep( i, 1, q ) ( Ans[i] == 1 ) ? puts("Yes") : puts("No") ;
	return 0;
}