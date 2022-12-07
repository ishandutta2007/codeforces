#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 1000 + 5 ; 
int m, n, b[N], c[N], top ; 
signed main()
{
	int T = gi() ; 
	while( T-- ) {
		m = n = gi(), top = 0  ;
		for( re int i = 2; i <= sqrt(n); ++ i ) {
			if( n % i == 0 ) {
				b[++ top] = i ;
				while( n % i == 0 ) ++ c[top], n /= i ;
			}
		} if( n != 1 ) b[++ top] = n, c[top] = 1 ;
		if( top >= 3 ) {
			int A = b[1], B = b[2] ;
			int C = m / A / B ; 
			puts("YES") ;
			printf("%I64d %I64d %I64d\n", A, B, C ) ;
		}
		else if( top == 1 ) {
			if( c[1] >= 6 ) {
				int A = b[1], B = b[1] * b[1] ;
				int C = m / A / B ; 
				puts("YES") ;
				printf("%I64d %I64d %I64d\n", A, B, C ) ;
			} else puts("NO") ;
		}
		else if( top == 2 ) {
			int A = b[1], B = b[2] ;
			int C = m / A / B ; 
			if( C == A || C == B || C == 1 ) puts("NO") ;
			else {
				puts("YES") ;
				printf("%I64d %I64d %I64d\n", A, B, C ) ;
			}
		}
		rep( i, 1, top ) b[i] = c[i] = 0 ;
	}
	return 0 ;
}