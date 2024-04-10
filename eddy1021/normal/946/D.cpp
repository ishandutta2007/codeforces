#include <bits/stdc++.h>
using namespace std;
#define N 514
int n , m , k , dp[ N ] , mn[ N ] , s[ N ];
char c[ N ];
void cal(){
  s[ 0 ] = 0;
  for( int i = 1 ; i <= m ; i ++ )
    s[ i ] = s[ i - 1 ] + c[ i ] - '0';
  for( int i = 0 ; i <= k ; i ++ )
    mn[ i ] = m + m;
  mn[ s[ m ] ] = 0;
  for( int i = 1 ; i <= m ; i ++ )
    for( int j = i ; j <= m ; j ++ ){
      int skp = s[ m ] - s[ j ] + s[ i - 1 ];
      if( skp == s[ m ] )
        mn[ skp ] = 0;
      else
        mn[ skp ] = min( mn[ skp ] , j - i + 1 );
    }
  for( int i = 0 ; i <= k ; i ++ ){
    s[ i ] = dp[ i ];
    dp[ i ] = N * N;
  }
  for( int i = 0 ; i <= k ; i ++ )
    for( int j = 0 ; i + j <= k ; j ++ )
      dp[ i + j ] = min( dp[ i + j ] , s[ i ] + mn[ j ] );
}
int main(){
  scanf( "%d%d%d" , &n , &m , &k );
  for( int i = 1 ; i <= n ; i ++ ){
    scanf( "%s" , c + 1 );
    cal();
  }
  printf( "%d\n" , dp[ k ] );
}