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
const int N = 1e5 + 5 ; 
int r, n, t[N], x[N], y[N], f[N], pre[N] ; 
signed main()
{
	r = gi(), n = gi() ;
	rep( i, 1, n ) t[i] = gi(), x[i] = gi(), y[i] = gi() ; 
	memset( f, -63, sizeof(f) ) ; 
	f[0] = 0 ; x[0] = 1, y[0] = 1 ; 
	for(re int i = 1; i <= n; ++ i) {
		for(re int j = i - 1; j >= 0; -- j) {
			if( t[i] - t[j] >= 2 * r ) {
				f[i] = max( f[i], pre[j] + 1 ) ; 
				break ; 
			} 
			if( t[i] - t[j] >= abs(x[i] - x[j]) + abs(y[i] - y[j]) )
				f[i] = max(f[i], f[j] + 1) ; 
		}
		pre[i] = max( pre[i - 1], f[i] ) ; 
	}
	cout << pre[n] << endl ; 
	return 0 ;
}