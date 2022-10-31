#include <bits/stdc++.h>
using namespace std;
#define N 111
int n;
char c[ N ];
int main(){
  scanf( "%d%s" , &n , c );
  for( int i = 0 ; i < n ; )
    if( c[ i ] == 'o' && c[ i + 1 ] == 'g' && c[ i + 2 ] == 'o' ){
      printf( "***" );
      i += 3;
      while( i + 1 < n && c[ i ] == 'g' && c[ i + 1 ] == 'o' ) i += 2;
    }else putchar( c[ i ++ ] );
  puts( "" );
}