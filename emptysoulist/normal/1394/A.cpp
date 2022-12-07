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
const int N = 2e5 + 5 ; 
int n, d, m, top, b[N], st[N], cnt, sum[N], a[N] ;  
signed main()
{
	n = gi(), d = gi(), m = gi() ; 
	rep( i, 1, n ) {
		a[i] = gi() ; 
		if( a[i] > m ) st[++ top] = a[i] ; 
		else b[++ cnt] = a[i] ;  
	}
	sort( b + 1, b + cnt + 1 ) ;
	sort( st + 1, st + top + 1 ) ;
	rep( i, 1, cnt ) sum[i] = sum[i - 1] + b[i] ;
	int su = 0, ans = sum[cnt] ; 
	for(re int i = top; i >= 1; -- i ) {
		int u = (top - i + 1) ;
		su += st[i] ; 
		int md = (u - 1) * d ; 
		if( md + u <= top ) ans = max( ans, su + sum[cnt] ) ;
		else {
			md -= (top - u) ;
			if( md <= cnt ) ans = max( ans, su + sum[cnt] - sum[md] ) ; 
		}
	}
	cout << ans << endl ; 
	return 0 ;
}