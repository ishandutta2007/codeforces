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
const int N = 1e4 + 5 ; 
int n, a[N], b[N], c, f[2][N] ; 
signed main()
{
	n = gi(), c = gi() ; 
	rep( i, 1, n ) a[i] = gi() ; 
	rep( i, 1, n ) b[i] = gi() ; 
	memset(f, 63, sizeof(f)) ;
	f[0][0] = 0 ; 
	rep( i, 1, n ) {
		int u = (i & 1), d = (u ^ 1) ; 
		rep( j, 0, n ) {
			if(!j) f[u][j] = f[d][j] + a[i] ; 
			else f[u][j] = min(f[d][j - 1] + b[i], f[d][j] + a[i] + j * c) ; 
		}
	}
	int ans = inf ; 
	rep( j, 0, n ) ans = min(ans, f[n & 1][j]) ;
	cout << ans << endl ; 
	return 0 ;
}