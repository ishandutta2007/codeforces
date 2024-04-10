#include <bits/stdc++.h>
using namespace std;
#define N 20202
#define K 52
#define P 111
const int inf = 1e6;
int n , k , p , a[ N ];
int dp[ P ][ K ];
int main(){
  scanf( "%d%d%d" , &n , &k , &p );
  for( int i = 1 ; i <= n ; i ++ ){
    scanf( "%d" , &a[ i ] );
    a[ i ] = (a[ i ] + a[ i - 1 ]) % p;
  }
  for( int i = 0 ; i < p ; i ++ )
    for( int j = 0 ; j <= k ; j ++ )
      dp[ i ][ j ] = -inf;
  dp[ 0 ][ 0 ] = 0;
  for( int i = 1 ; i <= n ; i ++ ){
    for( int kk = 0 ; kk < k ; kk ++ ){
      int bst = -inf;
      for( int j = 0 ; j < p ; j ++ ){
        if( dp[ j ][ kk ] == -inf ) continue;
        int sc = (a[ i ] - j + p) % p;
        bst = max( bst , dp[ j ][ kk ] + sc );
      }
      if( i == n and kk + 1 == k ){
        printf( "%d\n" , bst );
        exit(0);
      }
      dp[ a[ i ] ][ kk + 1 ] = max(
        dp[ a[ i ] ][ kk + 1 ] , bst );
    }
  }
}