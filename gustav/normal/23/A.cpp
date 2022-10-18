#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char b[ 105 ];
int n;

int dp[ 105 ][ 105 ];

int calc( int x, int y ) {
  if( x == n || y == n ) return 0;
  if( b[x] != b[y] ) return 0;

  int &ref = dp[x][y];
  if( ref >= 0 ) return ref;

  return 1 + calc( x+1, y+1 );
}

int main( void )
{
  scanf( "%s", b );
  n = strlen( b );

  memset( dp, -1, sizeof dp );

  int Sol = 0;

  for( int i = 0; i < n; ++i )
    for( int j = i+1; j < n; ++j )
      Sol = max( Sol, calc( i, j ) );

  printf( "%d\n", Sol );

  return 0;
}