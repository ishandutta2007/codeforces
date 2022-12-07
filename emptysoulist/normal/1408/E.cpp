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
const int N = 1e6 + 5 ;  
int n, m, cnt, Ans, a[N], b[N], fa[N] ; 
struct E {
	int fr, to, w ; 
} e[N] ;
int fd(int x) {
	return (x == fa[x]) ? x : fa[x] = fd(fa[x]) ; 
}
bool cmp( E x, E y ) {
	return x.w > y.w ; 
} 
signed main()
{
	n = gi(), m = gi() ; 
	rep( i, 1, n ) a[i] = gi() ; 
	rep( i, 1, m ) b[i] = gi() ; 
	rep( i, 1, n ) {
		int z = gi(), x ; 
		rep( j, 1, z ) {
			x = gi() ; 
			e[++ cnt] = (E){ i, x + n, a[i] + b[x] } ;
			Ans += (a[i] + b[x]) ; 
		}
	}
	for(int i = 1; i <= n + m; ++ i) fa[i] = i ; 
	sort(e + 1, e + cnt + 1, cmp ) ;
	rep( i, 1, cnt ) {
		int x = e[i].fr, y = e[i].to ; 
		int u = fd(x), v = fd(y) ;
		if( u == v ) continue ; 
		fa[u] = v, Ans -= (e[i].w) ;
	}
	cout << Ans << endl ; 
	return 0 ;
}
// 
// 
// 
// 
//