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
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 1e6 + 5 ; 
int n, cnt, head[N], dep[N], son[N] ; 
struct E {
	int to, next ; 
} e[N << 1] ; 
int *f[N], buc[N], ans[N], *now = buc ; 
void add(int x, int y) {
	e[++ cnt] = (E){ y, head[x] }, head[x] = cnt,
	e[++ cnt] = (E){ x, head[y] }, head[y] = cnt ; 
}
void dfs(int x, int fa) {
	Next(i, x) { 
		int v = e[i].to ; if(v == fa) continue ; 
		dfs(v, x) ; if(dep[v] > dep[son[x]]) son[x] = v ; 
	} dep[x] = dep[son[x]] + 1 ; 
}
void DFS(int x, int fa) {
	f[x][0] = 1 ; 
	if(son[x]) f[son[x]] = f[x] + 1, DFS(son[x], x), ans[x] = ans[son[x]] + 1 ; 
	Next(i, x) {
		int v = e[i].to ; if(v == fa || v == son[x]) continue ; 
		f[v] = now, now += dep[v], DFS(v, x) ; 
		rep( j, 1, dep[v] ) {
			f[x][j] += f[v][j - 1] ; 
			if(f[x][j] > f[x][ans[x]]) ans[x] = j ;
			else if(f[x][j] == f[x][ans[x]] && j < ans[x]) ans[x] = j ; 
		}
	}
	if(f[x][ans[x]] == 1) ans[x] = 0 ; 
}
signed main()
{
	n = gi() ; int x, y ; 
	rep( i, 2, n ) x = gi(), y = gi(), add(x, y) ; 
	dfs(1, 1), f[1] = now, now += dep[1], DFS(1, 1) ; 
	rep( i, 1, n ) printf("%d\n", ans[i] ) ; 
	return 0 ; 
}