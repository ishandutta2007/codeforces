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
const int P = 998244353 ; 
const int IP = 499122177 ;
const int N = 1e5 + 5 ; 
const int M = 3e5 + 5 ; 
int n, f1, f2, f3, f4, limit, fA, f[M] ;
struct node { int x, y ; } c[N] ;
struct fucti { int a1, a2, a3, a4 ; } g[M] ;
int fpow( int x, int k ) {
	int ans = 1, base = x ; 
	while(k) {
		if(k & 1) ans = ans * base % P ; 
		base = base * base % P, k >>= 1 ; 
	} return ans ; 
}
void FWT( int *a, int type ) {
	for( re int k = 1; k < limit; k <<= 1 ) 
	for( re int i = 0; i < limit; i += ( k << 1 ) ) 
	for( re int j = i; j < i + k; ++ j ) {
		int nx = a[j], ny = a[j + k] ;
		a[j] = (nx + ny) % P, a[j + k] = (nx - ny + P) % P ; 
		if( !type ) a[j] = a[j] * IP % P, a[j + k] = a[j + k] * IP % P ;  
	}
}
void init() {
	memset( f, 0, sizeof(f) ) ; 
} 
void Mod( int &x ) {
	x += P, x += P, x %= P ; 
}
signed main()
{
	n = gi(), limit = gi(), limit = 1 << limit ; int x, y, z ; 
	
	x = gi(), y = gi(), z = gi() ; 
	f1 = x + y + z, f2 = x - y - z, f3 = x + y - z, f4 = x - y + z ; 
	Mod(f1), Mod(f2), Mod(f3), Mod(f4) ; 
	rep( i, 1, n ) {
		x = gi(), y = gi() ^ x, z = gi() ^ x, fA ^= x ; 
		c[i].x = y, c[i].y = z ; 
	}
	
	
	
	rep( i, 1, n ) ++ f[c[i].x] ; FWT( f, 1 ) ; 
	for( re int i = 0; i < limit; ++ i ) g[i].a1 = n, g[i].a2 = f[i] ;

	init() ; rep( i, 1, n ) ++ f[c[i].y] ; FWT( f, 1 ) ; 
	for( re int i = 0; i < limit; ++ i ) g[i].a3 = f[i] ;
	
	init() ; rep( i, 1, n ) ++ f[c[i].x ^ c[i].y] ; FWT( f, 1 ) ; 
	for( re int i = 0; i < limit; ++ i ) g[i].a4 = f[i] ;
	int ip = IP * IP % P ; 
	for( re int i = 0; i < limit; ++ i ) {
		int A = g[i].a1, B = g[i].a2, C = g[i].a3, D = g[i].a4 ; 
		int c1 = A + B + C + D, c2 = A + D - B - C,
			c3 = A + B - C - D, c4 = A + C - B - D ;
		Mod(c1), Mod(c2), Mod(c3), Mod(c4),
		c1 = c1 * ip % P, c2 = c2 * ip % P, c3 = c3 * ip % P, c4 = c4 * ip % P,
		f[i] = fpow( f1, c1 ) * fpow( f2, c2 ) % P * fpow( f3, c3 ) % P * fpow( f4, c4 ) % P ;  
	}
	FWT( f, 0 ) ; 
	for( re int i = 0; i < limit; ++ i ) printf("%lld ", f[fA ^ i] ) ; 
	return 0 ;
}