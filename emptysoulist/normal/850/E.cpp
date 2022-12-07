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
const int Iv2 = 5e8 + 4 ;
const int N = ( 1 << 21 ) ;
int n, limit, f[N], g[N], fac[N] ; 
char s[N] ; 
int lowbit( int x ) {
    return __builtin_popcountll(x) ;
}
void FWT_xor( int *a, int type ) {
	for( re int k = 1; k < limit; k <<= 1 ) 	
	for( re int i = 0; i < limit; i = ( i + ( k << 1 ) ) ) 
		for( re int j = i; j < i + k; ++ j ) {
			int nx = a[j], ny = a[j + k] ;
			( type == 1 ) ? ( a[j] = ( nx + ny ) % P, a[j + k] = ( nx - ny + P ) % P ) : ( a[j] = ( nx + ny ) * Iv2 % P, 
				a[j + k] = ( nx - ny + P ) * Iv2 % P ) ; 
		}
}
signed main()
{
	n = gi(), limit = ( 1 << n ) ;
	scanf("%s", s ) ; int S = limit - 1 ; 
	rep( i, 0, limit - 1 ) f[i] = s[i] - '0' ;
	for( int i = 0; i < limit; ++ i ) g[i] = f[i ^ S] ;
	FWT_xor( f, 1 ), FWT_xor( g, 1 ) ;
	rep( i, 0, limit ) g[i] = f[i] * g[i] % P ; 
	FWT_xor( g, 0 ) ; int Ans = 0 ;
	fac[0] = 1 ; 
	rep( i, 1, 25 ) fac[i] = fac[i - 1] * 2 % P ;  
	rep( i, 0, limit ) Ans = ( Ans + g[i] * fac[lowbit(i)] % P ) % P ; 
	cout << ( Ans * 3 ) % P << endl ;
	return 0 ;
}