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
const int N = 1e5 + 5 ;
int n, S, Ans, Id, a[N], pre[N] ; 
signed main()
{
	int T = gi() ; 
	while( T-- ) {
		n = gi(), S = gi() ; Ans = 0, Id = 0 ;
		rep( i, 1, n ) a[i] = gi(), pre[i] = pre[i - 1] + a[i] ; 
		pre[n + 1] = S + 1 ; 
		for( re int i = 1; i <= n + 1; ++ i ) if( pre[i] > S ) {
			Ans = i - 1, Id = 0 ; break ; 
		}
		for( re int i = 1; i <= n; ++ i ) {
			int t = pre[i - 1] ; if( t > S ) break ; 
			int tst = i - 1, tm = S - pre[i - 1] ; 
			int l = i + 1, r = n, ans = i ; 
			while( l <= r ) {
				int mid = ( l + r ) >> 1 ; 
				if( pre[mid] - pre[i] <= tm ) ans = mid, l = mid + 1 ; 
				else r = mid - 1 ; 
			}
			tst = tst + ans - i ; if( tst > Ans ) Ans = tst, Id = i ;
		}
		printf("%I64d\n", Id ) ;
		rep( i, 1, n ) a[i] = pre[i] = 0 ;  
	}
	return 0 ;
}