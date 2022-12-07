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
int n, a[N], sum[N] ; 
signed main()
{
	int T = gi() ; 
	while( T-- ) {
		n = gi() ;
		rep( i, 1, n ) a[i] = gi() ; 
		memset( sum, 0, sizeof(sum) ) ;  
		sort(a + 1, a + n + 1) ;
		drep( i, 1, n ) sum[i] = sum[i + 1] + a[i] ;
		int flag = 0 ;  
		rep( i, 1, n ) if( sum[i] == 0 ) flag = 1 ;
		int z = 0 ;
		if( !flag ) {
			z = 1 ; 
			puts("YES") ; 
			drep( i, 1, n ) printf("%d ", a[i] ) ;
			puts("") ;
		}
		memset( sum, 0, sizeof(sum) ) ;  
		rep( i, 1, n ) sum[i] = sum[i - 1] + a[i] ;
		flag = 0 ; 
		rep( i, 1, n ) if(sum[i] == 0) flag = 1 ;
		if( !flag && !z ) {
			z = 1 ;
			puts("YES") ; 
			rep( i, 1, n ) printf("%d ", a[i] ) ;
			puts("") ;
			
		}
		if( !z ) puts("NO") ; 
	}
	return 0 ;
}