#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int M = 5000 + 5 ;
const int N = 1000 + 5 ;
int n, m, a[M], k[M][N], R[M], use[M], p[N], sum[M], Ans, top, isp[M] ; 
void init( int x ) {
	rep( i, 2, x )
		if( !isp[i] ) { p[++ top] = i ;
			for( re int j = 2 * i; j <= x; j += i ) isp[j] = 1 ;
		}
	rep( i, 1, top ) {
		int u = p[i] ; for( re int j = u; j <= x; j += u ) k[j][i] = k[j / u][i] + 1 ;
	} sum[0] = sum[1] = 0 ;
	rep( i, 2, x ) {
		sum[i] = sum[i - 1] ;
		rep( j, 1, top ) sum[i] += k[i][j] ;
		rep( j, 1, top ) k[i][j] += k[i - 1][j] ;
		for( re int j = top; j >= 1; -- j )
		if( k[i][j] ) { R[i] = j ; break ; }
		Ans = Ans + sum[i] * a[i] ;
	}
}
signed main()
{
	n = gi() ; int x, cnt = 0, sz ;
	rep( i, 1, n ) x = gi(), ++ a[x], m = max( m, x ) ;
	init( m ) ; int flag = 1 ;
	for( re int i = top; i >= 1; -- i ) {
		flag = 1 ; while( flag ) {
			sz = 0 ; 
			rep( j, 2, m ) if( R[j] == i && ( use[j] == cnt ) ) sz += a[j] ; 
			if( 2 * sz > n ) {
				Ans = Ans + n - 2 * sz ; 
				rep( j, 2, m ) if( R[j] == i && ( use[j] == cnt ) ) { 
					-- k[j][R[j]], ++ use[j] ; if( !k[j][R[j]] )
					while( ( !k[j][R[j]] ) && ( R[j] != 0 ) ) -- R[j] ;
				} ++ cnt, flag = 1 ;
			} else flag = 0 ;
		} 
	} printf("%lld\n", Ans ) ;
	return 0 ;
}