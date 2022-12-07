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
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 100 + 5 ; 
int n, A[N], B[N], dp[N * N][N] ; 
signed main()
{
	n = gi() ; int sum = 0 ; 
	rep( i, 1, n ) 
		A[i] = gi(), B[i] = gi(), A[i] -= B[i], sum += B[i] ; 
	memset(dp, -63, sizeof(dp)) ; 
	dp[0][0] = 0 ; 
	rep( i, 1, n ) {
		drep( k, 1, i ) drep( j, B[i], sum ) 
		dp[j][k] = max( dp[j][k], dp[j - B[i]][k - 1] + A[i] ) ; 
	} 
	rep( k, 1, n ) {
		double ans = 0 ; 
		rep( j, 0, sum ) 
			ans = max(ans, 0.5 * min(sum - j, dp[j][k] * 2) + j ) ; 
		printf("%.7lf ", ans ) ; 
	}
	return 0 ;
}