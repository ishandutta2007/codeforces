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
int n, R, Z, k, cnt, A[N] ;  
signed main()
{
    n = gi(), k = sqrt(n) ;
    R = n - k - (n - 1) / k ;
    if( R <= 0 ) { puts("0") ; exit(0) ; }
    while(1) {
        printf("%d ", k ) ; cnt = 0 ;
        rep( i, 1, n ) {
            if(A[i] || i % k == 1) continue ; 
            printf("%d ", i ), A[i] = 1, ++ Z, ++ cnt ; 
            if( cnt == k ) break ; 
        }
        puts("") ; 
        int x ; cin >> x ; 
        rep( i, 0, k - 1 ) {
            if( A[(i + x - 1) % n + 1] ) -- Z ;
            A[(i + x - 1) % n + 1] = 0 ; 
        }
        if( Z == R ) break ; 
    }
    puts("0") ; 
    return 0 ;
}