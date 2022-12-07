#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 5000 + 5 ; 
int n, Ans ;
void init() {
	Ans = 0 ;
}
signed main() {
	int T = gi() ;
	while( T -- ) {
		n = gi(), init() ; 
		for( re int l = 1, r; l <= n; l = r + 1 )
			r = n / ( n / l ), ++ Ans ;
		printf("%d\n", Ans + 1 ) ;
		printf("0 ") ; 
		for( re int l = 1, r ; l <= n ; l = r + 1 ) {
			r = n / ( n / l ), printf("%d ", r ) ;
		}
		puts("") ;
	}
	return 0;
}