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
const int N = 200000 + 5 ; 
const int P = 998244353 ; 
int fpow(int x, int k) {
	int ans = 1, base = x ;
	while(k) {
		if(k & 1) ans = 1ll * ans * base % P ;
		base = 1ll * base * base % P, k >>= 1 ;
	} return ans ;
}
int n, k, a[N], b[N], Id[N], vis[N] ; 
signed main()
{
	int T = gi() ; 
	while( T-- ) {
		n = gi(), k = gi() ; 
		rep( i, 1, n ) {
			a[i] = gi(), Id[a[i]] = i ; 
		}
		rep( i, 1, n ) vis[i] = 1 ; 
		rep( i, 1, k ) {
			b[i] = gi() ; 
		}
		int ans = 1 ; 
		for(re int i = k; i >= 1; -- i) {
			int u = Id[b[i]] ;
			int p = vis[u - 1] + vis[u + 1] ;
			ans = ans * p % P ; 
			vis[u] = 0 ; 
		}
		rep( i, 1, n ) vis[i] = 0 ; 
		printf("%lld\n", ans ) ; 
	}
	return 0 ;
}