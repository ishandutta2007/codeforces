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
const int P = 1e9 + 7 ;  
const int N = 1e5 + 5 ; 
int fpow(int x, int k) {
	int ans = 1, base = x ;
	while(k) {
		if(k & 1) ans = 1ll * ans * base % P ;
		base = 1ll * base * base % P, k >>= 1 ;
	} return ans ;
}
int n, m, c, a[N], f[N], inv[N] ;  
signed main()
{
	n = gi() ; f[0] = 0 ; 
	rep( i, 1, n ) a[i] = gi(), c += a[i], m = max( m, a[i] ) ; 
	rep( i, 0, m ) inv[i] = fpow(c - i, P - 2) ; 
	rep( i, 1, m ) inv[i] = (inv[i - 1] + inv[i]) % P ; 
	rep( i, 1, m ) f[i] = (c - 1) * (c - i) % P * inv[i - 1] % P ; 
	int ans = 0 ;
	rep( i, 1, n ) ans = (ans + f[a[i]]) % P ; 
	cout << ans % P << endl ; 
	return 0 ;
}