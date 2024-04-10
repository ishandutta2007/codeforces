#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 1010101
int n , a[ N ] , p[ N ] , l[ N ] , r[ N ];
bool in[ N ];
void reset(){
  for( int i = 1 ; i <= n ; i ++ ){
    p[ i ] = l[ i ] = r[ i ] = i;
    in[ i ] = false;
  }
}
int f( int x ){
  return x == p[ x ] ? x : p[ x ] = f( p[ x ] );
}
void uni( int x , int y ){
  x = f( x ); y = f( y );
  if( x == y ) return;
  p[ x ] = y;
  l[ y ] = min( l[ x ] , l[ y ] );
  r[ y ] = max( r[ x ] , r[ y ] );
}
void init(){
  scanf( "%d" , &n );
  for( int i = 1 ; i <= n ; i ++ )
    scanf( "%d" , &a[ i ] );
}
vector< pair<int,int> > v;
void solve(){
  for( int i = 1 ; i <= n ; i ++ )
    v.push_back( { a[ i ] , i } );
  LL ans = 0;
  {
    sort( v.begin() , v.end() );
    reset();
    for( auto i : v ){
      int now = i.second;
      in[ now ] = true;
      if( now - 1 >= 1 and in[ now - 1 ] ) uni( now - 1 , now );
      if( now + 1 <= n and in[ now + 1 ] ) uni( now + 1 , now );
      int prt = f( now );
      LL cnt = 1LL * ( now - l[ prt ] + 1 ) * ( r[ prt ] - now + 1 );
      ans += i.first * cnt;
    }
  }
  {
    reverse( v.begin() , v.end() );
    reset();
    for( auto i : v ){
      int now = i.second;
      in[ now ] = true;
      if( now - 1 >= 1 and in[ now - 1 ] ) uni( now - 1 , now );
      if( now + 1 <= n and in[ now + 1 ] ) uni( now + 1 , now );
      int prt = f( now );
      LL cnt = 1LL * ( now - l[ prt ] + 1 ) * ( r[ prt ] - now + 1 );
      ans -= i.first * cnt;
    }
  }
  printf( "%lld\n" , ans );
}
int main(){
  init();
  solve();
}