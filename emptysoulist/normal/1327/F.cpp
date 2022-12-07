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
const int N = 5e5 + 5 ; 
const int P = 998244353 ; 
int n, m, k, a[N], f[N], Lx[N], ll[N], Nxt[N], Ans = 1 ; 
struct S {
	int l, r, x ; 
} q[N] ;
signed main()
{
	n = gi(), k = gi(), m = gi() ; 
	rep( i, 1, m ) q[i].l = gi(), q[i].r = gi(), q[i].x = gi() ;
	for( re int l = 0; l < k; ++ l ) {
		int L = -1, S = 0, ans = 0 ;
		rep( i, 1, n ) ll[i] = -1 ;  
		rep( i, 1, m ) {
			if( q[i].x & ( 1ll << l ) ) ++ Lx[q[i].l], -- Lx[q[i].r + 1] ; 
			else ll[q[i].r] = max( ll[q[i].r], q[i].l - 1 ) ; 
		}
		rep( i, 1, n ) S += Lx[i], a[i] = S ? 1 : 0 ; 
		f[0] = 1, Nxt[0] = f[0] ;
		for( re int i = 1; i <= n; ++ i ) {
			if( a[i] ) f[i] = 0 ;
			else f[i] = ( Nxt[i - 1] - ( ( L >= 0 ) ? Nxt[L] : 0 ) + P ) % P ; 
			L = max( L, ll[i] ), Nxt[i] = ( Nxt[i - 1] + f[i] ) % P ; 
		}
		for( re int i = L + 1; i <= n; ++ i ) ans = ( ans + f[i] ) % P ; 
		Ans = Ans * ans % P ; 
		rep( i, 1, n + 1 ) f[i] = Nxt[i] = Lx[i] = a[i] = 0 ; 
	}
	cout << Ans << endl ; 
	return 0 ;
}