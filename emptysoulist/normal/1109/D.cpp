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
const int P = 1e9 + 7 ;
const int N = 1e6 + 5 ;  
int n, m, fac[N], inv[N], mf[N], nf[N] ;  
int fpow( int x, int k ) {
    int ans = 1, base = x  ;
    while( k ) {
        if( k & 1 ) ans = ans * base % P ;
        base = base * base % P, k >>= 1 ; 
    } return ans ; 
}
int C( int x, int y ) {
    if( x < y ) return 0 ;
    return 1ll * fac[x] * inv[y] % P * inv[x - y] % P ;  
}
signed main()
{
    n = gi(), m = gi(), mf[0] = nf[0] = fac[0] = inv[0] = 1 ; 
    rep( i, 1, max( n, m ) ) fac[i] = fac[i - 1] * i % P, inv[i] = fpow( fac[i], P - 2 ) ;
    rep( i, 1, n ) mf[i] = mf[i - 1] * m % P, nf[i] = nf[i - 1] * n % P ; 
    int Ans = fac[n - 2] * C(m - 1, n - 2) % P ; 
    for( re int i = 2; i < n; ++ i ) {
        int x = fac[n - 2] * inv[n - i] % P * i % P * nf[n - i - 1] % P * C(m - 1, i - 2) % P * mf[n - i] % P ; 
        Ans = ( Ans + x ) % P ; 
    }
    cout << Ans << endl ; 
    return 0 ;
}