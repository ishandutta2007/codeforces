#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 50 + 5 ; 
const int P = 998244353 ; 
int n, cnt, num, idx, L[N], R[N], Dp[N][N * 2], dp[N][N * 2], w[N * 2] ; 
int fpow( int x, int k ) {
	int ans = 1, base = x ; 
	while(k) {
		if(k & 1) ans = ans * base % P ;
		base = base * base % P, k >>= 1 ; 
	} return ans ; 
}
int Lag( int u, int x ) {
	if( x <= idx ) return dp[u][x] ; int ans = 0 ; 
	rep( i, 1, idx ) {
		int fm = 1, fz = dp[u][i] ;  
		rep( j, 1, idx ) if( i != j ) fm = fm * (i - j + P) % P, fz = fz * (x - j + P) % P ; 
		ans = ( ans + fpow(fm, P - 2) * fz % P ) % P ;  
	} return ans ; 
}
void solve(int l, int r) {
	rep( i, 0, n ) rep( j, 0, idx ) dp[i][j] = 0 ;
	rep( j, 0, idx ) dp[0][j] = 1 ; 
	for( re int i = 1; i <= n; ++ i ) {
		dp[i][0] = Dp[i][num - 1] ; 
		if( L[i] <= l && r <= R[i] ) {
			rep( j, 1, idx ) dp[i][j] = dp[i - 1][j] ; 
		}
		rep( j, 1, idx ) dp[i][j] = ( dp[i][j] + dp[i][j - 1] ) % P ; 
		Dp[i][num] = Lag(i, r - l + 1) ; 
	}
} 
signed main()
{
	n = gi(), idx = n * 2 + 1 ; 
	rep( i, 1, n ) 
		L[i] = gi(), R[i] = gi(), w[++ cnt] = L[i], w[++ cnt] = R[i] + 1 ; 
	sort( w + 1, w + cnt + 1 ) ; 
	for(re int i = cnt - 1; i >= 1; -- i ) {
		if( w[i] != w[i + 1] ) ++ num, solve(w[i], w[i + 1] - 1) ; 
	}
	int Ans = Dp[n][num] ; 
	rep( i, 1, n ) Ans = Ans * fpow( R[i] - L[i] + 1, P - 2 ) % P ; 
	cout << Ans << endl ; 
	return 0 ;
}