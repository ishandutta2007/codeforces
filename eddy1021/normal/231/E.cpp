#include <bits/stdc++.h>
using namespace std;
#define N 101010
const int mod = 1000000007;
int two[ N ];
void build(){
  two[ 0 ] = 1;
  for( int i = 1 ; i < N ; i ++ )
    two[ i ] = ( two[ i - 1 ] << 1 ) % mod;
}
int n , m , a[ N ] , b[ N ] , p[ N ] , sz[ N ];
int find_p( int x ){
  return x == p[ x ] ? x : p[ x ] = find_p( p[ x ] );
}
void Union( int x , int y ){
  x = find_p( x );
  y = find_p( y );
  if( x == y ) return;
  p[ x ] = y;
  sz[ y ] += sz[ x ];
}
vector< int > cat[ N ] , t[ N ];
void init(){
  scanf( "%d%d" , &n , &m );
  for( int i = 0 ; i < m ; i ++ ){
    scanf( "%d%d" , &a[ i ] , &b[ i ] );
    cat[ a[ i ] ].push_back( b[ i ] );
    cat[ b[ i ] ].push_back( a[ i ] );
  }
}
int stk[ N ];
bool vst[ N ] , ins[ N ];
void go( int now , int tdep , int prt ){
  vst[ now ] = true;
  ins[ now ] = true;
  stk[ tdep ] = now;
  for( int son : cat[ now ] ){
    if( son == prt ) continue;
    if( vst[ son ] ){
      if( !ins[ son ] ) continue;
      for( int i = tdep ; stk[ i ] != son ; i -- )
        Union( son , stk[ i ] );
    }else
      go( son , tdep + 1 , now );
  }
  ins[ now ] = false;
}
#define K 20
int pp[ N ][ K ] , sum[ N ] , dep[ N ];
inline int lca( int ui , int vi ){
  if( dep[ ui ] > dep[ vi ] ) swap( ui , vi );
  int dlt = dep[ vi ] - dep[ ui ];
  for( int i = 0 ; i < K ; i ++ )
    if( ( dlt >> i ) & 1 )
      vi = pp[ vi ][ i ];
  if( ui == vi ) return ui;
  for( int i = K - 1 ; i >= 0 ; i -- )
    if( pp[ ui ][ i ] != pp[ vi ][ i ] ){
      ui = pp[ ui ][ i ];
      vi = pp[ vi ][ i ];
    }
  return pp[ ui ][ 0 ];
}
void go2( int now , int prt , int tdep , int tsum ){
  if( sz[ now ] > 1 ) tsum ++;
  sum[ now ] = tsum;
  pp[ now ][ 0 ] = prt;
  dep[ now ] = tdep;
  for( int son : t[ now ] ){
    if( son == prt ) continue;
    go2( son , now , tdep + 1 , tsum );
  }
}
void presolve(){
  for( int i = 1 ; i <= n ; i ++ )
    p[ i ] = i , sz[ i ] = 1;
  go( 1 , 1 , 1 );
  int st = -1;
  for( int i = 1 ; i <= n ; i ++ )
    if( i == find_p( i ) ){
      st = i; break;
    }
  for( int i = 0 ; i < m ; i ++ ){
    if( find_p( a[ i ] ) == find_p( b[ i ] ) )
      continue;
    t[ find_p( a[ i ] ) ].push_back( find_p( b[ i ] ) );
    t[ find_p( b[ i ] ) ].push_back( find_p( a[ i ] ) );
  }
  go2( st , st , 0 , 0 );
  for( int i = 1 ; i < K ; i ++ )
    for( int j = 1 ; j <= n ; j ++ )
      pp[ j ][ i ] = pp[ pp[ j ][ i - 1 ] ][ i - 1 ];
}
void solve(){
  int q; scanf( "%d" , &q ); while( q -- ){
    int qa, qb; scanf( "%d%d" , &qa , &qb );
    qa = find_p( qa );
    qb = find_p( qb );
    int nlca = lca( qa , qb );
    int num = sum[ qa ] + sum[ qb ] - 2 * sum[ nlca ];
    if( sz[ nlca ] > 1 ) num ++;
    printf( "%d\n" , two[ num ] );
  }
}
int main(){
  build();
  init();
  presolve();
  solve();
}