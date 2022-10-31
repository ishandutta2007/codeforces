// eddy1021
#include <bits/stdc++.h>
using namespace std;
int k , cnt[ 10 ];
char c[ 9 ];
int main(){
  scanf( "%d" , &k );
  for( int i = 0 ; i < 4 ; i ++ ){
    scanf( "%s" , c );
    for( int j = 0 ; j < 4 ; j ++ )
      cnt[ c[ j ] == '.' ? 0 : c[ j ] - '0' ] ++;
  }
  for( int i = 1 ; i < 10 ; i ++ )
    if( cnt[ i ] > k + k ){
      puts( "NO" );
      exit( 0 );
    }
  puts( "YES" );
}