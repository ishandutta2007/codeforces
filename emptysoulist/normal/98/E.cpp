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
const int N = 1005 ; 
long double f[N][N] ; 
int vis[N][N] ; 
long double DFS(int n, int m) {
	if(!n) return 1.0 / (m + 1) ; 
	if(!m) return 1.0 ; 
	if(vis[n][m]) return f[n][m] ; 
	long double po = (1.0 / (m + 1)) ; 
	long double A = po * m * (1.0 - DFS(m - 1, n)),
		B = po * (1 + m * (1.0 - DFS(m - 1, n))), C = (1.0 - DFS(m, n - 1)) ; 
	long double p = (1 - C) / (B - A - C + 1.0) ; 
	vis[n][m] = 1 ; 
	return f[n][m] = (1 - p) + p * A ;  
}
signed main()
{
	int n = gi(), m = gi() ; 
	printf("%.10Lf %.10Lf\n", DFS(n, m), 1 - DFS(n, m)) ; 
	return 0 ;
}