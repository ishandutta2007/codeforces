#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define int long long
#define bit(x) __builtin_popcountll(x)
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = (1 << 21) + 5 ; 
int limit, n, A[N], B[N], f[30], c[N] ; 
char s[N] ; 
void fwt(int *a) {
	for(re int k = 1; k < limit; k <<= 1) for(re int i = 0; i < limit; ++ i) if(i & k) a[i] += a[i ^ k] ;
}
void ifwt(int *a) {
	for(re int k = 1; k < limit; k <<= 1) for(re int i = 0; i < limit; ++ i) if(i & k) a[i] -= a[i ^ k] ;
}
signed main()
{
	n = gi(), limit = (1 << n) ; f[0] = 1 ; 
	rep( i, 1, 21 ) f[i] = f[i - 1] * 4 ; 
	scanf("%s", s ) ; 
	for(re int i = 0; i < limit; ++ i) A[i] = (s[i] - '0') * f[bit(i)] ;
	scanf("%s", s ) ;
	for(re int i = 0; i < limit; ++ i) B[i] = (s[i] - '0') * f[bit(i)] ;
	fwt(A), fwt(B); 
	for(re int i = 0; i < limit; ++ i) A[i] = A[i] * B[i] ;
	ifwt(A) ; 
	for(re int i = 0; i < limit; ++ i) A[i] = A[i] >> (bit(i) << 1) ; 
	for(re int i = 0; i < limit; ++ i) printf("%lld", A[i] & 3ll ) ; 
	return 0 ;
}