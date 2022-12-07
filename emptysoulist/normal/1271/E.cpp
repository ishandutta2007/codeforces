#include <bits/stdc++.h>
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
int n, k ;
int Get( int u ) {
	int res = 1 , p = u ; u <<= 1 ;
	if( u > n ) {
		if( !( p & 1 ) ) res += Get( p + 1 ) ;
		return res ;
	}
	int cnt = 0 ;
	while( 1 ) {
		u <<= 1, ++ cnt ;
		if( u <= n ) { res += 1ll << cnt ; } 
		else {
			u >>= 1 ; int y = 1 ;
			for( re int i = cnt - 1 ; i != -1; -- i ) {
				if( u + ( 1ll << i ) <= n )
					u += 1ll << i, y += 1ll << i;
			}
			res += y ; if( p % 2 == 0 ) res += Get( p + 1 ) ;
			return res ;
		}
	}
}
int mx = 0 ;
signed main() {
	n = gi(), k = gi() ; int l = 1, r = n >> 1, ans = 0 ;
	while( l <= r ) {
		int mid = l + r >> 1 ;
		if( Get(mid << 1) >= k ) {
			ans = mid, l = mid + 1 ;
		} else r = mid - 1 ;
	}
	mx = max( mx , ans << 1 ) ;
	l = 0, r = ( n - 1 ) >> 1, ans = 0 ;
	while( l <= r ) {
		int mid = l + r >> 1 ;
		if( Get(mid << 1 | 1) >= k ) {
			l = mid + 1, ans = mid ;
		} else r = mid - 1 ;
	}
	mx = max(mx , ans << 1 | 1) ;
	printf("%I64d\n", mx ) ;
	return 0 ;
}