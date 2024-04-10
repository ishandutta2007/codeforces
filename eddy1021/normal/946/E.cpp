#include <bits/stdc++.h>
using namespace std;
#define N 202020
char s[ N ];
int n , t[ N ];
bool go( int dg , int msk , int bnd , int st ){
  if( dg == n ){
    if( bnd or !st ) return false;
    if( !msk ){
      int ptr = 0;
      while( ptr + 1 < n and !t[ ptr ] ) ptr ++;
      for( int i = ptr ; i < n ; i ++ )
        printf( "%d" , t[ i ] );
      puts( "" );
      return true;
    }
    return false;
  }
  if( __builtin_popcount( msk ) > n - dg )
    return false;
  if( (__builtin_popcount( msk ) + (n - dg)) & 1 ){
    if( !st ){
      t[ dg ] = 0;
      return go( dg + 1 , 0 , 0 , 0 );
    }
    return false;
  }
  if( !bnd ){
    for( int i = 9 ; i >= 0 ; i -- ){
      t[ dg ] = i;
      if( go( dg + 1 , st or i ? msk ^ (1 << i) : msk , 0 , st or i ) )
        return true;
    }
    return false;
  }
  for( int i = s[ dg ] - '0' ; i >= 0 ; i -- ){
    t[ dg ] = i;
    if( go( dg + 1 , st or i ? msk ^ (1 << i) : msk , i == s[ dg ] - '0' , st or i ) )
      return true;
  }
  return false;
}
void solve(){
  if( n & 1 ){
    for( int i = 1 ; i < n ; i ++ )
      putchar( '9' );
    puts( "" );
    return;
  }
  assert( go( 0 , 0 , 1 , 0 ) );
}
int main(){
  int _; scanf( "%d" , &_ ); while( _ -- ){
    scanf( "%s" , s );
    n = strlen( s );
    solve();
  }
}