#include <bits/stdc++.h>
using namespace std;
#define N 101010
typedef long long LL;
int n , m , clr[ N ];
vector< int > v[ N ];
void init(){
  scanf( "%d%d" , &n , &m );
  for( int i = 0 ; i < m ; i ++ ){
    int ai , bi; scanf( "%d%d" , &ai , &bi );
    v[ ai ].push_back( bi );
    v[ bi ].push_back( ai );
  }
}
int cnt[ 3 ];
void go( int now , int tclr ){
  clr[ now ] = tclr;
  for( int x : v[ now ] ){
    if( clr[ x ] && clr[ x ] == tclr ){
      puts( "0 1" );
      exit( 0 );
    }
    if( clr[ x ] ) continue;
    go( x , 3 - tclr );
  }
  cnt[ clr[ now ] ] ++;
}
inline LL C( LL a , LL b ){
  LL ret = 1;
  for( LL i = a , j = 0 ; j < b ; i -- , j ++ )
    ret *= i;
  for( LL j = b ; j ; j -- )
    ret /= j;
  return ret;
}
void solve(){
  if( m == 0 ){
    printf( "3 %lld\n" , C( n , 3 ) );
    exit( 0 );
  }
  LL ans = 0;
  bool ok = false;
  for( int i = 0 ; i < n ; i ++ ){
    if( clr[ i ] ) continue;
    cnt[ 1 ] = cnt[ 2 ] = 0;
    go( i , 1 );
    if( cnt[ 1 ] + cnt[ 2 ] > 2 ){
      ok = true;
      ans += C( cnt[ 1 ] , 2 ) + C( cnt[ 2 ] , 2 );
    }
  }
  if( ok )
    printf( "1 %lld\n" , ans );
  else
    printf( "2 %lld\n" , (LL)m * ( n - 2 ) );
}
int main(){
  init();
  solve();
}