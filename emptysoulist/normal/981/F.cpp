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
const int N = 1e6 + 5 ; 
int n, m, a[N], b[N], ll[N], rr[N] ; 
bool check(int x) {
	int l = 1, r = 4 * n ; 
	for(re int i = n + 1; i <= 3 * n; ++ i) {
		while( a[l] < b[i] - x ) ++ l ;
		ll[i] = l - i ; 
	}
	for(re int i = 3 * n; i >= n + 1; -- i) {
		while( a[r] > b[i] + x ) -- r ; 
		rr[i] = r - i ; 
	}
	for(re int i = n + 2; i <= 3 * n; ++ i) ll[i] = max(ll[i - 1], ll[i]) ; 
	for(re int i = n + 1; i <= 3 * n; ++ i) if(rr[i] < ll[i]) return 0 ; 
	return 1 ; 
}
signed main()
{
	n = gi(), m = gi() ; 
	rep( i, 1, n ) a[i] = gi() ;
	rep( i, 1, n ) b[i] = gi() ; 
	sort(a + 1, a + n + 1), sort(b + 1, b + n + 1) ;
	rep( i, 1, n ) 
		a[i + n] = a[i] + m, a[i + 2 * n] = a[i] + 2 * m, a[i + 3 * n] = a[i] + 3 * m,
		b[i + n] = b[i] + m, b[i + 2 * n] = b[i] + 2 * m, b[i + 3 * n] = b[i] + 3 * m;
	int l = 0, r = m, ans = 0 ;
	while( l <= r ) {
		int mid = (l + r) >> 1 ; 
		if( check(mid) ) ans = mid, r = mid - 1 ;
		else l = mid + 1 ; 
	}
	cout << ans << endl ; 
	return 0 ;
}