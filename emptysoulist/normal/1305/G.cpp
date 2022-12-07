#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = (1 << 18) + 5 ; 
int n, a[N], f[N], fa[N] ; 
long long ans ; 
int fd(int x) {
	return (x == fa[x]) ? x : fa[x] = fd(fa[x]) ; 
}
void merge(int x, int y) {
	int u = fd(x), v = fd(y) ;
	if( u == v ) return ; 
	fa[u] = v, ans += 1ll * (f[x] + f[y] - 1) * (x + y) ; 
}
signed main()
{
	n = gi() ; int x ; 
	rep( i, 1, n ) x = gi(), ans -= x, f[x] ++ ; 
	n = (1 << 18) - 1 ; 
	rep( i, 1, n ) fa[i] = i ; ++ f[0] ;
	for(re int i = n; i >= 0; -- i) {
		for(re int j = i; j; j = (j - 1) & i ) {
			int u = j, v = j ^ i ;
			if( !f[u] || !f[v] ) continue ; 
			merge(u, v), f[u] = 1, f[v] = 1 ; 
		}
	}
	cout << ans << endl ; 
	return 0 ;
}