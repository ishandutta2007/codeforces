#include <bits/stdc++.h>
using namespace std;
#define N 101010
#define MAGIC 514
int n , dp[ N ][ MAGIC ] , a[ N ];
int q , p , k;
int main(){
  scanf( "%d" , &n );
  for( int i = 1 ; i <= n ; i ++ )
    scanf( "%d" , &a[ i ] );
  for( int i = n ; i >= 1 ; i -- )
    for( int j = 1 ; j < MAGIC ; j ++ ){
      int nxt = i + a[ i ] + j;
      dp[ i ][ j ] = nxt > n ? 1 : dp[ nxt ][ j ] + 1;
    }
  scanf( "%d" , &q ); while( q -- ){
    scanf( "%d%d" , &p , &k );
    if( k < MAGIC )
      printf( "%d\n" , dp[ p ][ k ] );
    else{
      int tans = 0;
      while( p <= n ){
        tans ++;
        p = p + a[ p ] + k;
      }
      printf( "%d\n" , tans );
    }
  }
}