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
const int N = 5000 + 5 ; 
int T, n ;
char s[N], ans[N], Md[N] ; 
bool check( char *a, char *b ) {
	rep( i, 1, n ) if( a[i] != b[i] ) return a[i] < b[i] ;
	return 0 ;
} 
signed main()
{
	T = gi() ; 
	while( T-- ) {
		n = gi() ; int keai = 1, Imakf = keai ;
		scanf("%s", s + 1 ) ; 
		ans[1] = 'z' + 1 ; int Id = 0 ;
		rep( k, 1, n ) {
			rep( j, k, n ) Md[j - k + 1] = s[j] ;
			if( ( n - k ) % 2 == 1 ) {
				for( int j = 1; j < k; ++ j ) Md[n - k + 1 + j] = s[j] ;
				++ Imakf ;
			}
			else {
				-- Imakf ; 
				for( int j = 1; j < k; ++ j ) Md[n - k + j + 1] = s[k - j] ;
			}
			if( check( Md, ans ) ) {
				Id = k, ++ Imakf ;
				rep( j, 1, n ) ans[j] = Md[j] ;
			}
		}
		ans[n + 1] = 0;
		printf("%s\n%d\n", ans + 1, Id ) ;
	}
	return 0 ;
}