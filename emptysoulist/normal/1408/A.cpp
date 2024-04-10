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
const int N = 1000 + 5 ; 
int n, a[N], b[N], c[N], p[N] ; 
signed main()
{
	int T = gi() ; 
	while(T--) {
		n = gi() ; 
		rep( i, 1, n ) a[i] = gi() ;
		rep( i, 1, n ) b[i] = gi() ; 
		rep( i, 1, n ) c[i] = gi() ; 
		p[1] = a[1] ;
		for(int i = 2; i < n; ++ i) {
			if( a[i] != p[i - 1] ) p[i] = a[i] ;
			if( b[i] != p[i - 1] ) p[i] = b[i] ;
			if( c[i] != p[i - 1] ) p[i] = c[i] ;
		}
		if( a[n] != p[n - 1] && a[n] != p[1] ) p[n] = a[n] ;
		if( b[n] != p[n - 1] && b[n] != p[1] ) p[n] = b[n] ;
		if( c[n] != p[n - 1] && c[n] != p[1] ) p[n] = c[n] ;
		rep( i, 1, n ) printf("%d ", p[i] ) ; puts("") ; 
	} 
	return 0 ;
}