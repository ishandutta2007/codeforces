#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 2e5 + 5 ;
const int M = 450 + 5;
int n, cnt, a[N], c[N], t[N * M + N] ;
long long Ans ; 
char s[N] ; 
signed main()
{
	scanf("%s", s + 1 ), n = strlen( s + 1 ), cnt = sqrt(n) ; 
	for( re int k = 1; k <= cnt; ++ k ) {
		++ t[n], a[0] = 0 ;
		rep( i, 1, n )
		a[i] = a[i - 1] + ( ( s[i] == '1' ) ? ( k - 1 ) : -1 ), Ans += 1ll * t[a[i] + n], ++ t[a[i] + n] ;
		rep( i, 0, n ) t[a[i] + n] = 0, a[i] = 0 ;
	} 
	int sz = n / cnt, L = 0, R = 0 ;
	rep( i, 1, n ) c[i] = c[i - 1] + ( s[i] == '1' ) ;
	for( re int k = 1; k <= sz; ++ k ) {
		L = 0, R = 0 ;
		rep( i, 1, n ) {
			if( c[i] < k ) continue ;
			while( c[i] - c[R + 1] == k ) ++ R ;
			while( c[i] - c[L] > k ) ++ L ; 
			Ans += 1ll * max( 0, ( i - L ) / k - max( ( i - R - 1 ) / k, cnt ) ) ;
		}
	} printf("%lld\n", Ans ) ;
	return 0 ;
}