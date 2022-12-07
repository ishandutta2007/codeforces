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
const int N = 2e5 + 5 ;  
int n, m, a[N], b[N], dp[N], d, id ; 
bool check(int x) {
	rep( j, 0, 1 ) {
		rep( i, 0, n ) dp[i] = -m ;
		int Ed = m + b[1] - j * x, fs = Ed ; //j = 0 means after
		dp[1] = b[1] + (j ^ 1) * x ;
		if(!j) fs = m + b[2] - x - 1, dp[2] = max( b[2], b[1] + x ) ; 
		rep( i, (2 + (j ^ 1)), n ) {
			if( dp[i - 2] >= b[i] - x - 1 ) dp[i] = b[i - 1] + x ;
			if( dp[i - 1] >= b[i] - x - 1 ) dp[i] = max(dp[i], b[i]) ;
			if( dp[i - 1] >= b[i] - 1 ) dp[i] = b[i] + x ;
		}
		if( dp[n] >= min( Ed - 1, fs ) ) return 1 ;
	} return 0 ; 
}
signed main()
{
	m = gi(), n = gi() ; 
	rep( i, 1, n ) a[i] = gi(), a[i + n] = a[i] + m ;
	if( n == 1 ) { printf("%d\n", m - 1 ) ; exit(0) ; }
	rep( i, 2, n + 1 ) {
		int di = a[i] - a[i - 1] ; 
		if( d < di ) d = di, id = i ; 
	}
	rep( i, 1, n ) b[i] = a[i + id - 1] ; 
	int l = 0, r = d, ans = d ; 
	while( l <= r ) {
		int mid = (l + r) >> 1 ; 
		if(check(mid)) ans = mid, r = mid - 1 ;
		else l = mid + 1 ; 
	}
	printf("%d\n", ans ) ;
	return 0 ;
}