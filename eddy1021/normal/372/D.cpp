// eddy1021
#include <bits/stdc++.h>
using namespace std;
#define N 101010
#define K 20
int n , k;
vector< int > v[ N ];
void init(){
  scanf( "%d%d" , &n , &k );
  for( int i = 1 ; i < n ; i ++ ){
    int ai , bi;
    scanf( "%d%d" , &ai , &bi );
    v[ ai ].push_back( bi );
    v[ bi ].push_back( ai );
  }
}
int p[ N ][ K ] , dep[ N ] , in[ N ] , stp;
void go( int now , int prt , int tdep ){
  in[ now ] = ++ stp;
  dep[ now ] = tdep;
  p[ now ][ 0 ] = prt;
  for( int son : v[ now ] ){
    if( son == prt ) continue;
    go( son , now , tdep + 1 );
  }
}
inline int lca( int ai , int bi ){
  if( dep[ ai ] > dep[ bi ] ) swap( ai , bi );
  int dlt = dep[ bi ] - dep[ ai ];
  for( int i = 0 ; i < K ; i ++ )
    if( ( dlt >> i ) & 1 )
      bi = p[ bi ][ i ];
  if( ai == bi ) return ai;
  for( int i = K - 1 ; i >= 0 ; i -- )
    if( p[ ai ][ i ] != p[ bi ][ i ] ){
      ai = p[ ai ][ i ];
      bi = p[ bi ][ i ];
    }
  return p[ ai ][ 0 ];
}
inline int dist( int ai , int bi ){
  return dep[ ai ] + dep[ bi ] - 2 * dep[ lca( ai , bi ) ];
}
set< pair<int,int> > S;
inline int Cost( const pair<int,int> tp , int id ){
  auto it = S.lower_bound( tp );
  int lc = id , rc = id;
  if( it == S.begin() || it == S.end() ){
    lc = (*--S.end()).second;
    rc = S.begin()->second;
  }else{
    rc = it->second; it --;
    lc = it->second;
  }
  return ( dist( id , lc ) + dist( id , rc ) - dist( lc , rc ) ) / 2;
}
void solve(){
  go( 1 , 1 , 0 );
  for( int i = 1 ; i < K ; i ++ )
    for( int j = 1 ; j <= n ; j ++ )
      p[ j ][ i ] = p[ p[ j ][ i - 1 ] ][ i - 1 ];
  int ans = 1;
  S.insert( { in[ 1 ] , 1 } );
  int cur_sz = 1 , ptr = 1;
  for( int i = 2 ; i <= n ; i ++ ){
    cur_sz += Cost( { in[ i ] , i } , i );
    S.insert( { in[ i ] , i } );
    while( cur_sz > k ){
      auto it = S.find( { in[ ptr ] , ptr } );
      S.erase( it );
      cur_sz -= Cost( { in[ ptr ] , ptr } , ptr );
      ptr ++;
    }
    ans = max( ans , i - ptr + 1 );
    //printf( "%d %d %d\n" , ptr , i , cur_sz );
  }
  printf( "%d\n" , ans );
}
int main(){
  init();
  solve();
}