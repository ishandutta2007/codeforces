#include<bits/stdc++.h>
using namespace std ;
#define int long long
int read() {
    char cc = getchar() ; int cn = 0 ;
    while( cc > '9' || cc < '0' ) cc = getchar() ;
    while( cc >= '0' && cc <= '9' ) cn = cn * 10 + cc - '0', cc = getchar() ;
    return cn ;
}
int gcd( int a, int b ) {
    if( a == 0 ) return b ; 
    return gcd( b % a, a ) ;
}
int h, a, w ; 
signed main() {
    a = read(), h = read(), w = read() ;
    int g = gcd( h + a, w + a ) ;
    int y = g / a ;
    if( y == 0 || h < a || w < a ) puts("-1");
    else printf("%lf\n", ( 1.0 * g / y ) - a ) ;
    return 0 ;
}