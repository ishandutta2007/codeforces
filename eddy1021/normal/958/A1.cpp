#include <bits/stdc++.h>
using namespace std;
#define N 50
int n;
char c[ 2 ][ N ][ N ] , t[ N ][ N ];
void rotate(){
  for( int i = 0 ; i < n ; i ++ )
    for( int j = 0 ; j < n ; j ++ )
      t[ i ][ j ] = c[ 0 ][ i ][ j ];
// j = 0 i = n - 1 .. 0
  for( int i = 0 ; i < n ; i ++ )
    for( int j = 0 ; j < n ; j ++ )
      c[ 0 ][ i ][ j ] = t[ j ][ n - 1 - i ];
}
void flip_h(){
  for( int i1 = 0 , i2 = n - 1 ; i1 < i2 ; i1 ++ , i2 -- )
    for( int j = 0 ; j < n ; j ++ )
      swap( c[ 0 ][ i1 ][ j ] , c[ 0 ][ i2 ][ j ] );
}
void flip_v(){
  for( int j1 = 0 , j2 = n - 1 ; j1 < j2 ; j1 ++ , j2 -- )
    for( int i = 0 ; i < n ; i ++ )
      swap( c[ 0 ][ i ][ j1 ] , c[ 0 ][ i ][ j2 ] );
}
bool same(){
  for( int i = 0 ; i < n ; i ++ )
    for( int j = 0 ; j < n ; j ++ )
      if( c[ 0 ][ i ][ j ] != c[ 1 ][ i ][ j ] )
        return false;
  return true;
}
int main(){
  cin >> n;
  for( int i = 0 ; i < 2 ; i ++ )
    for( int j = 0 ; j < n ; j ++ )
      cin >> c[ i ][ j ];
  for( int f1 = 0 ; f1 < 2 ; f1 ++ ){
    for( int f2 = 0 ; f2 < 2 ; f2 ++ ){
      for( int rr = 0 ; rr < 4 ; rr ++ ){
        if( same() ){
          puts( "Yes" );
          return 0;
        }
        rotate();
      }
      flip_v();
    }
    flip_h();
  }
  puts( "No" );
}