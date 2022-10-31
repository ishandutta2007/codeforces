#include <bits/stdc++.h>
using namespace std;
#define N 505050
#define K 111
#define P 111
const int inf = 1e6;
int n , k , p , a[ N ];
int BIT[ 2 ][ K ][ P ];
int lb[ P ];
void modify( int no , int nk , int pp , int vl ){
  for( int i = pp ; i < P ; i += lb[ i ] )
    BIT[ no ][ nk ][ i ] = min(
      BIT[ no ][ nk ][ i ] , vl );
}
int query( int no , int nk , int pp ){
  int ret = inf;
  for( int i = pp ; i ; i -= lb[ i ] )
    ret = min( ret , BIT[ no ][ nk ][ i ] );
  return ret;
}
int main(){
  for( int i = 0 ; i < P ; i ++ )
    lb[ i ] = i & (-i);
  for( int i = 0 ; i < 2 ; i ++ )
    for( int j = 0 ; j < K ; j ++ )
      for( int ip = 0 ; ip < P ; ip ++ )
        BIT[ i ][ j ][ ip ] = inf;
  scanf( "%d%d%d" , &n , &k , &p );
  for( int i = 1 ; i <= n ; i ++ ){
    scanf( "%d" , &a[ i ] );
    a[ i ] = (a[ i ] + a[ i - 1 ]) % p;
  }
  modify( 0 , 0 , 1 , 0 );
  modify( 1 , 0 , p , 0 );
  for( int i = 1 ; i <= n ; i ++ ){
    for( int kk = k - 1 ; kk >= 0 ; kk -- ){
    //for( int kk = 0 ; kk < k ; kk ++ ){
      int bst = inf;
      {
        int pre = query( 0 , kk , a[ i ] + 1 );
        if( pre != inf ){
          int tans = pre + a[ i ];
          bst = min( bst , tans );
        }
      }
      {
        int nxt = query( 1 , kk , p - a[ i ] );
        if( nxt != inf ){
          int tans = nxt + a[ i ] + p;
          bst = min( bst , tans );
        }
      }
      if( i == n and kk + 1 == k ){
        printf( "%d\n" , bst );
        exit(0);
      }
      //printf( "%d %d -> %d\n" , i , kk , bst );
      if( bst != inf ){
        modify( 0 , kk + 1 , a[ i ] + 1 , bst - a[ i ] );
        modify( 1 , kk + 1 , p - a[ i ] , bst - a[ i ] );
      }
    }
  }
}