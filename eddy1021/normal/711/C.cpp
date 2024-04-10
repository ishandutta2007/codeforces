// eddy1021
#include <bits/stdc++.h>
using namespace std;
#define N 111
typedef long long LL;
int n , m , k , c[ N ];
LL p[ N ][ N ];
void init(){
  scanf( "%d%d%d" , &n , &m , &k );
  for( int i = 1 ; i <= n ; i ++ )
    scanf( "%d" , &c[ i ] );
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 1 ; j <= m ; j ++ )
      scanf( "%lld" , &p[ i ][ j ] );
}
LL dp[ 2 ][ N ][ N ];
bool got[ 2 ][ N ][ N ];
void solve(){
  for( int i = 1 ; i <= m ; i ++ ){
    if( c[ 1 ] && i != c[ 1 ] ) continue;
    got[ 1 ][ i ][ 1 ] = true;
    dp[ 1 ][ i ][ 1 ] = c[ 1 ] ? 0 : p[ 1 ][ i ];
  }
  for( int i = 2 ; i <= n ; i ++ ){
    int now = i & 1 , pre = 1 - now;
    for( int j = 1 ; j <= m ; j ++ )
      for( int u = 1 ; u <= i ; u ++ )
        got[ now ][ j ][ u ] = false;
    for( int j = 1 ; j <= m ; j ++ ){
      if( c[ i ] && j != c[ i ] ) continue;
      for( int u = 1 ; u <= m ; u ++ ){
        if( c[ i - 1 ] && u != c[ i - 1 ] ) continue;
        for( int g = 1 ; g < i ; g ++ ){
          if( !got[ pre ][ u ][ g ] ) continue;
          LL tcst = dp[ pre ][ u ][ g ] + ( c[ i ] ? 0 : p[ i ][ j ] );
          int nxtg = g + ( j != u );
          if( !got[ now ][ j ][ nxtg ] ||
              tcst < dp[ now ][ j ][ nxtg ] ){
            got[ now ][ j ][ nxtg ] = true;
            dp[ now ][ j ][ nxtg ] = tcst;
          }
        }
      }
    }
  }
  LL ans = -1;
  for( int i = 1 ; i <= m ; i ++ )
    if( got[ n & 1 ][ i ][ k ] ){
      if( ans == -1 || dp[ n & 1 ][ i ][ k ] < ans )
        ans = dp[ n & 1 ][ i ][ k ];
    }
  printf( "%lld\n" , ans );
}
int main(){
  init();
  solve();
}