#include <bits/stdc++.h>
using namespace std;
#define N 1021
bool pos[ N ][ N + N ];
int bk[ N ][ N + N ];
char c[ N ];
int n , k;
int main(){
  scanf( "%d%d" , &n , &k );
  scanf( "%s" , c + 1 );
  pos[ 0 ][ N ] = true;
  for( int i = 1 ; i <= n ; i ++ ){
    int ret = -2;
    if( c[ i ] == 'W' ) ret = 1;
    else if( c[ i ] == 'D' ) ret = 0;
    else if( c[ i ] == 'L' ) ret = -1;
    if( ret == -2 ){
      for( int j = 1 ; j + 1 < N + N ; j ++ )
        for( int d = -1 ; d <= 1 ; d ++ )
          if( pos[ i - 1 ][ j - d ] ){
            pos[ i ][ j ] = true;
            bk[ i ][ j ] = d;
          }
    }else{
      for( int j = 1 ; j + 1 < N + N ; j ++ )
        if( pos[ i - 1 ][ j ] ){
          pos[ i ][ j + ret ] = true;
          bk[ i ][ j + ret ] = ret;
        }
    }
    if( i < n ){
      for( int j = 0 ; j < N + N ; j ++ )
        if( j - N <= -k or j - N >= k )
          pos[ i ][ j ] = false;
    }
  }
  if( not pos[ n ][ N + k ] and not pos[ n ][ N - k ] ){
    puts( "NO" );
    exit(0);
  }
  int ret = pos[ n ][ N + k ] ? N + k : N - k;
  vector<int> ans;
  for( int i = n ; i >= 1 ; i -- ){
    ans.push_back( bk[ i ][ ret ] );
    ret -= bk[ i ][ ret ];
  }
  reverse( ans.begin() , ans.end() );
  for( auto cc : ans )
    putchar( "LDW"[ cc + 1 ] );
  puts( "" );
}