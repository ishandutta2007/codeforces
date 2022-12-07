#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 100 + 5 ; 
int a[N], n ; 
int abc(int x) {
	return (x < 0) ? -x : x ; 
}
signed main()
{
	int T = gi() ; 
	while( T-- ) {
		n = gi() ; 
		rep( i, 1, n ) a[i] = gi() ; 
		rep( i, 1, n ) {
			a[i] = abc(a[i]) ; 
			if( i & 1 ) printf("%d ", a[i] ) ;
			else printf("%d ", -a[i] ) ; 
		}
		puts("") ; 
	}
	return 0 ;
}