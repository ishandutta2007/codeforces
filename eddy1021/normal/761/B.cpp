#include <bits/stdc++.h>
using namespace std;
#define N 55
int n , l , a[ N ] , b[ N ];
bool okay( int st ){
  int dlt = ( b[ st ] - a[ 0 ] + l ) % l;
  for( int i = 0 ; i < n ; i ++ )
    if( ( a[ i ] + dlt ) % l != b[ ( st + i ) % n ] )
      return false;
  return true;
}
int main(){
  scanf( "%d%d" , &n , &l );
  for( int i = 0 ; i < n ; i ++ )
    scanf( "%d" , &a[ i ] );
  for( int i = 0 ; i < n ; i ++ )
    scanf( "%d" , &b[ i ] );
  for( int i = 0 ; i < n ; i ++ )
    if( okay( i ) ){
      puts( "YES" );
      exit( 0 );
    }
  puts( "NO" );
}