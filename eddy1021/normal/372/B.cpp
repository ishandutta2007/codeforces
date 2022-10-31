// eddy1021
#include <bits/stdc++.h>
using namespace std;
#define N 52
#define Q 303030
int n , m , q , r[ Q ] , c[ Q ] , ans[ Q ];
int ss[ N ][ N ];
char ic[ N ][ N ];
vector< int > qry[ N ][ N ];
void init(){
  scanf( "%d%d%d" , &n , &m , &q );
  for( int i = 1 ; i <= n ; i ++ )
    scanf( "%s" , ic[ i ] + 1 );
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 1 ; j <= m ; j ++ )
      ss[ i ][ j ] = ss[ i - 1 ][ j ] + ss[ i ][ j - 1 ] -
                     ss[ i - 1 ][ j - 1 ] + ( ic[ i ][ j ] - '0' );
  for( int i = 0 ; i < q ; i ++ ){
    int qr , qc;
    scanf( "%d%d%d%d" , &r[ i ] , &c[ i ] , &qr , &qc );
    qry[ qr ][ qc ].push_back( i );
  }
}
inline bool okay( int i , int j , int ii , int jj ){
  if( i > ii || j > jj ) return false;
  return ss[ ii ][ jj ] - ss[ i - 1 ][ jj ]
                        - ss[ ii ][ j - 1 ] + ss[ i - 1 ][ j - 1 ] == 0;
}
int cnt[ N ][ N ][ N ][ N ];
void solve(){
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 1 ; j <= m ; j ++ ){
      for( int ii = 1 ; ii <= n ; ii ++ )
        for( int jj = 1 ; jj <= m ; jj ++ ){
          cnt[ i ][ j ][ ii ][ jj ] = cnt[ i ][ j ][ ii - 1 ][ jj ] +
                                      cnt[ i ][ j ][ ii ][ jj - 1 ] -
                                      cnt[ i ][ j ][ ii - 1 ][ jj - 1 ];
          if( okay( ii , jj , i , j ) )
            cnt[ i ][ j ][ ii ][ jj ] ++;
        }
      for( int ii = 1 ; ii <= n ; ii ++ )
        for( int jj = 1 ; jj <= m ; jj ++ )
          cnt[ i ][ j ][ ii ][ jj ] += cnt[ i - 1 ][ j ][ ii ][ jj ] +
                                       cnt[ i ][ j - 1 ][ ii ][ jj ] -
                                       cnt[ i - 1 ][ j - 1 ][ ii ][ jj ];
      for( int id : qry[ i ][ j ] ){
        int ii = r[ id ] , jj = c[ id ];
        ans[ id ] = cnt[ i ][ j ][ i ][ j ] -
                    cnt[ i ][ j ][ ii - 1 ][ j ] -
                    cnt[ i ][ j ][ i ][ jj - 1 ] +
                    cnt[ i ][ j ][ ii - 1 ][ jj - 1 ];
      }
    }
  for( int i = 0 ; i < q ; i ++ )
    printf( "%d\n" , ans[ i ] );
}
int main(){
  init();
  solve();
}