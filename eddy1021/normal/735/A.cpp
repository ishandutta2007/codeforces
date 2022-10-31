#include <bits/stdc++.h>
using namespace std;
#define N 1021
int n , k , len;
char c[ N ];
int main(){
  scanf( "%d%d" , &n , &k );
  scanf( "%s" , c );
  len = strlen( c );
  for( int i = 0 ; c[ i ] ; i ++ )
    if( isalpha( c[ i ] ) ){
      for( int j = i + k ; j < len ; j += k ){
        if( c[ j ] == '#' ) break;
        if( isalpha( c[ j ] ) ){
          puts( "YES" );
          exit( 0 );
        }
      }
      break;
    }
  puts( "NO" );
}