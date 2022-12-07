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
const int N = 2e5 + 5 ; 
int T, n, st[N], top, a[N] ;  
signed main()
{
	T = gi() ; 
	while( T-- ) {
		n = gi() ; 
		rep( i, 1, n ) a[i] = gi() ; 
		int flag = a[1] ;
		rep( i, 2, n ) if( a[i] != flag ) flag = -1 ; 
		if( flag != -1 ) printf("%lld\n", n ) ;
		else puts("1") ; 
	}
	return 0 ;
}