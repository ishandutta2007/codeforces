#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int off = ( 1 << 17 );
const int inf = 0x3f3f3f3f;

#define L( n ) ( ( n ) << ( 1 ) )
#define R( n ) ( L( n ) | ( 1 ) )

int N;
int t[ off << 1 ];

inline void build( int n ) {
  if( n >= off ) return;

  build( L( n ) );
  build( R( n ) );

  t[n] = min( t[L( n )], t[R( n )] );
}

int main( void )
{
  scanf( "%d", &N );

  memset( t, inf, sizeof t );
  
  for( int i = 0; i < N; ++i )
    scanf( "%d", t+i+off );

  build( 1 );

  for( int i = 0; i < N; ++i ) {
    if( t[1] >= t[i+off] ) { printf( "-1 " ); continue; }

    int it = 1;

    for( ; ; ) {
      if( it >= off ) break;
      if( t[R(it)] < t[i+off] ) it = R( it );
      else it = L( it );
    }

    int val = it-off-i-1;

    printf( "%d ", ( val < 0 ) ? -1 : val );
  }

  putchar( '\n' );

  return 0;
}