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
const int N = 20 + 5 ;
const int M = 20 + 5 ;
char s[N][M], t[N][M] ; 
int n, m ;
signed main()
{
	n = gi(), m = gi() ;
	rep( i, 1, n ) scanf("%s", s[i] + 1 ) ;
	
	rep( i, 1, m ) scanf("%s", t[i] + 1 ) ;
	int Q = gi() ;
	while( Q-- ) {
		int x = gi() ; 
		int t1 = ( x - 1 ) % n + 1, t2 = ( x - 1 ) % m + 1 ;
		printf("%s", s[t1] + 1 ), printf("%s", t[t2] + 1 ) ;
		puts("") ; 
	}
	return 0 ;
}