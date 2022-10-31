#include <bits/stdc++.h>
int n , a[ 202020 ];
int main(){
  scanf( "%d" , &n );
  for( int i = 0 ; i < n ; i ++ )
    scanf( "%d" , &a[ i ] );
  for( int i = 0 ; i < n - i - 1 ; i += 2 )
    std::swap( a[ i ] , a[ n - i - 1 ] );
  for( int i = 0 ; i < n ; i ++ )
    printf( "%d%c" , a[ i ] , " \n"[ i + 1 == n ] );
}