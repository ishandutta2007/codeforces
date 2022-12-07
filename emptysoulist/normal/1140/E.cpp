// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define int long long
int read() {
	char cc = getchar(); int cn = 0, flus = 1;
	while(cc < '0' || cc > '9') {  if( cc == '-' ) flus = -flus;  cc = getchar();  }
	while(cc >= '0' && cc <= '9')  cn = cn * 10 + cc - '0', cc = getchar();
	return cn * flus;
}
const int N = 2e5 + 5 ; 
const int mod = 998244353 ; 
int n, k, a[N], num, b[N], dp[N][2], Ans ;
int solve() {
	int w = 1, len = 0, pre = 0 ; 
	rep( i, 1, num ) {
		if( b[i] == -1 ) ++ len ;
		else {
			if( len ) {
				if( !pre ) w = w * ( ( k - 1ll ) * dp[len - 1][1] % mod + dp[len - 1][0] ) % mod ;
				else if( pre == b[i] ) w = w * dp[len][0] % mod ; 
				else w = w * dp[len][1] % mod ;  
			} 
			pre = b[i], len = 0 ;
		}
	}
	if( len == num ) {
		w = k ;
		rep( i, 2, num ) w = ( w * ( k - 1ll ) ) % mod ; 
		return w % mod ; 
	} 
	if( len ) w = ( w * ( ( dp[len - 1][0] + ( k - 1ll ) * dp[len - 1][1] % mod ) % mod ) ) % mod  ;
	return w % mod ; 
}
signed main()
{
	n = read(), k = read() ;  
	rep( i, 1, n ) {
		a[i] = read() ; 
		if( i > 3 && a[i] == a[i - 2] && a[i] != -1 )
			puts("0"), exit(0) ; 
	}
	dp[0][0] = 0, dp[0][1] = 1 ; //01 
	for( int i = 1; i <= n / 2 + 1; ++ i ) {
		dp[i][0] = ( dp[i - 1][1] * ( k - 1 ) ) % mod ;
		dp[i][1] = ( dp[i - 1][0] + ( ( k - 2 ) * dp[i - 1][1] % mod ) ) % mod ;
	}
	rep( i, 1, n ) if( i % 2 ) b[++ num] = a[i] ; 
	Ans = solve(), num = 0 ; 
	rep( i, 1, n ) if( i % 2 == 0 ) b[++ num] = a[i] ; 
	Ans *= solve(), Ans %= mod ; 
	printf("%d\n", Ans ) ;
	return 0;
}