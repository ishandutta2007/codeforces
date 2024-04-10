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
const double inf = 1e9 ; 
const int N = 1005 ; 
int n, vis[N] ; 
double p[N][N], f[N], g[N] ; 
signed main() {
	n = gi() ; 
	rep( i, 1, n ) f[i] = 0 ; 
	rep( i, 1, n ) rep( j, 1, n ) 
	p[i][j] = gi(), p[i][j] /= 100.0 ; 
	rep( k, 1, n ) g[k] = 1 ; 
	f[n] = 0, g[n] = 0 ; 
	rep( k, 1, n ) {
		int u = 0 ; double F = inf ; 
		rep( i, 1, n ) {
			if(g[i] == 1 || vis[i]) continue ; 
			if(F > (f[i] + g[i]) / (1 - g[i]))
			F = (f[i] + g[i]) / (1 - g[i]), u = i ; 
		}
		vis[u] = 1 ; 
		rep( i, 1, n ) {
			if(vis[i]) continue ; 
			f[i] = f[i] + g[i] * p[i][u] * (F + 1) ;
			g[i] = g[i] * (1 - p[i][u]) ; 
		} 
		if(u == 1) break ; 
	} 
	printf("%.10lf\n", (f[1] + g[1]) / (1 - g[1])) ; 
	//awa
	return 0 ;
}