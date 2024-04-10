// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 514
LL n , a[ N ][ N ];
LL xn , xm;
void init(){
  scanf( "%lld" , &n );
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 1 ; j <= n ; j ++ ){
      scanf( "%lld" , &a[ i ][ j ] );
      if( a[ i ][ j ] == 0 ){
        xn = i;
        xm = j;
      }
    }
}
bool okay( LL ans , LL sum ){
  if( ans <= 0 ) return false;
  a[ xn ][ xm ] = ans;
  for( int i = 1 ; i <= n ; i ++ ){
    LL tsum = 0;
    for( int j = 1 ; j <= n ; j ++ )
      tsum += a[ i ][ j ];
    if( tsum != sum ) return false;
    tsum = 0;
    for( int j = 1 ; j <= n ; j ++ )
      tsum += a[ j ][ i ];
    if( tsum != sum ) return false;
  }
  LL tsum = 0;
  for( int i = 1 ; i <= n ; i ++ )
    tsum += a[ i ][ i ];
  if( tsum != sum ) return false;
  tsum = 0;
  for( int i = 1 ; i <= n ; i ++ )
    tsum += a[ i ][ n - i + 1 ];
  if( tsum != sum ) return false;
  printf( "%lld\n" , ans );
  return true;
}
void solve(){
  if( n == 1 ) puts( "1" );
  else{
    LL sum = 0;
    for( int i = 1 ; i <= n ; i ++ ){
      if( i == xn ) continue;
      for( int j = 1 ; j <= n ; j ++ )
        sum += a[ i ][ j ];
      break;
    }
    LL ssum = sum;
    for( int j = 1 ; j <= n ; j ++ )
      sum -= a[ xn ][ j ];
    if( !okay( sum , ssum ) )
      puts( "-1" );
  }
}
int main(){
  init();
  solve();
}