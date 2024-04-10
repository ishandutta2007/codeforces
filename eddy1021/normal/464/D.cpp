#include <stdio.h>
#define D double
#define M 600
#define EPS 1e-200
int n , k;
D p[ 2 ][ M + 1 ];
void solve(){
    D ans = 0;
    p[ 0 ][ 1 ] = 1.000;
    for( int i = 0 ; i < n ; i ++ ){
        int now = i & 1 , nxt = ( i + 1 ) & 1;
        for( int j = 1 ; j < M ; j ++ )
            ans += p[ now ][ j ] * ( j / 2.0 + j / ( j + 1.0 ) );
        for( int j = 1 ; j < M ; j ++ )
            p[ nxt ][ j ] = p[ now ][ j ] * ( 1.0 - ( 1.0 / ( j + 1.0 ) ) / k );
        for( int j = 1 ; j < M ; j ++ )
            p[ nxt ][ j + 1 ] += p[ now ][ j ] / ( j + 1.0 ) / k;
        for( int j = 1 ; j < M ; j ++ )
            if( p[ nxt ][ j ] < EPS ) p[ nxt ][ j ] = 0.0;
    }
    printf( "%.20f\n" , ans );
}
int main(){
    scanf( "%d%d" , &n , &k );
    solve();
}