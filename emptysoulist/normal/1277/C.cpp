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
int T, ans, Ck[N], top ;
char s[N] ; 
signed main()
{
	T = gi() ; 
	while( T-- ) {
		scanf("%s", s + 1 ) ; int m = strlen( s + 1 ) ;
		for( re int i = 1; i <= m; ++ i ) {
			if( s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o' && s[i + 3] == 'n' && s[i + 4] == 'e' ) {
				++ ans ; Ck[++ top] = i + 2 ; i += 4 ; 
			}
			else if( s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o' ) {
				++ ans; Ck[++ top] = i + 1 ; i += 2 ; 
			}
			else if( s[i] == 'o' && s[i + 1] == 'n' && s[i + 2] == 'e' ) {
				++ ans ; Ck[++ top] = i + 1 ; i += 2 ;
			}
		}
		printf("%d\n", ans ) ;
		for( re int i = 1; i <= top; ++ i ) printf("%d ", Ck[i] ) ;
		puts("") ;
		top = ans = 0 ; 
	}
	return 0 ;
}