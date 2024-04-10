#include <bits/stdc++.h>
using namespace std;
#define N 111
vector< char > v;
char c[ N ];
int k , len;
bool got[ N ];
void bye(){
  puts( "IMPOSSIBLE" );
  exit( 0 );
}
int main(){
  scanf( "%d" , &k );
  scanf( "%s" , c );
  len = strlen( c );
  for( int i = 0 , j = len - 1 ; i <= j ; i ++ , j -- ){
    if( ( c[ i ] == '?' ) ^ ( c[ j ] == '?' ) ){
      if( c[ i ] == '?' ) c[ i ] = c[ j ];
      else c[ j ] = c[ i ];
    }else if( c[ i ] != c[ j ] )
      bye();
    if( c[ i ] != '?' && ( c[ i ] - 'a' >= k ) ) bye();
    if( c[ j ] != '?' && ( c[ j ] - 'a' >= k ) ) bye();
    if( c[ i ] != '?' ) got[ c[ i ] - 'a' ] = true;
    if( c[ j ] != '?' ) got[ c[ j ] - 'a' ] = true;
  }
  for( int i = 0 ; i < len ; i ++ )
    v.push_back( 'a' );
  for( int i = 0 ; i < k ; i ++ )
    if( !got[ i ] )
      v.push_back( (char)( i + 'a' ) );
  for( int i = ( len + 1 ) / 2 - 1 , j = len / 2 ; i >= 0 ; i -- , j ++ )
    if( c[ i ] == '?' || c[ j ] == '?' ){
      c[ i ] = c[ j ] = v.back();
      got[ v.back() - 'a' ] = true;
      v.pop_back();
    }
  for( int i = 0 ; i < k ; i ++ )
    if( !got[ i ] )
      bye();
  puts( c );
}