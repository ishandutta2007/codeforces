#include <bits/stdc++.h>
using namespace std;
#define N 111
int n , m , dp[ N ][ 8 ];
char c[ N ][ N ];
int type( char ctmp ){
  if( isdigit( ctmp ) ) return 0;
  if( isalpha( ctmp ) ) return 1;
  return 2;
}
int main(){
  scanf( "%d%d" , &n , &m );
  for( int i = 1 ; i <= n ; i ++ )
    scanf( "%s" , c[ i ] );
  for( int i = 0 ; i <= n ; i ++ )
    for( int j = 0 ; j < 8 ; j ++ )
      dp[ i ][ j ] = N * N;
  dp[ 0 ][ 0 ] = 0;
  for( int i = 0 ; i < n ; i ++ )
    for( int j = 0 ; j < 8 ; j ++ )
      for( int k = 0 ; k < m ; k ++ ){
        int nxtj = j | ( 1 << type( c[ i + 1 ][ k ] ) );
        dp[ i + 1 ][ nxtj ] = min( dp[ i + 1 ][ nxtj ] ,
                                   dp[ i ][ j ] + min( k , m - k  ) );
      }
  printf( "%d\n" , dp[ n ][ 7 ] );
}