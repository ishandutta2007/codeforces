#include <bits/stdc++.h>
using namespace std;
#define N 1021
#define K 303030
typedef long long LL;
int n , m , kk , o[ N ][ N ];
char oc[ N ][ N ];
LL cnt[ 26 ][ N ][ N ];
int a[ K ] , b[ K ] , c[ K ] , d[ K ];
char e[ K ] , in[ N ];
LL cst[ N ][ N ];
void init(){
  scanf( "%d%d%d" , &n , &m , &kk );
  for( int i = 1 ; i <= n ; i ++ )
    scanf( "%s" , oc[ i ] + 1 );
  for( int i = 0 ; i < kk ; i ++ ){
    scanf( "%d%d%d%d%s" , &a[ i ] , &b[ i ] , &c[ i ] , &d[ i ] , in );
    e[ i ] = in[ 0 ];
  }
}
inline LL Cost( int ai , int bi , int ci , int di ){
  return cst[ ci ][ di ] - cst[ ai - 1 ][ di ]
                         - cst[ ci ][ bi - 1 ]
                         + cst[ ai - 1 ][ bi - 1 ];
}
inline LL Cnt( int ki , int ai , int bi , int ci , int di ){
  return cnt[ ki ][ ci ][ di ] - cnt[ ki ][ ai - 1 ][ di ]
                               - cnt[ ki ][ ci ][ bi - 1 ]
                               + cnt[ ki ][ ai - 1 ][ bi - 1 ];
}
void solve(){
  for( int i = 0 ; i < kk ; i ++ ){
    cnt[ e[ i ] - 'a' ][ a[ i ] ][ b[ i ] ] ++;
    cnt[ e[ i ] - 'a' ][ a[ i ] ][ d[ i ] + 1 ] --;
    cnt[ e[ i ] - 'a' ][ c[ i ] + 1 ][ b[ i ] ] --;
    cnt[ e[ i ] - 'a' ][ c[ i ] + 1 ][ d[ i ] + 1 ] ++;
    o[ a[ i ] ][ b[ i ] ] ++;
    o[ a[ i ] ][ d[ i ] + 1 ] --;
    o[ c[ i ] + 1 ][ b[ i ] ] --;
    o[ c[ i ] + 1 ][ d[ i ] + 1 ] ++;
  }
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 1 ; j <= m ; j ++ ){
      o[ i ][ j ] += o[ i - 1 ][ j ] + o[ i ][ j - 1 ] - o[ i - 1 ][ j - 1 ];
      cnt[ oc[ i ][ j ] - 'a' ][ i ][ j ] += kk - o[ i ][ j ];
      cnt[ oc[ i ][ j ] - 'a' ][ i ][ j + 1 ] -= kk - o[ i ][ j ];
      cnt[ oc[ i ][ j ] - 'a' ][ i + 1 ][ j ] -= kk - o[ i ][ j ];
      cnt[ oc[ i ][ j ] - 'a' ][ i + 1 ][ j + 1 ] += kk - o[ i ][ j ];
    }
  for( int k = 0 ; k < 26 ; k ++ )
    for( int i = 1 ; i <= n ; i ++ )
      for( int j = 1 ; j <= m ; j ++ )
        cnt[ k ][ i ][ j ] += cnt[ k ][ i - 1 ][ j ] + 
                              cnt[ k ][ i ][ j - 1 ] -
                              cnt[ k ][ i - 1 ][ j - 1 ];
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 1 ; j <= m ; j ++ ){
      for( int k = 0 ; k < 26 ; k ++ )
        cst[ i ][ j ] += abs( k - ( oc[ i ][ j ] - 'a' ) ) * cnt[ k ][ i ][ j ];
      cst[ i ][ j ] += cst[ i - 1 ][ j ] +
                       cst[ i ][ j - 1 ] -
                       cst[ i - 1 ][ j - 1 ];
    }
  for( int k = 0 ; k < 26 ; k ++ )
    for( int i = 1 ; i <= n ; i ++ )
      for( int j = 1 ; j <= m ; j ++ )
        cnt[ k ][ i ][ j ] += cnt[ k ][ i - 1 ][ j ] + 
                              cnt[ k ][ i ][ j - 1 ] -
                              cnt[ k ][ i - 1 ][ j - 1 ];
  LL ans = 1e18;
  for( int i = 0 ; i < kk ; i ++ ){
    LL tans = cst[ n ][ m ];
    tans -= Cost( a[ i ] , b[ i ] , c[ i ] , d[ i ] );
    //printf( "%d %lld\n" , i , tans );
    for( int j = 0 ; j < 26 ; j ++ )
      tans += abs( j - ( e[ i ] - 'a' ) ) *
        Cnt( j , a[ i ] , b[ i ] , c[ i ] , d[ i ] );
    //printf( "%d %lld\n" , i , tans );
    ans = min( ans , tans );
  }
  printf( "%lld\n" , ans );
}
int main(){
  init();
  solve();
}