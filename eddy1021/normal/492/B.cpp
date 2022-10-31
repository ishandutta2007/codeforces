#include <bits/stdc++.h>
using namespace std;
#define N 1010
typedef double D;
int n , l;
D a[ N ] , ans;
void init(){
    scanf( "%d%d" , &n , &l );
    for( int i = 0 ; i < n ; i ++ )
        scanf( "%lf" , &a[ i ] );
    sort( a , a + n );
}
void solve(){
    ans = max( a[ 0 ] - 0 , l - a[ n - 1 ] );
    for( int i = 0 ; i < n - 1 ; i ++ )
        ans = max( ans , ( a[ i + 1 ] - a[ i ] ) / 2 );
    printf( "%.20f\n" , ans );
}
int main(){
    init();
    solve();
}