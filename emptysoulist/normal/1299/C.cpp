#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 2e6 + 5 ; 
int n, a[N], fa[N], sz[N], w[N] ;
long double ans[N] ; 
int fd( int x ) {
	return ( x == fa[x] ) ? x : fa[x] = fd(fa[x]) ;
}
void merge( int u, int v ) {
	int x = fd(u), y = fd(v) ;
	fa[y] = x, w[x] += w[y], sz[x] += sz[y] ;
	ans[x] = 1.0 * w[x] / sz[x] ;
}
signed main()
{
	n = gi() ; 
	rep( i, 1, n ) a[i] = gi(), fa[i] = i ; 
	for( re int i = 1; i <= n; ++ i ) {
		sz[i] = 1, ans[i] = 1.0 * a[i], w[i] = a[i] ;
		if( i == 1 ) continue ; 
		int u = i - 1 ;
		while(1) {
			int x = fd(u) ;
			if( ans[x] > ans[fd(i)] ) merge( x, i ) ;
			else break ;
			if( x <= 1 ) break ;
			u = x - 1 ; 
		}
	}
	rep( i, 1, n ) {
		double Ans = ans[fd(i)] ;
		printf("%.9lf\n", Ans ) ;
	}
	return 0 ;
}