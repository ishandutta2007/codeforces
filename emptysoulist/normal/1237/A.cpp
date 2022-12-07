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
const int N = 50000 + 5 ; 
int a[N], b[N], n ; 
signed main()
{
    n = gi() ; int Sum = 0, Sum2 = 0 ;
    rep( i, 1, n ) a[i] = gi(), Sum += a[i], b[i] = abs( a[i] % 2 ), Sum2 += b[i] ; 
    int rSum = Sum + Sum2 ; 
    rep( i, 1, n ) {
        if( rSum == 0 ) break ; 
        if( rSum > 0 && b[i] == 1 ) rSum -= 2, b[i] = -b[i] ;
    }
    rep( i, 1, n ) printf("%d\n", ( a[i] + b[i] ) / 2 ) ;
	return 0 ;
}