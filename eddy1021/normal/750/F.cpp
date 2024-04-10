#include <bits/stdc++.h>
using namespace std;
#define N (1<<8)
int n , h , ans , qq;
bool asked[ N ];
vector<int> v[ N ];
void query( int x ){
  if( ans ) return;
  if( ++ qq > 16 ){
    ans = x; return;
  }
  asked[ x ] = true;
  printf( "? %d\n" , x );
  fflush( stdout );
  int k , t; scanf( "%d" , &k );
  if( k == 2 ) ans = x;
  while( k -- ){
    scanf( "%d" , &t );
    v[ x ].push_back( t );
  }
}
void init(){
  scanf( "%d" , &h );
  n = ( 1 << h ) - 1;
  for( int i = 1 ; i <= n ; i ++ ){
    asked[ i ] = false;
    v[ i ].clear();
  }
  ans = qq = 0;
}
deque<int> dq;
inline int unasked( int x ){
  for( int i : v[ x ] )
    if( !asked[ i ] )
      return i;
  return 0;
}
void find_path(){
  dq.clear();
  query( 1 );
  if( ans ) return;
  int nxt = v[ 1 ][ 0 ];
  dq.push_back( 1 );
  while( nxt ){
    query( nxt );
    if( ans ) return;
    dq.push_back( nxt );
    nxt = unasked( nxt );
  }
  if( v[ 1 ].size() > 1u ){
    nxt = v[ 1 ][ 1 ];
    while( nxt ){
      query( nxt );
      if( ans ) return;
      dq.push_front( nxt );
      nxt = unasked( nxt );
    }
  }
}
void go( int now , int dd ){
  if( ans ) return;
  if( !asked[ now ] ) query( now );
  if( ans || dd == 0 ) return;
  for( int nxt = unasked( now ) ; nxt ; nxt = unasked( now ) ){
    go( nxt , dd - 1 );
    if( ans ) return;
  }
}
void solve(){
  find_path();
  while( ans == 0 ){
    int mid = dq[ dq.size() / 2 ];
    int dst = h - 1 - dq.size() / 2;
    int nd = ( 1 << dst ) - 1;
    if( qq + nd <= 17 ){
      go( mid , dst );
      return;
    }
    dq.resize( dq.size() / 2 + 1 );
    int nxt = unasked( mid );
    while( nxt ){
      dq.push_back( nxt );
      query( nxt );
      if( ans ) return;
      nxt = unasked( nxt );
    }
  }
}
int main(){
  int t; scanf( "%d" , &t ); while( t -- ){
    init();
    solve();
    printf( "! %d\n" , ans );
    fflush( stdout );
  }
}