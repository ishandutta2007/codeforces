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
const int N = 3e5 + 5 ; 
int n, m, a[N] ;  
bool check(int x) {
	int LL = 0 ; 
	for(re int i = 1; i <= n; ++ i) {
		int lim = (a[i] + x) % m ;
		if( lim < a[i] ) {
			if( LL > lim ) LL = max( a[i], LL ) ; 
		}
		else { //lim > a[i]
			if( LL > lim ) return 0 ;
			LL = max( LL, a[i] ) ;  
		}
	}
	return 1 ; 
}
signed main()
{
	n = gi(), m = gi() ; 
	rep( i, 1, n ) a[i] = gi() ; 
	int l = 0, r = m - 1, ans = m ; 
	while( l <= r ) {
		int mid = (l + r) >> 1 ; 
		if(check(mid)) ans = mid, r = mid - 1 ; 
		else l = mid + 1 ; 
	}
	cout << ans << endl ; 
	return 0 ;
}