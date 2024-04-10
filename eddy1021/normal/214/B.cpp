#include <bits/stdc++.h>
using namespace std;
int n , c[ 10 ] , x , mn[ 3 ] = {10, 10, 10};
int main(){
  cin >> n; while( n -- ){
    cin >> x; c[ x ] ++;
    mn[ x % 3 ] = min( mn[ x % 3 ] , x );
  }
  if( !c[ 0 ] ){
    puts( "-1" );
    exit(0);
  }
  int tar = 0;
  for( int i = 0 ; i < 10 ; i ++ )
    tar = ( tar + i * c[ i ] ) % 3;
  if( tar ){
    if( mn[ tar ] < 10 )
      c[ mn[ tar ] ] --;
    else{
      for( int i = 3 - tar , res = 2 ; res > 0 ; i += 3 )
        while( res > 0 and c[ i ] ){
          c[ i ] --;
          res --;
        }
    }
  }
  int pp = 0;
  for( int i = 9 ; i ; i -- )
    while( c[ i ] -- ){
      printf( "%d" , i );
      pp = 1;
    }
  if( !pp ) c[ 0 ] = 1;
  while( c[ 0 ] -- ) putchar( '0' );
  puts( "" );
}