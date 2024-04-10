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
const int N = 7 ; 
const int M = 2e4 + 5 ; 
const int inf = 4e8 ; 
vector<int> f[M] ; 
int n, m, fac[N], a[N], b[N], w[N][N], d[N], dp[N][M] ; 
void dfs(int x, int y, int c, int C) {
	if(x == m) {
		if(c > d[m]) return ; 
		int s = 0 ; d[m] -= c ; 
		rep( i, 1, m ) s += d[i] * fac[i] ; 
		dp[y][s] = min(dp[y][s], C + (c > 0) * w[y][m]) ; 
		d[m] += c ; 
		return ; 
	}
	rep( i, 0, min(d[x], c) ) {
		d[x] -= i ; 
		if(!i) dfs(x + 1, y, c, C) ;
		else dfs(x + 1, y, c - i, C + w[y][x]) ;
		d[x] += i ; 
	}
}
signed main()
{
	n = gi(), m = gi() ; 
	rep( i, 1, n ) a[i] = gi() ; 
	rep( i, 1, m ) b[i] = gi() ; 
	rep( i, 1, n ) rep( j, 1, m ) w[i][j] = gi() ; 
	fac[1] = 1 ; int S = 0 ; 
	rep( i, 2, m ) fac[i] = fac[i - 1] * (1 + b[i - 1]) ; 
	rep( i, 1, m ) S += fac[i] * b[i] ; 
	memset(dp, 63, sizeof(dp)), dp[0][S] = 0 ; 
	for(int x = 1; x <= n; ++ x) {
		rep( t, 0, S ) {
			int u = t ; 
			drep( i, 1, m ) d[i] = (u / fac[i]), u %= fac[i] ; 
			dfs(1, x, a[x], dp[x - 1][t]) ; 
		}
	}
	int ans = inf ; 
	rep( x, 0, S ) ans = min(ans, dp[n][x]) ;
	if(ans < inf) cout << ans << endl ; 
	else puts("-1") ; 
	return 0 ; 
}