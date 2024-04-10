#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 305

int r[ MAXN ];
int s[ MAXN ];
int sol[ MAXN ];
int inv[ MAXN ];

int m[ MAXN ][ MAXN ];
int p[ MAXN ];
int N;

bool cmpf( int a, int b ) { return ( inv[a] < inv[b] ); }

int pos( int r, int j ) {
  for( int i = 0; i < N; ++i )
    if( m[j][i] == r ) return i;
  return -1;
}

int main( void )
{
  scanf( "%d", &N );

  for( int i = 0; i < N; ++i ) {
    for( int j = 0; j < N; ++j ) {
      scanf( "%d", &m[i][j] );
      --m[i][j];
    }
  }

  for( int i = 0; i < N; ++i ) {
    scanf( "%d", &p[i] );
    inv[--p[i]] = i;
  }

  memset( sol, -1, sizeof sol );
  memset( r, -1, sizeof r );

  int cnt = 0;

  for( int i = 0; i < N; ++i ) {
    s[cnt++] = i;
    sort( s, s + cnt, cmpf );

    for( int j = 0; j < N; ++j ) {
      if( s[0] != j && ( pos( r[j], j ) > pos( s[0], j ) || r[j] == -1 ) ) {
	r[j] = s[0];
	sol[j] = i;
      }
      if( s[0] == j && cnt > 1 && ( pos( r[j], j ) > pos( s[1], j ) || r[j] == -1 ) ) {
	r[j] = s[1];
	sol[j] = i;
      }
    }
  }

  for( int i = 0; i < N; ++i )
    printf( "%d ", sol[i]+1 );
  putchar( '\n' );

  return 0;
}