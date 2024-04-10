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
const int N = 500 + 5 ; 
int n, A, B, C ; 
char s[N], Ans[N] ;
signed main()
{
	int T = gi() ; 
	while( T-- ) {
		n = gi(), A = gi(), B = gi(), C = gi() ; 
		scanf("%s", s + 1 ) ; int ans = 0 ;
		rep( i, 1, n ) {
			if( s[i] == 'R' && B ) Ans[i] = 'P', B--, ++ ans ;
			if( s[i] == 'P' && C ) Ans[i] = 'S', C--, ++ ans ;
			if( s[i] == 'S' && A ) Ans[i] = 'R', A--, ++ ans ;  
		}
		rep( i, 1, n ) {
			if( Ans[i] ) continue ; 
			if( A ) Ans[i] = 'R', A-- ;
			else if( B ) Ans[i] = 'P', B-- ;
			else if( C ) Ans[i] = 'S', C-- ;
		}
		if( ans >= ( ( n + 1 ) / 2 ) ) {
			puts("YES") ;
			printf("%s\n", Ans + 1 ) ;
		}
		else puts("NO") ;
		memset( Ans, 0, sizeof(Ans) ) ;
	}
	return 0 ;
}
/*
R Rock
P Paper
S  
*/