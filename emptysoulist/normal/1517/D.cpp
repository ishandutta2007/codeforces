#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( int i = (t); i >= (s); -- i )
#define mp make_pair
#define pi pair<int, int>
#define pb push_back
#define vi vector<int>
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int inf = 1e16 ; 
const int N = 505 ; 
int n, m, K, f[15][N][N] ; 
int c[N][N], b[N][N] ; 
signed main()
{
	n = gi(), m = gi(), K = gi() ; 
	rep( i, 1, n ) {
		for(int j = 1; j < m; ++ j)
		c[i][j] = gi() ; 
	}
	for(int i = 1; i < n; ++ i)
	rep( j, 1, m ) b[i][j] = gi() ; 
	rep( j, 1, m ) b[n][j] = inf ; 
	rep( i, 1, n ) c[i][m] = inf ; 
	if(K & 1) {
		rep( i, 1, n ) {
			rep( j, 1, m ) {
				printf("-1 ") ;  
			}
			puts("") ; 
		}
	}
	else {
		K /= 2 ; 
		rep( k, 1, K ) rep( i, 1, n ) rep( j, 1, m ) {
			f[k][i][j] = min(f[k - 1][i + 1][j] + b[i][j], f[k - 1][i][j + 1] + c[i][j]) ;
			if(i != 1) f[k][i][j] = min(f[k][i][j], f[k - 1][i - 1][j] + b[i - 1][j]) ; 
			if(j != 1) f[k][i][j] = min(f[k][i][j], f[k - 1][i][j - 1] + c[i][j - 1]) ; 
		}
		rep( i, 1, n ) {
			rep( j, 1, m ) {
				printf("%lld ", f[K][i][j] * 2) ; 
			} puts("") ; 
		}
	}
	return 0 ;
}