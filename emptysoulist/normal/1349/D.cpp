// ... 
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
const int N = 3e5 + 5 ; 
const int P = 998244353 ; 
int n, Ans, S, a[N], f[N], nxt[N], C ; 
int fpow( int x, int k ) {
	int ans = 1, base = x ; 
	while( k ) {
		if( k & 1 ) ans = ans * base % P ; 
		base = base * base % P, k >>= 1 ; 
	} return ans ; 
}
int d( int a, int b ) {
	return a * fpow( b, P - 2 ) % P ; 
}
signed main()
{
	n = gi() ; 
	rep( i, 1, n ) a[i] = gi(), S += a[i] ; 
	f[0] = n - 1 ; int iv = d(n - 2, n - 1) ;
	for( re int i = 1; i < S; ++ i ) {
		int k = ( d(S - i, S) * iv % P + d(i, S) ) % P ; 
		k = ( P + 1 - k ) % P ; 
		f[i] = ( 1 + d(i, S) * f[i - 1] % P ) * d(1, k) % P ; 
	}
	for( re int i = S; i >= 0; -- i ) nxt[i] = ( f[i] + nxt[i + 1] ) % P ; 
	C = nxt[0] ; Ans = P - ( n - 1 ) * C % P ; 
	rep( i, 1, n ) Ans = ( Ans + nxt[a[i]] ) % P ;
	printf("%lld\n", d(Ans, n) ) ;
	return 0 ;
}