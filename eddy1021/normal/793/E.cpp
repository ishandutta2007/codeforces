#include <bits/stdc++.h>
using namespace std;
#define N 5140
int n , a[ 4 ] , leaf;
vector<int> son[ N ];
void no(){
  puts( "NO" );
  exit(0);
}
void init(){
  scanf( "%d" , &n );
  for( int i = 0 ; i < 4 ; i ++ )
    scanf( "%d" , &a[ i ] );
  for( int i = 2 ; i <= n ; i ++ ){
    int pi; scanf( "%d" , &pi );
    son[ pi ].push_back( i );
  }
  for( int i = 1 ; i <= n ; i ++ )
    if( son[ i ].empty() )
      leaf ++;
  if( leaf & 1 ) no();
}
int sz[ N ];
vector<int> items;
int go( int now ){
  int who = -1;
  if( son[ now ].empty() ){
    sz[ now ] = 1;
    for( int i = 0 ; i < 4 ; i ++ )
      if( now == a[ i ] )
        who = i;
    return who;
  }
  vector<int> wt;
  for( int s : son[ now ] ){
    int ret = go( s );
    if( ret == -1 ) wt.push_back( sz[ s ] );
    else{
      who = ret;
      if( who > 1 ) wt.push_back( sz[ s ] );
    }
  }
  if( who == -1 or who > 1 ){
    sz[ now ] = 0;
    for( auto i : wt ) sz[ now ] += i;
  }else{
    for( auto i : wt ) items.push_back( i );
  }
  return who;
}
bool dp[ N ];
void knapsack( int tar ){
  if( tar < 0 or tar >= N ) no();
  for( int i = 0 ; i <= tar ; i ++ )
    dp[ i ] = false;
  dp[ 0 ] = true;
  for( auto i : items )
    for( int j = tar - i ; j >= 0 ; j -- )
      dp[ j + i ] |= dp[ j ];
  if( not dp[ tar ] ) no();
}
void solve(){
  for( int _ = 0 ; _ < 2 ; _ ++ ){
    items.clear();
    int cand = ( leaf - 2 ) >> 1;
    for( int s : son[ 1 ] ){
      int ret = go( s );
      if( ret == -1 ) items.push_back( sz[ s ] );
      else if( ret == 2 ) cand -= sz[ s ];
    }
    knapsack( cand );
    swap( a[ 0 ] , a[ 2 ] );
    swap( a[ 1 ] , a[ 3 ] );
  }
  puts( "YES" );
}
int main(){
  init();
  solve();
}