#include <bits/stdc++.h>
using namespace std;
#define K 30
struct F{
  int v[ K ];
  F(){
    for( int i = 0 ; i < K ; i ++ )
      v[ i ] = 0;
  }
  int add( int vl ){
    //cout << "adding " << vl << endl;
    for( int i = K - 1 ; i >= 0 and vl ; i -- ){
      if( ( ( vl >> i ) & 1 ) == 0 )
        continue;
      if( v[ i ] )
        vl ^= v[ i ];
      else{
        v[ i ] = vl;
        return i;
      }
    }
    return -1;
  }
  int best(){
    int ret = 0;
    for( int i = K - 1 ; i >= 0 ; i -- )
      if( ( ret ^ v[ i ] ) > ret )
        ret ^= v[ i ];
    return ret;
  }
};
inline int getint(){
  int x = 0; char c = getchar();
  while( c < '0' or c > '9' ) c = getchar();
  while( c >= '0' and c <= '9' )
    x = x * 10 + c - '0' , c = getchar();
  return x;
}
#define N 101010
F d;
int n , m;
vector< pair<pair<int,int>,int> > g[ N ];
int ecnt;
void init(){
  n = getint();
  m = getint();
  while( m -- ){
    int ui = getint();
    int vi = getint();
    int xi = getint();
    ++ ecnt;
    g[ ui ].push_back( { { vi , xi } , ecnt } );
    g[ vi ].push_back( { { ui , xi } , ecnt } );
  }
}
bool vst[ N ];
int ppp[ N ];
void go( int now , int pre , int pp ){
  vst[ now ] = true;
  ppp[ now ] = pre;
  //printf( "%d %d %d\n" , now , pre , pp );
  for( auto ii : g[ now ] ){
    if( ii.second == pp ) continue;
    pair<int,int> i = ii.first;
    if( vst[ i.first ] ){
      //printf( "%d->%d\n" , now , i.first );
      d.add( pre ^ i.second ^ ppp[ i.first ] );
      continue;
    }
    go( i.first , pre ^ i.second , ii.second );
  }
}
int dst[ N ];
bool gg[ N ];
void solve(){
  go( 1 , 0 , -1 );
  gg[ 1 ] = true;
  dst[ 1 ] = 0;
  queue<int> Q; Q.push( 1 );
  while( Q.size() ){
    int tn = Q.front(); Q.pop();
    for( auto ii : g[ tn ] ){
      pair<int,int> i = ii.first;
      if( gg[ i.first ] ) continue;
      gg[ i.first ] = true;
      dst[ i.first ] = dst[ tn ] ^ i.second;
      Q.push( i.first );
    }
  }
  int ans = dst[ n ];
  for( int i = K - 1 ; i >= 0 ; i -- )
    if( ( ans ^ d.v[ i ] ) < ans )
      ans ^= d.v[ i ];
  printf( "%d\n" , ans );
}
int main(){
  init();
  solve();
}