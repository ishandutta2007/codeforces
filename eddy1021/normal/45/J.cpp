// eddy1021
#include <bits/stdc++.h>
using namespace std;
#define N 514
int n , m , a[ N ][ N ];
typedef pair<int,pair<int,int> > data;
#define X first
#define Y second
vector< data > v;
bool cmp( data d1 , data d2 ){
  if( ( d1.X >> 14 ) % 2 != ( d2.X >> 14 ) % 2 )
    return ( d1.X >> 14 ) % 2 < ( d2.X >> 14 ) % 2;
  return d1 < d2;
}
int vv[ N * N ];
int main(){
  scanf( "%d%d" , &n , &m );
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 1 ; j <= m ; j ++ )
      v.push_back( { ( ( i + j ) << 14 ) + i , { i , j } } );
  sort( v.begin() , v.end() , cmp );
  for( int i = 0 ; i < n * m ; i ++ ) vv[ i ] = i + 1;
  reverse( vv , vv + ( n * m + 1 ) / 2 );
  reverse( vv + ( n * m + 1 ) / 2 , vv + n * m );
  for( size_t i = 0 ; i < v.size() ; i ++ )
    a[ v[ i ].Y.X ][ v[ i ].Y.Y ] = vv[ i ];
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 1 ; j <= m ; j ++ )
      if( ( i > 1 && abs( a[ i ][ j ] - a[ i - 1 ][ j ] ) <= 1 ) ||
          ( j > 1 && abs( a[ i ][ j ] - a[ i ][ j - 1 ] ) <= 1 ) ){
        puts( "-1" );
        exit( 0 );
      }
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 1 ; j <= m ; j ++ )
      printf( "%d%c" , a[ i ][ j ] , " \n"[ j == m ] );
}