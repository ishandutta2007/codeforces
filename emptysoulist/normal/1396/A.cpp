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
const int N = 1e5 + 5 ; 
int n, a[N], fac[N] ;  
signed main()
{
	n = gi() ; 
	rep( i, 1, n ) a[i] = gi() ; 
	if(n == 1) {
		printf("1 1\n") ;
		printf("%lld\n", -a[1] ) ;
		
		printf("1 1\n") ;
		puts("0") ; 
		printf("1 1\n") ;
		puts("0") ; 
		exit(0) ; 
	}
	printf("1 %lld\n", n ) ; 
	int k = n - 1 ; 
	rep( i, 1, n ) {
		int u = k - a[i] % k ; 
		printf("%lld ", 1ll * u * n ) ; 
		a[i] += u * n ; 
	}
	puts("") ; 
	printf("1 1\n") ;
	printf("%lld\n", -a[1] ) ;
	printf("2 %lld\n", n ) ;
	rep( i, 2, n ) printf("%lld ", -a[i] ) ; 
	return 0 ;
}