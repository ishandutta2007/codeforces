#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
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
const int N = 5000 + 5 ; 
const int P = 998244353 ; 
int n, dp[N][N], inv[N], fac[N] ; 
int fpow(int x, int k) {
	int ans = 1, base = x ;
	while(k) {
		if(k & 1) ans = 1ll * ans * base % P ;
		base = 1ll * base * base % P, k >>= 1 ;
	} return ans ;
}
void inc(int &x, int y) {
	((x += y) >= P) && (x -= P) ; 
}
int C(int x, int y) {
	return fac[x] * inv[y] % P * inv[x - y] % P ; 
}
signed main()
{
	n = gi(), fac[0] = inv[0] = 1 ; 
	rep( i, 1, n ) fac[i] = fac[i - 1] * i % P, inv[i] = fpow( fac[i], P - 2 ) ; 
	dp[1][0] = 1 ; 
	rep( i, 1, n - 1 ) {
		for(re int j = 0; j < i; ++ j) {
			inc( dp[i + 1][j], dp[i][j] ) ;
			inc( dp[i + 1][j + 1], dp[i][j] ) ; 
			inc( dp[i + 1][j], 1ll * dp[i][j] * j % P ) ;
			inc( dp[i + 1][j + 1], 1ll * dp[i][j] * (i - 1 - j) % P ) ;
		}
	}
	rep( i, 1, n ) {
		int ans = 0 ;
		for(re int j = 1; j <= n; ++ j) 
			inc(ans, dp[j][i - 1] * C(n, j) % P * fac[n - j] % P) ; 
		printf("%lld ", ans ) ; 
	}
	return 0 ;
}