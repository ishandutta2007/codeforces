#include <bits/stdc++.h>
using namespace std;
#define N 202020
int n , a[ N ] , d[ N ];
int main(){
  scanf( "%d" , &n );
  for( int i = 0 ; i < n ; i ++ ){
    scanf( "%d" , &a[ i ] );
    d[ i ] = N + N;
  }
  for( int i = 0 , l = -N ; i < n ; i ++ ){
    if( a[ i ] == 0 ) l = i;
    d[ i ] = min( d[ i ] , i - l );
  }
  for( int i = n - 1 , r = n + N ; i >= 0 ; i -- ){
    if( a[ i ] == 0 ) r = i;
    d[ i ] = min( d[ i ] , r - i );
  }
  for( int i = 0 ; i < n ; i ++ )
    printf( "%d%c" , d[ i ] , " \n"[ i + 1 == n ] );
}