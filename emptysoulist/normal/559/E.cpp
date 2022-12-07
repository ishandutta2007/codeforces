#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define pi pair<int, int>
#define fi first
#define se second
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int inf = 1e9 ; 
const int N = 300 + 5 ; 
int n, st[N], top, cnt, l[N], w[N] ;
int pre[N], a[N], dp[N][N], fr[N] ; 
pi f[N] ; 
signed main()
{
	n = gi() ; 
	rep( i, 1, n ) {
		w[i] = gi(), l[i] = gi(), f[i].fi = w[i], f[i].se = l[i] ; 
		st[++ top] = w[i] - l[i], st[++ top] = w[i], st[++ top] = w[i] + l[i] ; 
	}
	sort(st + 1, st + top + 1), a[++ cnt] = st[1] ; 
	rep( i, 2, top ) if( st[i] != st[i - 1] ) a[++ cnt] = st[i] ;
	pre[1] = st[1] ; 
	rep( i, 2, cnt ) pre[i] = a[i] ; 
	sort(f + 1, f + n + 1) ;
	rep( i, 1, n ) {
		int x = 0, p = 0, ll = f[i].fi, rr = f[i].fi + f[i].se ;
		rep( j, 1, cnt ) if( pre[j] == ll ) p = j ; 
		rep( j, 1, cnt ) if( pre[j] == rr ) x = j ; 
		fr[i] = x ; 
		rep( j, 1, cnt ) dp[i][j] = dp[i - 1][j] ; 
		rep( j, p, x ) 
			dp[i][j] = max( dp[i][j], dp[i - 1][p] + pre[j] - ll ) ;
		ll = f[i].fi - f[i].se ; 
		rep( j, 1, cnt ) if( pre[j] == ll ) x = j ; 
		int R = p ; 
		for(re int k = i - 1; k >= 0; -- k) {
			for( re int t = x; t <= R; ++ t ) 
				dp[i][t] = max( dp[i][t], dp[k][x] + max(0ll, pre[t] - ll) ) ;
			R = max( R, fr[k] ) ; 
		}
		rep( j, 1, cnt ) dp[i][j] = max( dp[i][j - 1], dp[i][j] ) ; 
	}
	printf("%lld\n", dp[n][cnt] ) ; 
	return 0 ;
}