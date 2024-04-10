#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int inf = 0x3f3f3f3f;

#define MAX 1005

int N, m;
int d2[ MAX ][ MAX ], dp2[ MAX ][ MAX ];
int d5[ MAX ][ MAX ], dp5[ MAX ][ MAX ];

char buff[ 2*MAX ];

int main( void )
{
  scanf( "%d", &N );

  bool zero = 0;
  int zx, zy;

  for( int i = 0; i < N; ++i ) {
    for( int j = 0; j < N; ++j ) {
      scanf( "%d", &m );
      if( m == 0 ) { zero = 1; zx = i; zy = j; ++d2[i][j]; ++d5[i][j]; continue; }
      while( m % 2 == 0 ) { m /= 2; ++d2[i][j]; }
      while( m % 5 == 0 ) { m /= 5; ++d5[i][j]; }
    }
  }

  for( int i = 0; i < N; ++i ) {
    for( int j = 0; j < N; ++j ) {
      dp2[i][j] = ( i+j == 0 ) ? 0 : inf;
      dp5[i][j] = ( i+j == 0 ) ? 0 : inf;

      if( i ) dp2[i][j] = min( dp2[i][j], dp2[i-1][j] ), dp5[i][j] = min( dp5[i][j], dp5[i-1][j] );
      if( j ) dp2[i][j] = min( dp2[i][j], dp2[i][j-1] ), dp5[i][j] = min( dp5[i][j], dp5[i][j-1] );

      dp2[i][j] += d2[i][j];
      dp5[i][j] += d5[i][j];
    }
  }

  if( dp2[N-1][N-1] <= dp5[N-1][N-1] && ( !zero || dp2[N-1][N-1] == 0 ) ) {
    printf( "%d\n", dp2[N-1][N-1] );

    int x = N-1, y = N-1; buff[x+y] = 0;

    while( x + y > 0 ) {
      if( x && dp2[x][y] == dp2[x-1][y] + d2[x][y] ) { --x; buff[x+y] = 'D'; }
      else { --y; buff[x+y] = 'R'; }
    }
  }
  else if( !zero || dp5[N-1][N-1] == 0 ) {
    printf( "%d\n", dp5[N-1][N-1] );
    int x = N-1, y = N-1; buff[x+y] = 0;

    while( x + y > 0 ) {
      if( x && dp5[x][y] == dp5[x-1][y] + d5[x][y] ) { --x; buff[x+y] = 'D'; } 
      else { --y; buff[x+y] = 'R'; }
    }
  }
  else {
    printf( "1\n" );

    int x = 0, y = 0;

    while( x < zx ) { buff[x+y] = 'D'; ++x; }
    while( y < zy ) { buff[x+y] = 'R'; ++y; }
    while( x < N-1 ) { buff[x+y] = 'D'; ++x; }
    while( y < N-1 ) { buff[x+y] = 'R'; ++y; }

    buff[x+y] = 0;
  }

  puts( buff );


  return 0;
}