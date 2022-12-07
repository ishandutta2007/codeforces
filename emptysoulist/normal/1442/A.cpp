#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 30000 + 5 ; 
int n, a[N] ; 
signed main()
{
	int T = gi() ; 
	while( T-- ) {
		n = gi() ; 
		rep( i, 1, n ) a[i] = gi() ; 
		int ll = a[1], flag = 0 ; 
		rep( i, 1, n ) {
			ll = min( ll, a[i] ) ;
			if( a[i] - ll >= a[i - 1] ) 
				a[i] -= ll ; 
			else {
				ll = a[i] - a[i - 1] ;
				if( ll < 0 ) flag = 1 ; 
				a[i] -= ll ; 
			}
		}
		if( flag ) puts("NO") ; 
		else puts("YES") ; 
	}
	return 0 ;
}