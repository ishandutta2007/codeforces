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
const int N = 500 + 5 ; 
int n, k, a[N], b[N], L[N], R[N], sA[N], Sum[N], ans = 0, sum ;
int dp[N][N << 1] ;  
void solve() {
	rep( i, 1, n ) {
		rep( t, 0, k ) L[t] = t - 1, R[t - 1] = t ; 
		sum += a[i] + b[i] ; 
		
		for( re int j = 0; j < k; ++ j ) 
		if( dp[i - 1][j] ) {
			for( re int t = R[-1]; t < k; t = R[t] ) 
			if(( t + k - j ) % k <= a[i] ) 
				if( ( ( sum - t ) % k + k - ( sum - a[i] - b[i] - j ) % k ) % k <= b[i] ) 
					dp[i][t] = 1, L[R[t]] = L[t], R[L[t]] = R[t] ;
		}
	}
}
signed main()
{
	n = gi(), k = gi() ;
	rep( i, 1, n ) a[i] = gi(), b[i] = gi(), Sum[i] = a[i] + b[i] ;
	memset( dp, 0, sizeof(dp) ) ;
	dp[0][0] = 1, 
	solve() ; 
	for( re int t = 0; t < k; ++ t ) if( dp[n][t] ) ans = max( ans, ( sum - t ) / k ) ;
	cout << ans << endl ;
	return 0;
}