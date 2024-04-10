#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define int long long
const int P = 998244353 ; 
const int qwq = 2333 ; 
const int N = 20 ; 
const int M = 1 << 18 ; 
int n, limit, top, ft[M], st[N], a[N][N], bit[M], g[M], dp[M][N], f[N][M], tx[N][M] ; 
map<int, int> ff ;
void FWT( int *a ) {
	for( re int k = 1; k < limit; k <<= 1 ) rep(i, 0, limit - 1) if(i & k) a[i] += a[i ^ k] ; 
}
void mul( int u, int *a ) { for( re int i = 0; i < limit; ++ i ) tx[u][i] = tx[u - 1][i] * a[i] ; }
void init(int x) { for( re int i = 0; i < limit; ++ i ) ff[x] = ff[x] + tx[top][i] * ft[i] ; }
void dfs( int S, int l, int hash ) {
	if(!S) return init(hash) ; 
	for( re int i = 1; i <= min( S, l ); ++ i ) 
		++ top, mul( top, f[i] ), st[top] = i, dfs( S - i, i, ( hash * qwq + i ) % P ), st[-- top] = i ;
}
signed main()
{
	cin >> n ; getchar() ; 
	rep( i, 1, n ) {
		rep( j, 1, n ) a[i][j] = getchar() - '0' ; 
		getchar() ; 
	}
	rep( i, 1, n ) dp[1 << (i - 1)][i] = 1 ; 
	limit = ( 1 << n ) ; int m = limit - 1 ; 
	rep( i, 1, m ) {
		bit[i] = bit[i ^ (i & (-i))] + 1 ; int ans = 0 ; 
		for( re int j = 1; j <= n; ++ j ) {
			if( (i & (1 << (j - 1))) ) 
				for( re int k = 1; k <= n; ++ k ) 
				if( (!(i & (1 << (k - 1)))) && a[j][k] ) dp[i | (1 << (k - 1))][k] += dp[i][j] ;
			ans += dp[i][j] ; 
		} f[bit[i]][i] = ans ; 
	} 
	for( re int j = 0; j < limit; ++ j ) 
		tx[0][j] = 1, ft[j] = ((bit[m ^ j]) & 1) ? -1 : 1 ; 
	rep( i, 1, n ) FWT( f[i] ) ; dfs( n, n, 0 ) ; 
	int maxn = ( 1 << (n - 1) ) - 1 ; 
	for( re int i = 0; i <= maxn; ++ i ) {
		top = 0 ; int fl = 1, hash = 0 ; 
		for( re int j = n - 2; j >= 0; -- j ) 
			if( i & ( 1 << j ) ) ++ fl ;
			else st[++ top] = fl, fl = 1 ; 
		st[++ top] = fl, sort( st + 1, st + top + 1 ) ; 
		drep( j, 1, top ) hash = ( hash * qwq + st[j] ) % P ; g[i] = ff[hash] ;
	}
	for( re int k = 1; k <= maxn; k <<= 1 ) rep(i, 0, maxn) if(!(i & k)) g[i] = g[i] - g[i ^ k] ;
	for( re int i = 0; i <= maxn; ++ i ) printf("%lld ", g[i] ) ; 
	return 0 ;
}