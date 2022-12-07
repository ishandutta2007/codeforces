#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define mp make_pair
#define pi pair<int, int>
#define pb push_back
#define int long long
#define vi vector<int>
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 4e5 + 5 ; 
int n, cnt, head[N], f[50], vis[N], Go[N], sz[N] ; 
struct E {
	int to, next ; 
} e[N << 1] ; 
void add(int x, int y) {
	e[++ cnt] = (E){y, head[x]}, head[x] = cnt,
	e[++ cnt] = (E){x, head[y]}, head[y] = cnt ; 
}
int root1, root2 ; 
void dfs(int x, int fa, int k) {
	sz[x] = 1 ; 
	Next(i, x) {
		int v = e[i].to ; if(v == fa || Go[i]) continue ; 
		dfs(v, x, k), sz[x] += sz[v] ; 
	}
	if(x != fa && ((vis[sz[x]] == k) || (vis[sz[x]] == k - 1))) root1 = x, root2 = fa ; 
}
int solve(int x, int k) {
	root1 = 0, dfs(x, x, k - 1) ; 
	if(sz[x] == 1) return 1 ;  
	if(!root1) return 0 ; 
	Next(i, root2) {
		int v = e[i].to ; 
		if(v == root1) Go[i] = Go[i ^ 1] = 1 ; 
	} int u = root1, v = root2 ; 
	int k1 = vis[sz[u]] ; 
	int k2 = k * 2 - 3 - k1 ; 
	return (solve(u, k1) & solve(v, k2)) ; 
}
signed main()
{
	f[0] = f[1] = 1 ; cnt = 1 ; 
	rep( i, 2, 26 ) f[i] = f[i - 1] + f[i - 2] ; 
	rep( i, 1, 26 ) vis[f[i]] = i ; 
	n = gi() ; int x, y ; 
	rep( i, 2, n ) x = gi(), y = gi(), add(x, y) ; 
	if(!vis[n]) { puts("NO") ; exit(0) ; }
	if(solve(1, vis[n])) puts("YES") ; 
	else puts("NO") ; 
	return 0 ;
}