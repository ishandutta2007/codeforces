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
const int N = 1e6 + 5 ; 
const int P = 1e9 + 7 ; 
int n, m, pre[N], w[N], dp[N], sum[N], a[N] ; 
char s[N] ; 
signed main()
{
	cin >> (s + 1), n = strlen(s + 1) ; 
	rep( i, 1, n ) a[i] = s[i] - '0' ; 
	int ff = 0 ; 
	rep( i, 1, n ) 
		( a[i] == 1 ) ? pre[++ m] = ff, ff = 0 : ++ ff ; 
	pre[++ m] = ff ;
	if( m == 1 ) { cout << n << endl ; exit(0) ; }
	int ans = (pre[1] + 1) * (pre[m] + 1) % P ; 
	rep( i, 0, n ) w[i] = 1 ; 
	sum[1] = dp[1] = 1 ; 
	for(re int i = 2; i < m; ++ i) {
		int L = w[0] ; 
		for(re int j = 0; j <= pre[i]; ++ j) 
			L = w[j], dp[i] = (dp[i] + sum[i - 1] - sum[L - 1] + P) % P ; 
		for(re int j = 0; j <= pre[i]; ++ j) w[j] = i ; 
		sum[i] = (sum[i - 1] + dp[i]) % P ; 
	}
	ans = ans * sum[m - 1] % P ; 
	cout << ans << endl ; 
	return 0 ;
}