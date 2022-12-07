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
const int P = 1e9 + 7 ;  
const int maxn = 1e6 + 5 ; 
const int M = 999999 ;
int n, a[N], g[N], ans[N], fac[N] ; 
struct node {
	int f1, f2, f3 ; 
	void init( int x ) { f3 = 1, f2 = x, f1 = x * x % P ; }
} f[N] ;
node operator * ( node x, node y ) {
	return (node){
		( x.f1 * fac[y.f3] % P + x.f2 * y.f2 * 2 % P + fac[x.f3] * y.f1 % P ) % P,
		( x.f2 * fac[y.f3] % P + y.f2 * fac[x.f3] % P ) % P, x.f3 + y.f3 } ;
}

signed main()
{
	n = gi(), fac[0] = 1 ; 
	rep( i, 1, n ) fac[i] = fac[i - 1] * 2 % P ; 
	rep( i, 1, n ) {
		a[i] = gi() ; node u ; u.init(a[i]) ;
		f[a[i]] = f[a[i]] * u ;
	}
	int l = 1 ;
	rep( k, 0, 5 ) {
		drep( i, 0, M )
			if( (( i / l ) % 10) ^ 9 ) {
				f[i] = f[i] * f[i + l] ;
			}
		l = l * 10 ;
	}
	rep( i, 0, M ) g[i] = f[i].f1 ; 
	l = 1 ; int Ans = 0 ; 
	rep( k, 0, 5 ) {
		rep( i, 0, M ) 
			if( (( i / l ) % 10) ^ 9 ) g[i] = ( g[i] - g[i + l] + P ) % P ;
		l = l * 10 ;
	}
	rep( i, 0, M ) Ans ^= ( i * ( g[i] % P ) ) ;
	printf("%lld\n", Ans ) ;
	return 0 ;
}