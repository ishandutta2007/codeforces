// eddy1021
#include <bits/stdc++.h>
using namespace std;
#define N 1021
int n;
char c[ N ][ 9 ];
void init(){
  scanf( "%d" , &n );
  for( int i = 1 ; i <= n ; i ++ )
    scanf( "%s" , c[ i ] );
}
bool okay(){
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 0 ; j <= 3 ; j += 3 )
      if( c[ i ][ j     ] == 'O' &&
          c[ i ][ j + 1 ] == 'O' ){
          c[ i ][ j ] =
          c[ i ][ j + 1 ] = '+';
          return true;
      }
  return false;
}
void solve(){
  if( okay() ){
    puts( "YES" );
    for( int i = 1 ; i <= n ; i ++ )
      puts( c[ i ] );
  }else
    puts( "NO" );
}
int main(){
  init();
  solve();
}