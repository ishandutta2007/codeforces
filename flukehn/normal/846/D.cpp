#include <bits/stdc++.h>
using namespace std;
#define N 514
#define Q (N * N)
int n , m , k , q , x[ Q ] , y[ Q ] , t[ Q ];
int s[ N ][ N ] , c[ N ][ N ];
bool broken( int cur ){
  for( int i = 0 ; i <= n ; i ++ )
    for( int j = 0 ; j <= m ; j ++ )
      c[ i ][ j ] = 0;
  for( int i = 0 ; i < q ; i ++ )
    if( t[ i ] <= cur )
      c[ x[ i ] ][ y[ i ] ] = 1;
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 1 ; j <= m ; j ++ )
      if( c[ i ][ j ] ){
        s[ i ][ j ] = min( s[ i - 1 ][ j ] ,
                           min( s[ i ][ j - 1 ] , s[ i - 1 ][ j - 1 ] ) ) + 1;
        if( s[ i ][ j ] >= k )
          return true;
      }else
        s[ i ][ j ] = 0;
  return false;
}
int main(){
  cin >> n >> m >> k >> q;
  for( int i = 0 ; i < q ; i ++ )
    cin >> x[ i ] >> y[ i ] >> t[ i ];
  int bl = 0 , br = 1000000000 , ba = -1;
  while( bl <= br ){
    int bmid = (bl + br) >> 1;
    if( broken( bmid ) ) ba = bmid , br = bmid - 1;
    else bl = bmid + 1;
  }
  cout << ba << endl;
}