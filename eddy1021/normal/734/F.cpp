// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 202020
LL n , a[ N ] , b[ N ] , c[ N ];
void init(){
  scanf( "%lld" , &n );
  for( int i = 0 ; i < n ; i ++ )
    scanf( "%lld" , &b[ i ] );
  for( int i = 0 ; i < n ; i ++ )
    scanf( "%lld" , &c[ i ] );
}
#define K 30
LL sum , cnt[ K ];
void solve(){
  for( int i = 0 ; i < n ; i ++ )
    sum += b[ i ] + c[ i ];
  if( sum % ( n + n ) ){
    puts( "-1" );
    exit( 0 );
  }
  sum /= ( n + n );
  for( int i = 0 ; i < n ; i ++ ){
    LL ret = b[ i ] + c[ i ];
    ret -= sum;
    if( ret < 0 || ret % n ){
      puts( "-1" );
      exit( 0 );
    }
    a[ i ] = ret / n;
  }
  for( int i = 0 ; i < n ; i ++ )
    for( int j = 0 ; j < K ; j ++ )
      if( ( a[ i ] >> j ) & 1ll )
        cnt[ j ] ++;
  for( int i = 0 ; i < n ; i ++ ){
    LL nb = 0 , nc = 0;
    for( int j = 0 ; j < K ; j ++ )
      if( ( a[ i ] >> j ) & 1ll ){
        nb += ( 1ll << j ) * cnt[ j ];
        nc += ( 1ll << j ) * n;
      }else
        nc += ( 1ll << j ) * cnt[ j ];
    if( nb != b[ i ] || nc != c[ i ] ){
      puts( "-1" );
      exit( 0 );
    }
  }
  for( int i = 0 ; i < n ; i ++ )
    printf( "%lld%c" , a[ i ] , " \n"[ i + 1 == n ] );
}
int main(){
  init();
  solve();
}