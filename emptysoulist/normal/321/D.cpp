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
const int N = 40 + 5 ; 
int n, m, Ans, S, a[N][N], w[N] ; 
int Get( int x, int y, int fy ) {
	int f1 = 1, f2 = w[x], f3 = fy, f4 = fy * w[m] * w[x] ; 
	int ans1 = a[x][y] * f1 + a[x][y + m] * f2 + a[x + m][y] * f3 + a[x + m][y + m] * f4 ; 
	return max( ans1, -ans1 ) ; 
}
int F( int y, int fy ) {
	int ans = fy * a[m][y] + fy * w[m] * a[m][y + m] ;  
	for(int j = 1; j < m; ++ j) 
	ans = ( ans + Get(j, y, fy) ) ;
	return ans ; 
}
signed main()
{
	n = gi() ; 
	rep(i, 1, n) rep(j, 1, n) a[i][j] = gi() ; 
	m = (n + 1) / 2 ; 
	int maxn = ( 1 << m ) - 1 ; 
	rep( i, 0, maxn ) {
		int ans = 0 ; S = i ; 
		rep( j, 1, m ) w[j] = ( ( S >> (j - 1) ) & 1 ) ; 
		if( w[m] ) {
			ans = a[m][m] ;
			for(int j = 1; j < m; ++ j) 
				( w[j] ) ? ans = ans + a[j][m] + a[j + m][m] : ans = ans - a[j][m] - a[j + m][m] ; 
			rep(j, 1, m) w[j] = w[j] ? 1 : -1 ; 
		}
		else {
			ans = -a[m][m] ;
			for(int j = 1; j < m; ++ j) 
				( w[j] ) ? ans = ans + a[j][m] - a[j + m][m] : ans = ans - a[j][m] + a[j + m][m] ; 
			rep(j, 1, m) w[j] = w[j] ? 1 : -1 ; 
		}
		for(int j = 1; j < m; ++ j) 
			ans += max( F(j, -1), F(j, 1) ) ;
		Ans = max( Ans, ans ) ; 
	} 
	cout << Ans << endl ; 
	return 0 ;
}