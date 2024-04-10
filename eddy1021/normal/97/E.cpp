#include <bits/stdc++.h>
using namespace std;
#define N 101010
#define K 20
struct DJS{
  int p[ N ];
  void init( int n ){
    for( int i = 0 ; i <= n ; i ++ )
      p[ i ] = i;
  }
  int find_p( int x ){
    return x == p[ x ] ? x : p[ x ] = find_p( p[ x ] );
  }
  void uni( int x , int y ){
    p[ find_p( x ) ] = find_p( y );
  }
} djs , cc;
int n , m;
vector< int > g[ N ] , s[ N ];
void init(){
  scanf( "%d%d" , &n , &m );
  djs.init( n ); cc.init( n );
  while( m -- ){
    int ui , vi; scanf( "%d%d" , &ui , &vi );
    g[ ui ].push_back( vi );
    g[ vi ].push_back( ui );
    cc.uni( ui , vi );
  }
}
bool got[ N ] , got2[ N ];
int p[ K ][ N ] , dep[ N ];
inline int lca( int ui , int vi ){
  if( dep[ ui ] > dep[ vi ] ) swap( ui , vi );
  int dlt = dep[ vi ] - dep[ ui ];
  for( int i = 0 ; i < K ; i ++ )
    if( ( dlt >> i ) & 1 )
      vi = p[ i ][ vi ];
  if( ui == vi ) return ui;
  for( int i = K - 1 ; i >= 0 ; i -- )
    if( p[ i ][ ui ] != p[ i ][ vi ] ){
      ui = p[ i ][ ui ];
      vi = p[ i ][ vi ];
    }
  return p[ 0 ][ ui ];
}
vector< pair<int,int> > e;
void go( int now , int prt , int dp ){
  got[ now ] = true;
  dep[ now ] = dp;
  p[ 0 ][ now ] = prt;
  for( int son : g[ now ] ){
    if( son == prt ) continue;
    if( got[ son ] ) e.push_back( { now , son } );
    else{
      s[ now ].push_back( son );
      go( son , now , dp + 1 );
    }
  }
}
bool od[ N ];
int sum[ N ];
void go2( int now ){
  got2[ now ] = true;
  if( od[ djs.find_p( now ) ] && now != djs.find_p( now ) )
    sum[ now ] ++;
  for( int son : s[ now ] ){
    sum[ son ] = sum[ now ];
    go2( son );
  }
}
void solve(){
  for( int i = 1 ; i <= n ; i ++ )
    if( !got[ i ] )
      go( i , i , 0 );
  for( int i = 1 ; i < K ; i ++ )
    for( int j = 1 ; j <= n ; j ++ )
      p[ i ][ j ] = p[ i - 1 ][ p[ i - 1 ][ j ] ];
  for( pair<int,int> tp : e ){
    int ui = tp.first , vi = tp.second;
    int lc = lca( ui , vi );
    if( ( dep[ vi ] - dep[ ui ] ) % 2 == 0 ) od[ lc ] = true;
    ui = djs.find_p( ui );
    vi = djs.find_p( vi );
    while( ui != vi ){
      if( dep[ ui ] > dep[ vi ] ) swap( ui , vi );
      djs.uni( vi , p[ 0 ][ vi ] );
      vi = djs.find_p( vi );
    }
  }
  for( int i = 1 ; i <= n ; i ++ )
    if( od[ i ] && i != djs.find_p( i ) ){
      od[ djs.find_p( i ) ] = true;
      od[ i ] = false;
    }
  for( int i = 1 ; i <= n ; i ++ )
    if( !got2[ i ] )
      go2( i );
  int q; scanf( "%d" , &q ); while( q -- ){
    int ui , vi; scanf( "%d%d" , &ui , &vi );
    int lc = lca( ui , vi );
    bool pos = false;
    if( sum[ ui ] != sum[ lc ] ||
        sum[ vi ] != sum[ lc ] ||
        ( dep[ ui ] + dep[ vi ] ) % 2 ) pos = true;
    if( cc.find_p( ui ) != cc.find_p( vi ) ||
        ui == vi ) pos = false;
    puts( pos ? "Yes" : "No" );
  }
}
int main(){
  init();
  solve();
}