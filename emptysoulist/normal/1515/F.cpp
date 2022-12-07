#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( int i = (t); i >= (s); -- i )
#define mp make_pair
#define int long long
#define pi pair<int, int>
#define pb push_back
#define vi vector<int>
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 3e5 + 5 ; 
int n, m, X, cnt, st[N], be, ed, head[N], fa[N], a[N] ; 
struct E {
	int to, next, w ; 
} e[N << 1] ;
void add(int x, int y, int w) {
	e[++ cnt] = (E){ y, head[x], w }, head[x] = cnt,
	e[++ cnt] = (E){ x, head[y], w }, head[y] = cnt ; 
}
int fd(int x) { return (fa[x] == x) ? fa[x] : fa[x] = fd(fa[x]) ; }
void merge(int x, int y, int z) {
	int u = fd(x), v = fd(y) ; 
	if(u != v) add(x, y, z), fa[u] = v ; 
}
void dfs(int x, int ff) {
	Next( i, x ) {
		int v = e[i].to ; if(v == ff) continue ; 
		dfs(v, x) ; 
		if(a[v] >= -X && a[v] <= 0) st[-- ed] = e[i].w ; 
		else st[be] = e[i].w, ++ be, a[x] += a[v] ; 
	}
}
signed main()
{
	n = gi(), m = gi(), X = gi() ; int sum = 0 ;
	rep( i, 1, n ) fa[i] = i, a[i] = gi() - X, sum += a[i] ; 
	rep( i, 1, m ) {
		int x = gi(), y = gi() ; 
		merge(x, y, i) ; 
	}
	if(sum < -X) { puts("NO") ; exit(0) ; }
	rep( i, 1, n ) if(fd(i) != fd(1)) { puts("NO") ; exit(0) ; }
	puts("YES") ; 
	be = 1, ed = n, dfs(1, 1) ; 
	rep( i, 1, n - 1 ) printf("%lld\n", st[i]) ; 
	return 0 ;
}