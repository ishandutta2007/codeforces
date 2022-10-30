#include <bits/stdc++.h>
using namespace std;
#define N 111
int n , m , a[ N ] , l[ N ];
bool used[ N ];
int main(){
  cin >> n >> m;
  for( int i = 0 ; i < m ; i ++ )
    cin >> l[ i ];
  for( int i = 1 ; i < m ; i ++ ){
    int x = ( l[ i ] - l[ i - 1 ] + n ) % n;
    if( x == 0 ) x = n;
    if( a[ l[ i - 1 ] ] == 0 ){
      if( used[ x ] ){
        puts( "-1" );
        exit(0);
      }
      a[ l[ i - 1 ] ] = x;
      used[ x ] = true;
      continue;
    }
    if( x != a[ l[ i - 1 ] ] ){
      puts( "-1" );
      exit(0);
    }
  }
  for( int i = 1 ; i <= n ; i ++ ) if( a[ i ] == 0 )
    for( int j = 1 ; j <= n ; j ++ ) if( !used[ j ] ){
      a[ i ] = j;
      used[ j ] = true;
      break;
    }
  for( int i = 1 ; i <= n ; i ++ )
    printf( "%d%c" , a[ i ] , " \n"[ i == n ] );
}