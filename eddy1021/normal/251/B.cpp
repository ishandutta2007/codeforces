#include <bits/stdc++.h>
using namespace std;
#define N 111
struct per{
  int n , a[ N ];
  per( int _n = 0 ) : n( _n ) {}
  void init(){
    for( int i = 1 ; i <= n ; i ++ )
      scanf( "%d" , &a[ i ] );
  }
  per operator*( const per& p ){
    per tp( n );
    for( int i = 1 ; i <= n ; i ++ )
      tp.a[ i ] = a[ p.a[ i ] ];
    return tp;
  }
  per operator-(){
    per tp( n );
    for( int i = 1 ; i <= n ; i ++ )
      tp.a[ a[ i ] ] = i;
    return tp;
  }
  bool operator==( const per& p ){
    assert( n == p.n );
    for( int i = 1 ; i <= n ; i ++ )
      if( a[ i ] != p.a[ i ] )
        return false;
    return true;
  }
} i , q , s;
int n , k;
void init(){
  scanf( "%d%d" , &n , &k );
  q = per( n ); q.init();
  s = per( n ); s.init();
}
inline void bye( const char* c ){
  puts( c );
  exit( 0 );
}
void solve(){
  if( q == -q ){
    i = per( n );
    for( int j = 1 ; j <= n ; j ++ )
      i.a[ j ] = j;
    if( i == s ) bye( "NO" );
    i = i * q;
    if( i == s && k == 1 ) bye( "YES" );
    bye( "NO" );
  }
  for( int _ = 0 ; _ < 2 ; _ ++ ){
    i = per( n );
    for( int j = 1 ; j <= n ; j ++ )
      i.a[ j ] = j;
    if( i == s ) bye( "NO" );
    for( int j = 1 ; j <= k ; j ++ ){
      i = i * q;
      if( i == s && ( k - j ) % 2 == 0 )
        bye( "YES" );
    }
    q = -q;
  }
  bye( "NO" );
}
int main(){
  init();
  solve();
}