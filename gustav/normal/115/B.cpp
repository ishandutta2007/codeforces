#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX 155

int N, M;
char m[ MAX ][ MAX ];

int lm[ MAX ];
int rm[ MAX ];
int dp[ MAX ][ MAX ];

int calc( int x, int y ) {
  if( x == N ) return 0;
  int &ref = dp[x][y];
  if( ref >= 0 ) return ref;

  ref = 100000;

  if( x % 2 == 0 && ( rm[x] == -1 || y >= rm[x] ) ) {
    if( rm[x+1] == -1 || y >= rm[x+1] ) {
      ref = min( ref, calc( x+1, y ) + 1 );
    }
  }
  
  if( x % 2 == 1 && ( lm[x] == -1 || y <= lm[x] ) ) {
    if( lm[x+1] == -1 || y <= lm[x+1] ) {
      ref = min( ref, calc( x+1, y ) + 1 );
    }
  }

  if( x % 2 == 0 && y + 1 < M ) 
    ref = min( ref, calc( x, y+1 ) + 1 );
  
  if( x % 2 == 1 && y - 1 >= 0 ) 
    ref = min( ref, calc( x, y-1 ) + 1 );

  return ref;
}

int main( void )
{
  scanf( "%d%d", &N, &M );

  for( int i = 0; i < N; ++i ) {
    scanf( "%s", m[i] );
    lm[i] = rm[i] = -1;

    for( int j = 0; j < M; ++j ) {
      if( m[i][j] == 'G' ) continue;
      if( lm[i] == -1 ) lm[i] = j;
      rm[i] = j;
    }
  }

  lm[N] = rm[N] = -1;

  while( N > 0 && lm[N-1] == -1 ) --N;

  if( N == 0 ) {
    printf( "0\n" );
    return 0;
  }

  memset( dp, -1, sizeof dp );
  printf( "%d\n", calc( 0, 0 )-1 );

  return 0;
}