#include <bits/stdc++.h>
using namespace std;
#define N 101010
typedef long long LL;
LL n , d[ N ] , p[ N ];
vector< pair<LL,LL> > v[ N ];
const LL inf = 100000000000000000LL;
void DP( int now ){
  for( auto e : v[ now ] ){
    LL son = e.first;
    LL ki = e.second;
    DP( son );
    if( d[ son ] >= 0 )
      d[ now ] += d[ son ];
    else{
      LL nd = -d[ son ];
      if( nd >= inf / ki ){
        puts( "NO" );
        exit(0);
      }
      d[ now ] -= nd * ki;
      if( d[ now ] < -inf ){
        puts( "NO" );
        exit(0);
      }
    }
  }
}
int main(){
  scanf( "%lld" , &n );
  for( LL i = 1 , x ; i <= n ; i ++ ){
    scanf( "%lld" , &x );
    d[ i ] += x;
  }
  for( LL i = 1 , x ; i <= n ; i ++ ){
    scanf( "%lld" , &x );
    d[ i ] -= x;
  }
  for( LL i = 2 , x ; i <= n ; i ++ ){
    scanf( "%lld%lld" , &p[ i ] , &x );
    v[ p[ i ] ].push_back( { i , x } );
  }
  DP( 1 );
  puts( d[ 1 ] >= 0 ? "YES" : "NO" );
}