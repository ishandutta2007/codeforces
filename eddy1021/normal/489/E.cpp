#include <bits/stdc++.h>
using namespace std;
#define N 1010
#define M 51
#define inf 1e6
#define eps 1e-7
typedef double D;
int n , back[ N ];
D l , a[ N ] , b[ N ] , dp[ N ];
void init(){
    scanf( "%d%lf" , &n , &l );
    for( int i = 1 ; i <= n ; i ++ )
        scanf( "%lf%lf" , &a[ i ] , &b[ i ] );
}
bool can( D tm ){
    for( int i = 1 ; i <= n ; i ++ ){
        dp[ i ] = sqrt( abs( a[ i ] - l ) ) - tm * b[ i ];
        back[ i ] = 0;
    }
    for( int i = 1 ; i <= n ; i ++ )
        for( int j = i + 1 ; j <= n ; j ++ ){
            D dlt = sqrt( abs( a[ j ] - a[ i ] - l ) ) - tm * b[ j ];
            if( dp[ i ] + dlt < dp[ j ] ){
                dp[ j ] = dp[ i ] + dlt;
                back[ j ] = i;
            }
        }
    return dp[ n ] < eps;
}
void print_ans( int now ){
    if( now == 0 ) return;
    print_ans( back[ now ] );
    printf( "%d" , now );
    putchar( now == n ? '\n' : ' ' );
}
void solve(){
    D tl = 0 , tr = inf , tm;
    for( int i = 0 ; i < M ; i ++ ){
        tm = ( tl + tr ) * 0.5;
        if( can( tm ) ) tr = tm;
        else tl = tm;
    }
    print_ans( n );
}
int main(){
    init();
    solve();
}