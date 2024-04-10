#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define N 3003
int n , m , q;
vector<short> v[ N ];
void init(){
  scanf( "%d%d%d" , &n , &m , &q );
  while( m -- ){
    int ui , vi;
    scanf( "%d%d" , &ui , &vi );
    v[ ui ].push_back( vi );
  }
  for( int i = 1 ; i <= n ; i ++ )
    sort( v[ i ].begin() , v[ i ].end() );
}
#define K 12
short dst[ N ][ N ];
short pre[ N ][ K ][ N ];
bool vst[ N ][ N ] , in[ N ][ N ];
void noway( int root , int now ){
  vst[ root ][ now ] = true;
  for( auto i : v[ now ] )
    if( not vst[ root ][ i ] )
      noway( root , i );
}
void go( int root , int now , int dep ){
  dst[ root ][ now ] = dep;
  in[ root ][ now ] = true;
  short ppp = 0;
  for( auto i : v[ now ] ){
    assert( i > ppp );
    ppp = i;
    if( in[ root ][ i ] ){
      noway( root , i );
      break;
      int cur = now;
      while( cur != i ){
        noway( root , cur );
        cur = pre[ root ][ 0 ][ cur ];
      }
      noway( root , cur );
      break;
    }
    if( vst[ root ][ i ] )
      continue;
    pre[ root ][ 0 ][ i ] = now;
    go( root , i , dep + 1 );
  }
  vst[ root ][ now ] = true;
  in[ root ][ now ] = false;
}
int up( int root , int who , int dd ){
  for( int i = 0 ; i < K ; i ++ )
    if( (dd >> i) & 1 )
      who = pre[ root ][ i ][ who ];
  return who;
}
void solve(){
  for( int i = 1 ; i <= n ; i ++ )
    go( i , i , 1 );
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 1 ; j < K ; j ++ )
      for( int ii = 1 ; ii <= n ; ii ++ )
        pre[ i ][ j ][ ii ] = pre[ i ][ j - 1 ][ pre[ i ][ j - 1 ][ ii ] ];
  while( q -- ){
    int si , ti , ki;
    scanf( "%d%d%d" , &si , &ti , &ki );
    if( dst[ si ][ ti ] < ki )
      puts( "-1" );
    else
      printf( "%d\n" , up( si , ti , dst[ si ][ ti ] - ki ) );
  }
}
int main(){
  init();
  solve();
}