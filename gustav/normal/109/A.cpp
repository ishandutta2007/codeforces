#include <cstdio>
#include <cstring>

int main( void )
{
  int N; scanf( "%d", &N );

  int bf = N, bs = N;

  for( int i = 0; i*7 <= N; ++i ) {
    if( ( N - i*7 ) % 4 == 0 ) {
      int f = ( N - i*7 ) / 4;
      int s = i;

      if( bf + bs > f + s ) {
	bf = f;
	bs = s;
      }
    }
  }

  if( bf == N && bs == N ) puts( "-1" );
  else {
    for( int i = 0; i < bf; ++i ) putchar( '4' );
    for( int i = 0; i < bs; ++i ) putchar( '7' );
    putchar( '\n' );
  }

  return 0;
}