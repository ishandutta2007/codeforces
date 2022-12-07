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
const int P = 1e4 + 7 ; 
const int N = 200 + 5 ;
const int M = 300 + 5 ;  
int n, m, lim, fl, Id[N][N], dp[N][N][N] ; 
char s[N] ; 
struct Mat {
	int a[M][M] ; 
	void init() { rep( i, 1, lim ) rep( j, 1, lim ) a[i][j] = 0 ; }
	void init2() { init() ; rep( i, 1, lim ) a[i][i] = 1 ; }
} A, f ; 
Mat operator * (Mat x, Mat y) {
	Mat ans ; ans.init() ;
	rep( k, 1, lim ) rep( i, 1, lim ) rep( j, 1, lim ) 
		ans.a[i][j] = (ans.a[i][j] + x.a[i][k] * y.a[k][j]) % P ; 
	return ans ; 
}
Mat fpow(Mat x, int k) {
	Mat ans, base = x ; ans.init2() ; 
	while(k) {
		if(k & 1) ans = ans * base ;
		base = base * base, k >>= 1 ; 
	} return ans ; 
}
void Dfs(int l, int r) {
	if( l > r ) return dp[l][r][0] = 1, void() ; 
	if( Id[l][r] ) return ; Id[l][r] = 1 ; 
	if(s[l] == s[r]) {
		Dfs(l + 1, r - 1) ; 
		rep(i, 0, m) dp[l][r][i] = dp[l + 1][r - 1][i] ; 
	}
	else {
		Dfs(l + 1, r), Dfs(l, r - 1) ; 
		rep(i, 1, m) dp[l][r][i] = (dp[l + 1][r][i - 1] + dp[l][r - 1][i - 1]) % P ; 
	}
}
void Dfs2(int l, int r) {
	if( Id[l][r] > 1 ) return ; Id[l][r] = 2 ; 
	rep( i, 0, m ) dp[l][r][i] = 0 ; 
	if( l > r ) return dp[l][r][0] = 1, void() ; 
	if(s[l] == s[r]) {
		if( r == l ) return ; 
		Dfs2(l + 1, r - 1) ; 
		rep(i, 0, m) dp[l][r][i] = dp[l + 1][r - 1][i] ; 
	} else {
		Dfs2(l + 1, r), Dfs2(l, r - 1) ; 
		rep(i, 1, m) dp[l][r][i] = (dp[l + 1][r][i - 1] + dp[l][r - 1][i - 1]) % P ; 
	}
}
signed main()
{
	scanf("%s", s + 1 ), m = strlen(s + 1) ;
	n = gi(), n += m ; if(n & 1) ++ n, fl = 1 ;
	Dfs(1, m) ; lim = m + ((m + 1) / 2) ; 
	rep( i, 1, m - 1 ) {
		f.a[i][i] = 24, f.a[i][i + 1] = (i != (m - 1)),
		f.a[i][lim - (m - i + 1) / 2] = dp[1][m][i] ; 
	} 
	for(re int i = m; i < lim; ++ i) 
		f.a[i][i + 1] = 1, f.a[i][i] = 25 ; 
	f.a[lim][lim] = 26, A = fpow(f, n / 2) ;
	int ans = 0 ; 
	if( m != 1 ) ans = A.a[1][lim] ;
	ans = (ans + A.a[m][lim] * dp[1][m][0] % P) % P ; 
	if( fl ) {
		memset( f.a, 0, sizeof(f.a) ), Dfs2(1, m) ; 
		
		rep( i, 1, m - 1 ) {
			f.a[i][i] = 24, f.a[i][i + 1] = (i != (m - 1)), 
			f.a[i][lim - (m - i + 1) / 2] = dp[1][m][i] ; 
		} 
		for(re int i = m; i < lim; ++ i) 
			f.a[i][i + 1] = 1, f.a[i][i] = 25 ; 
		A = fpow(f, n / 2) ;
		if(m != 1) ans = (ans - A.a[1][lim] + P) % P ;
		ans = (ans - A.a[m][lim] * dp[1][m][0] % P + P) % P ; 
	}
	cout << ans << endl ; 
	return 0 ; 
}