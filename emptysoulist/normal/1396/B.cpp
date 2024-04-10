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
int T, n, a[N] ; 
signed main()
{
	T = gi() ; 
	while(T--) {
		n = gi() ; int mx = 0 ; 
		rep( i, 1, n ) a[i] = gi(), mx = max( mx, a[i] ) ; 
		int s = 0 ; 
		rep( i, 1, n ) s += a[i] ;
		if( mx * 2 > s ) puts("T") ;
		else if( s & 1 ) puts("T") ; 
		else puts("HL") ; 
	}
	return 0 ;
}