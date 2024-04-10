#include <bits/stdc++.h>
using namespace std;
#define N 151515
typedef long long LL;
vector<int> v[ N ];
bool vst[ N ];
int n , m , cc;
set< pair<int,int> > S;
void go( int now ){
  vst[ now ] = true;
  cc ++;
  for( int nxt : v[ now ] ){
    S.insert( { min( now , nxt ) , max( now , nxt ) } );
    if( not vst[ nxt ] )
      go( nxt );
  }
}
int main(){
  scanf( "%d%d" , &n , &m );
  while( m -- ){
    int ai , bi; scanf( "%d%d" , &ai , &bi );
    v[ ai ].push_back( bi );
    v[ bi ].push_back( ai );
  }
  for( int i = 1 ; i <= n ; i ++ ){
    if( vst[ i ] ) continue;
    S.clear(); cc = 0;
    go( i );
    if( (LL)cc * ( cc - 1 ) / 2 != (LL)S.size() ){
      puts( "NO" );
      exit( 0 );
    }
  }
  puts( "YES" );
}