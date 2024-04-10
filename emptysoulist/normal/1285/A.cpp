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
const int N = 1e5 + 5 ; 
char s[N] ; 
int L, R ; 
signed main()
{
	int n = gi() ; 
	scanf("%s", s + 1 ) ;
	rep( i, 1, n ) if( s[i] == 'L' ) ++ L ; 
	rep( i, 1, n ) if( s[i] == 'R' ) ++ R ; 
	printf("%d\n", L + R + 1 ) ;
	return 0 ;
}