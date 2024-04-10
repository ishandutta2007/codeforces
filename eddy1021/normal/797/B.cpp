#include <bits/stdc++.h>
using namespace std;
#define N 101010
int bst[ 2 ];
int main(){
  bst[ 1 ] = -1000000000;
  int n; scanf( "%d" , &n ); while( n -- ){
    int a; scanf( "%d" , &a );
    int dlt = abs( a ) & 1;
    int tbst[ 2 ];
    for( int i = 0 ; i < 2 ; i ++ ){
      int ni = ( i + dlt ) & 1;
      tbst[ ni ] = bst[ i ] + a;
    }
    for( int i = 0 ; i < 2 ; i ++ )
      bst[ i ] = max( bst[ i ] , tbst[ i ] );
  }
  printf( "%d\n" , bst[ 1 ] );
}