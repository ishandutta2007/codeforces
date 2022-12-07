#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( int i = (t); i >= (s); -- i )
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
const int inf = 1e9 + 7 ; 
const int N = 105 ; 
int n, m, b[N][N], c[N][N], vis[N][N] ;  
signed main()
{
	int T = gi() ; 
	while( T-- ) {
		n = gi(), m = gi() ; 
		rep( i, 1, n ) rep( j, 1, m ) b[i][j] = gi() ; 
		rep( i, 1, n ) sort(b[i] + 1, b[i] + m + 1) ; 
		rep( t, 1, m ) {
			int idx = 0, idy = 0, mi = inf ; 
			rep( i, 1, n ) rep( j, 1, m ) {
				if(vis[i][j]) continue ; 
				if(b[i][j] <= mi)
				idx = i, idy = j, mi = b[i][j] ; 
			}
			vis[idx][idy] = 1 ; 
			c[idx][t] = mi ; 
			rep( i, 1, n ) {
				if(idx == i) continue ; 
				for(int j = m; j >= 1; -- j) {
					if(!vis[i][j]) {
						vis[i][j] = 1, c[i][t] = b[i][j] ; break ; 
					}
				}
			}
		}
		rep( i, 1, n ) {
			rep( j, 1, m ) printf("%lld ", c[i][j]) ; puts("") ; 
		}
		rep( i, 1, n ) rep( j, 1, m )
		vis[i][j] = 0, c[i][j] = b[i][j] = 0 ; 
	}
	return 0 ;
}