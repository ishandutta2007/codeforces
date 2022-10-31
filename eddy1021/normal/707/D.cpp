#include <bits/stdc++.h>
using namespace std;
#define N 1024
#define K 101010
bitset<N> b[ N ] , msk;
int n , m , q , cnt;
int cmd[ K ] , op1[ K ] , op2[ K ] , ans[ K ];
vector<int> nxt[ K ];
void init(){
  scanf( "%d%d%d" , &n , &m , &q );
  for( int i = 1 ; i <= m ; i ++ )
    msk[ i ] = true;
  for( int i = 1 ; i <= q ; i ++ ){
    scanf( "%d%d" , &cmd[ i ] , &op1[ i ] );
    if( cmd[ i ] <= 2 ) scanf( "%d" , &op2[ i ] );
    if( cmd[ i ] == 4 ) nxt[ op1[ i ] ].push_back( i );
    else nxt[ i - 1 ].push_back( i );
  }
}
void go( int now ){
  bool sv = false;
  int dlt = 0;
  if( cmd[ now ] <= 2 ){
    sv = b[ op1[ now ] ][ op2[ now ] ];
    b[ op1[ now ] ][ op2[ now ] ] = ( cmd[ now ] == 1 ? true : false );
    if( sv ^ b[ op1[ now ] ][ op2[ now ] ] ){
      dlt = ( sv ? -1 : +1 );
      cnt += dlt;
    }
  }
  if( cmd[ now ] == 3 ){
    cnt -= b[ op1[ now ] ].count();
    b[ op1[ now ] ] = ( ~b[ op1[ now ] ] ) & msk;
    cnt += b[ op1[ now ] ].count();
  }
  ans[ now ] = cnt;
  for( int son : nxt[ now ] )
    go( son );
  if( cmd[ now ] <= 2 ){
    b[ op1[ now ] ][ op2[ now ] ] = sv;
    cnt -= dlt;
  }
  if( cmd[ now ] == 3 ){
    cnt -= b[ op1[ now ] ].count();
    b[ op1[ now ] ] = ( ~b[ op1[ now ] ] ) & msk;
    cnt += b[ op1[ now ] ].count();
  }
}
void solve(){
  go( 0 );
  for( int i = 1 ; i <= q ; i ++ )
    printf( "%d\n" , ans[ i ] );
}
int main(){
  init();
  solve();
}