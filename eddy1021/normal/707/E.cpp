#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 2048
int n , m , k , len[ N ] , px[ N ][ N ] , py[ N ][ N ];
LL sum[ N ][ N ];
pair<int,int> who[ N ][ N ];
bool on[ N ];
void init(){
  scanf( "%d%d%d" , &n , &m , &k );
  for( int i = 0 ; i < k ; i ++ ){
    scanf( "%d" , &len[ i ] );
    on[ i ] = true;
    for( int j = 1 ; j <= len[ i ] ; j ++ ){
      scanf( "%d%d" , &px[ i ][ j ] , &py[ i ][ j ] );
      scanf( "%lld" , &sum[ i ][ j ] );
      sum[ i ][ j ] += sum[ i ][ j - 1 ];
      who[ px[ i ][ j ] ][ py[ i ][ j ] ] = { i + 1 , j };
    }
  }
}
vector< pair<int,int> > vv[ N ];
bool in( int x1 , int x2 , int x3 ){
  return x1 <= x2 && x2 <= x3;
}
void go(){
  int x[ 2 ] , y[ 2 ];
  scanf( "%d%d%d%d" , &x[ 0 ] , &y[ 0 ] , &x[ 1 ] , &y[ 1 ] );
  for( int i = 0 ; i < k ; i ++ ) vv[ i ].clear();
  for( int i = 0 ; i < k ; i ++ ){
    if( in( x[ 0 ] , px[ i ][ 1 ] , x[ 1 ] ) &&
        in( y[ 0 ] , py[ i ][ 1 ] , y[ 1 ] ) ){
      vv[ i ].push_back( { 1 , -1 } );
      if( len[ i ] > 1 ){
        if( !in( x[ 0 ] , px[ i ][ 2 ] , x[ 1 ] ) ||
            !in( y[ 0 ] , py[ i ][ 2 ] , y[ 1 ] ) )
          vv[ i ].push_back( { 1 , +1 } );
      }
    }
    if( in( x[ 0 ] , px[ i ][ len[ i ] ] , x[ 1 ] ) &&
        in( y[ 0 ] , py[ i ][ len[ i ] ] , y[ 1 ] ) ){
      vv[ i ].push_back( { len[ i ] , +1 } );
      if( len[ i ] > 1 ){
        if( !in( x[ 0 ] , px[ i ][ len[ i ] - 1 ] , x[ 1 ] ) ||
            !in( y[ 0 ] , py[ i ][ len[ i ] - 1 ] , y[ 1 ] ) )
          vv[ i ].push_back( { len[ i ] , -1 } );
      }
    }
  }
  for( int i = y[ 0 ] ; i <= y[ 1 ] ; i ++ ){
    if( who[ x[ 0 ] ][ i ].first > 0 ){
      int id = who[ x[ 0 ] ][ i ].first - 1;
      int jd = who[ x[ 0 ] ][ i ].second;
      if( jd > 1 &&
          ( !in( x[ 0 ] , px[ id ][ jd - 1 ] , x[ 1 ] ) ||
            !in( y[ 0 ] , py[ id ][ jd - 1 ] , y[ 1 ] ) ) )
        vv[ id ].push_back( { jd , -1 } );
      if( jd < len[ id ] &&
          ( !in( x[ 0 ] , px[ id ][ jd + 1 ] , x[ 1 ] ) ||
            !in( y[ 0 ] , py[ id ][ jd + 1 ] , y[ 1 ] ) ) )
        vv[ id ].push_back( { jd , +1 } );
    }
    if( who[ x[ 1 ] ][ i ].first > 0 ){
      int id = who[ x[ 1 ] ][ i ].first - 1;
      int jd = who[ x[ 1 ] ][ i ].second;
      if( jd > 1 &&
          ( !in( x[ 0 ] , px[ id ][ jd - 1 ] , x[ 1 ] ) ||
            !in( y[ 0 ] , py[ id ][ jd - 1 ] , y[ 1 ] ) ) )
        vv[ id ].push_back( { jd , -1 } );
      if( jd < len[ id ] &&
          ( !in( x[ 0 ] , px[ id ][ jd + 1 ] , x[ 1 ] ) ||
            !in( y[ 0 ] , py[ id ][ jd + 1 ] , y[ 1 ] ) ) )
        vv[ id ].push_back( { jd , +1 } );
    }
  }
  for( int i = x[ 0 ] ; i <= x[ 1 ] ; i ++ ){
    if( who[ i ][ y[ 0 ] ].first > 0 ){
      int id = who[ i ][ y[ 0 ] ].first - 1;
      int jd = who[ i ][ y[ 0 ] ].second;
      if( jd > 1 &&
          ( !in( x[ 0 ] , px[ id ][ jd - 1 ] , x[ 1 ] ) ||
            !in( y[ 0 ] , py[ id ][ jd - 1 ] , y[ 1 ] ) ) )
        vv[ id ].push_back( { jd , -1 } );
      if( jd < len[ id ] &&
          ( !in( x[ 0 ] , px[ id ][ jd + 1 ] , x[ 1 ] ) ||
            !in( y[ 0 ] , py[ id ][ jd + 1 ] , y[ 1 ] ) ) )
        vv[ id ].push_back( { jd , +1 } );
    }
    if( who[ i ][ y[ 1 ] ].first > 0 ){
      int id = who[ i ][ y[ 1 ] ].first - 1;
      int jd = who[ i ][ y[ 1 ] ].second;
      if( jd > 1 &&
          ( !in( x[ 0 ] , px[ id ][ jd - 1 ] , x[ 1 ] ) ||
            !in( y[ 0 ] , py[ id ][ jd - 1 ] , y[ 1 ] ) ) )
        vv[ id ].push_back( { jd , -1 } );
      if( jd < len[ id ] &&
          ( !in( x[ 0 ] , px[ id ][ jd + 1 ] , x[ 1 ] ) ||
            !in( y[ 0 ] , py[ id ][ jd + 1 ] , y[ 1 ] ) ) )
        vv[ id ].push_back( { jd , +1 } );
    }
  }
  LL ans = 0;
  for( int i = 0 ; i < k ; i ++ ){
    if( !on[ i ] ) continue;
    sort( vv[ i ].begin() , vv[ i ].end() );
    vv[ i ].resize( unique( vv[ i ].begin() , vv[ i ].end() ) - vv[ i ].begin() );
    assert( (int)vv[ i ].size() % 2 == 0 );
    for( size_t j = 0 ; j < vv[ i ].size() ; j += 2 )
      ans += sum[ i ][ vv[ i ][ j + 1 ].first ] - sum[ i ][ vv[ i ][ j ].first - 1 ];
  }
  printf( "%lld\n" , ans );
}
void solve(){
  int q; scanf( "%d" , &q );
  while( q -- ){
    char cmd[ 9 ];
    scanf( "%s" , cmd );
    if( cmd[ 0 ] == 'S' ){
      int id; scanf( "%d" , &id );
      on[ id - 1 ] = !on[ id - 1 ];
    }else go();
  }
}
int main(){
  init();
  solve();
}