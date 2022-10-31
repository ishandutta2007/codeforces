#include <bits/stdc++.h>
using namespace std;
#define N 505050
int n;
vector< pair<int,int> > v[ N ];
void init(){
  scanf( "%d" , &n );
  for( int i = 2 ; i <= n ; i ++ ){
    int pi; char c[ 9 ];
    scanf( "%d%s" , &pi , c );
    v[ pi ].push_back( { i , c[ 0 ] - 'a' } );
  }
}
int sz[ N ] , msk[ N ] , mxc[ N ] , dep[ N ];
int tl[ N ] , tr[ N ] , who[ N ] , stmp;
void go( int now , int tmsk , int ndep ){
  sz[ now ] = 1;
  msk[ now ] = tmsk;
  dep[ now ] = ndep;
  tl[ now ] = ++ stmp;
  who[ stmp ] = now;
  for( auto i : v[ now ] ){
    go( i.first , tmsk ^ ( 1 << i.second ) , ndep + 1 );
    sz[ now ] += sz[ i.first ];
    if( sz[ i.first ] > sz[ mxc[ now ] ] )
      mxc[ now ] = i.first;
  }
  tr[ now ] = stmp;
}
int mxdep[ 1 << 22 ] , ans[ N ];
inline void upd( int now , int he ){
  ans[ now ] = max( ans[ now ] ,
                    dep[ he ] + mxdep[ msk[ he ] ] -
                      dep[ now ] - dep[ now ] );
  for( int i = 0 ; i < 22 ; i ++ )
    ans[ now ] = max( ans[ now ] ,
                      dep[ he ] + mxdep[ msk[ he ] ^ ( 1 << i ) ] -
                        dep[ now ] - dep[ now ] );
}
inline void add( int he ){
  mxdep[ msk[ he ] ] = max( mxdep[ msk[ he ] ] ,
                            dep[ he ] );
}
void go( int now , bool keep ){
  for( auto i : v[ now ] ){
    if( i.first == mxc[ now ] )
      continue;
    go( i.first , 0 );
    ans[ now ] = max( ans[ now ] , ans[ i.first ] );
  }
  if( mxc[ now ] ){
    go( mxc[ now ] , 1 );
    ans[ now ] = max( ans[ now ] , ans[ mxc[ now ] ] );
  }
  for( auto i : v[ now ] ){
    if( i.first == mxc[ now ] )
      continue;
    for( int j = tl[ i.first ] ; j <= tr[ i.first ] ; j ++ )
      upd( now , who[ j ] );
    for( int j = tl[ i.first ] ; j <= tr[ i.first ] ; j ++ )
      add( who[ j ] );
  }
  upd( now , now );
  add( now );
  if( !keep ){
    for( int j = tl[ now ] ; j <= tr[ now ] ; j ++ )
      mxdep[ msk[ who[ j ] ] ] = - N - N;
  }
}
void solve(){
  go( 1 , 0 , 0 );
  for( int i = 0 ; i < ( 1 << 22 ) ; i ++ )
    mxdep[ i ] = - N - N;
  go( 1 , 1 );
  for( int i = 1 ; i <= n ; i ++ )
    printf( "%d%c" , ans[ i ] , " \n"[ i == n ] );
}
int main(){
  init();
  solve();
}