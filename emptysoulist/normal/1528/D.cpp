#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( int i = (s); i < (t); ++ i )
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 605 ; 
const int inf = 1e9 + 700 ; 
int n, m, vis[N], dis[N], go[N * 2], ans[N][N], w[N][N] ; 
signed main()
{
	n = gi(), m = gi() ; int a, b, c ; 
	rep( i, 0, n ) rep( j, 0, n ) w[i][j] = inf ; 
	rep( i, 0, m ) a = gi(), b = gi(), c = gi(), w[a][b] = c ; 
	rep( t, 0, n ) {
		rep( j, 0, n ) dis[j] = inf, vis[j] = 0 ; 
		dis[t] = 0 ; 
		rep( i, 0, n ) {
			int id = 0, d = inf ; 
			rep( j, 0, n ) 
			if((!vis[j]) && (d > dis[j])) d = dis[j], id = j ; 
			rep( j, 0, 2 * n ) go[j] = inf ; 
			rep( j, 0, n ) go[(j + d) % n] = w[id][j] ; 
			rep( j, 1, 2 * n ) go[j] = min(go[j], go[j - 1] + 1) ; 
			rep( j, 0, n ) go[j] = min(go[j], go[j + n]) ; 
			rep( j, 0, n ) dis[j] = min(dis[j], dis[id] + go[j]) ; 
			vis[id] = 1 ; 
		}
		rep( i, 0, n ) ans[t][i] = dis[i] ; 
	}
	rep( i, 0, n ) {
		rep( j, 0, n ) printf("%d ", ans[i][j]) ; puts("") ; 
	}
	return 0 ; 
}