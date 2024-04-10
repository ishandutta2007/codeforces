#include <bits/stdc++.h>
using namespace std;
#define N 111
char c[ N ];
int dp[ N ][ 3 ];
void no(){
  puts( "No" );
  exit(0);
}
int color( char ctmp ){
  if( ctmp == 'C' ) return 1;
  if( ctmp == 'M' ) return 2;
  if( ctmp == 'Y' ) return 4;
  return 7;
}
int len ,clr[ N ];
int main(){
  cin >> len;
  scanf( "%s" , c );
  for( int i = 0 ; i < len ; i ++ )
    clr[ i ] = color( c[ i ] );
  for( int i = 0 ; i < 3 ; i ++ )
    if( (clr[ 0 ] >> i) & 1 )
      dp[ 0 ][ i ] = 1;
  for( int i = 0 ; i + 1 < len ; i ++ )
    for( int j = 0 ; j < 3 ; j ++ ){
      if( dp[ i ][ j ] == 0 ) continue;
      for( int nj = 0 ; nj < 3 ; nj ++ ){
        if( ((clr[ i + 1 ] >> nj) & 1) and j != nj ){
          dp[ i + 1 ][ nj ] += dp[ i ][ j ];
          dp[ i + 1 ][ nj ] = min( dp[ i + 1 ][ nj ] , 2 );
        }
      }
    }
  int tot = 0;
  for( int i = 0 ; i < 3 ; i ++ )
    tot += dp[ len - 1 ][ i ];
  if( tot < 2 ) no();
  puts( "Yes" );
}