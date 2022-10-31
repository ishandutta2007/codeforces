#include <bits/stdc++.h>
#define N 200010
using namespace std;
char T[ N ] , a[ 2 ][ N ];
int n;
bool smaller( int no , int l , int r , int l2 , int r2 ){
    for( int i = l , j = l2 ; i <= r ; i ++ , j ++ )
        if( a[ no ][ i ] != a[ no ][ j ] )
            return a[ no ][ i ] < a[ no ][ j ];
    return false;
}
void build( int no , int l , int r ){
    if( ( r - l + 1 ) % 2 ) return;
    int mid = ( l + r ) >> 1;
    build( no , l , mid );
    build( no , mid + 1 , r );
    if( smaller( no , mid + 1 , r , l , mid ) ){
        for( int i = l , j = mid + 1 ; i <= mid ; i ++ , j ++ ){
            T[ i ] = a[ no ][ j ];
            T[ j ] = a[ no ][ i ];
        }
        for( int i = l ; i <= r ; i ++ )
            a[ no ][ i ] = T[ i ];
    }
}
int main() {
    for( int i = 0 ; i < 2 ; i ++ ){
        scanf( "%s" , a[ i ] );
        n = (int)strlen( a[ i ] );
        build( i , 0 , n - 1 );
    }
    for( int i = 0 ; i < n ; i ++ )
        if( a[ 0 ][ i ] != a[ 1 ][ i ] ){
            puts( "NO" );
            return 0;
        }
    puts( "YES" );
}