#include <bits/stdc++.h>
using namespace std;
#define N 101010
typedef long long LL;
LL n , m , p , d[ N ] , t[ N ] , st[ N ];
void init(){
  scanf( "%lld%lld%lld" , &n , &m , &p );
  for( LL i = 2 ; i <= n ; i ++ ){
    scanf( "%lld" , &d[ i ] );
    d[ i ] += d[ i - 1 ];
  }
  for( int i = 1 ; i <= m ; i ++ ){
    LL hi , ti; scanf( "%lld%lld" , &hi , &ti );
    t[ i ] = ti - d[ hi ];
  }
  sort( t + 1 , t + m + 1 );
  for( int i = 1 ; i <= m ; i ++ )
    st[ i ] = st[ i - 1 ] + t[ i ];
}
LL dp[ 2 ][ N ];
deque< pair<LL,LL> > stk;
inline void fix( LL x ){
  while( (int)stk.size() > 1 ){
    if( ( stk[ 1 ].second - stk[ 0 ].second ) <=
        ( stk[ 0 ].first - stk[ 1 ].first ) * x )
      stk.pop_front();
    else break;
  }
}
inline void add( const pair<LL,LL>& tp ){
  while( (int)stk.size() > 1 ){
    size_t _sz = stk.size();
    if( ( tp.second - stk[ _sz - 2 ].second ) *
        ( stk[ _sz - 2 ].first - stk[ _sz - 1 ].first ) <=
        ( stk[ _sz - 1 ].second - stk[ _sz - 2 ].second ) *
        ( stk[ _sz - 2 ].first - tp.first ) )
      stk.pop_back();
    else break;
  }
  stk.push_back( tp );
}
void solve(){
  for( int i = 1 ; i <= m ; i ++ )
    dp[ 1 ][ i ] = (LL)i * t[ i ] - st[ i ];
  p = min( p , m );
  for( int i = 2 ; i <= p ; i ++ ){
    int now = i & 1 , pre = 1 - now;
    stk.clear();
    stk.push_back( { 0 , 0 } );
    for( int j = 1 ; j <= m ; j ++ ){
      fix( t[ j ] );
      dp[ now ][ j ] = stk[ 0 ].first * t[ j ] + stk[ 0 ].second +
                       t[ j ] * j - st[ j ];
      add( { -j , dp[ pre ][ j ] + st[ j ] } );
    }
  }
  printf( "%lld\n" , dp[ p & 1 ][ m ] );
}
int main(){
  init();
  solve();
}