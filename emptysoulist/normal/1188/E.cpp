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
const int P = 998244353 ; 
const int M = 1e6 + 5 ; 
const int N = 1e5 + 5 ; 
int n, Ans, maxn, a[N], vis[N], cnt, fac[N + M], inv[M + N], w[M], o[M] ; 
int fpow( int x, int k ) {
	int ans = 1, base = x ; 
	while( k ) {
		if( k & 1 ) ans = ans * base % P ; 
		base = base * base % P, k >>= 1 ; 
	} return ans ; 
} 
int C( int x, int y ) {
	if( x < 0 || y < 0 || x < y ) return 0 ; 
	return 1ll * fac[x] * inv[y] % P * inv[x - y] % P ;  
}
signed main()
{
	maxn = n = gi(), Ans = inv[0] = fac[0] = 1 ; 
	rep( i, 1, n ) a[i] = gi(), ++ w[a[i]], maxn = max( a[i], maxn ) ;
	int rm = n + maxn ; 
	rep( i, 1, rm ) fac[i] = fac[i - 1] * i % P ; 
	inv[rm] = fpow( fac[rm], P - 2 ) ;
	drep( i, 1, rm ) inv[i - 1] = inv[i] * i % P ; 
	sort( a + 1, a + n + 1 ) ;
	rep( i, 0, maxn ) {
		if( !w[i] ) continue ; 
		for( re int j = i + 1; j <= maxn; j += n ) o[j] += w[i] ;
	}
	rep( j, 1, maxn ) o[j] += o[j - 1] ; 
	int l = 0, flag = 1 ; 
	rep( i, 1, n ) vis[i] = ( a[i] >= ( i - 1 ) ) ;
	rep( k, 1, maxn ) {
		while( l < n && ( a[l + 1] < k ) ) ++ l, ( flag &= vis[l] ) ;
		if( !flag ) break ; 
		Ans = ( Ans + C( k - o[k] + n - 1, n - 1 ) - C( k - o[k] + n - 1 - ( n - l ), n - 1 ) ) % P, Ans = ( Ans + P ) % P ; 
	}
	printf("%lld\n", Ans ) ;
	return 0 ;
}
//