#include <bits/stdc++.h>
using namespace std;
#define N 3030
#define K 14
int n;
vector< int > v[ N ];
void init(){
  scanf( "%d" , &n );
  for( int i = 0 ; i < n ; i ++ ){
    int ai , bi;
    scanf( "%d%d" , &ai , &bi );
    v[ ai ].push_back( bi );
    v[ bi ].push_back( ai );
  }
}
bool oncyc[ N ] , instk[ N ];
int vst[ N ] , p[ N ][ K ] , dep[ N ] , stk[ N ];
int cycsz;
void go( int now , int prt , int tdep ){
  p[ now ][ 0 ] = prt;
  dep[ now ] = tdep;
  stk[ tdep ] = now;
  vst[ now ] = 1;
  instk[ now ] = true;
  for( int son : v[ now ] ){
    if( son == prt ) continue;
    if( vst[ son ] ){
      if( !instk[ son ] ) continue;
      cycsz = tdep - dep[ son ] + 1;
      for( int i = dep[ son ] ; i <= tdep ; i ++ )
        oncyc[ stk[ i ] ] = true;
    }else
      go( son , now , tdep + 1 );
  }
  instk[ now ] = false;
}
int cyc[ N ];
void go2( int now , int prt , int sum ){
  if( oncyc[ now ] ) sum ++;
  cyc[ now ] = sum;
  vst[ now ] = 2;
  for( int son : v[ now ] ){
    if( son == prt || vst[ son ] == 2 )
      continue;
    go2( son , now , sum );
  }
}
void build_pp(){
  for( int i = 1 ; i < K ; i ++ )
    for( int j = 0 ; j < n ; j ++ )
      p[ j ][ i ] = p[ p[ j ][ i - 1 ] ][ i - 1 ];
}
inline int lca( int ui , int vi ){
  if( dep[ ui ] > dep[ vi ] ) swap( ui , vi );
  int dlt = dep[ vi ] - dep[ ui ];
  for( int i = 0 ; i < K ; i ++ )
    if( ( dlt >> i ) & 1 )
      vi = p[ vi ][ i ];
  if( ui == vi ) return ui;
  for( int i = K - 1 ; i >= 0 ; i -- )
    if( p[ ui ][ i ] != p[ vi ][ i ] ){
      ui = p[ ui ][ i ];
      vi = p[ vi ][ i ];
    }
  return p[ ui ][ 0 ];
}
inline double cal( int a , int b ){
  if( a == b ) return 1.0;
  int tlca = lca( a , b );
  int bet = dep[ b ] + dep[ a ] - 2 * dep[ tlca ] + 1;
  int cnt = cyc[ b ] + cyc[ a ] - 2 * cyc[ tlca ] + oncyc[ tlca ];
  if( cnt <= 1 ) return 1.0 / (double)bet;
  bet -= cnt;
  int p1 = cnt , p2 = cycsz - cnt + 2;
  // printf( "%d<->%d bet: %d, p1: %d p2: %d cycsz: %d\n" , a , b , bet , p1 , p2 , cycsz );
  return 1.0 / (double)( bet + p1 ) +
         1.0 / (double)( bet + p2 ) -
         1.0 / (double)( bet + cycsz );
}
void solve(){
  go( 0 , 0 , 0 );
  go2( 0 , 0 , 0 );
  build_pp();
  double ans = 0.0;
  for( int i = 0 ; i < n ; i ++ )
    for( int j = 0 ; j < n ; j ++ )
      ans += cal( i , j );
  printf( "%.9f\n" , ans );
}
int main(){
  init();
  solve();
}