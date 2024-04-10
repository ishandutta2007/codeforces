#include <cstdio>
#include <cstring>

char b[ 20 ];
int n;

int main( void )
{
  scanf( "%s", b );
  n = strlen( b );

  if( n % 2 == 0 ) {
    for( int i = 0; i < ( 1 << n ); ++i ) {
      if( __builtin_popcount( i ) != n / 2 ) continue;

      bool ok = 1;

      for( int j = 0; j < n; ++j ) {
	char curr = ( ( i >> ( n-j-1 ) ) & 1 ) ? '7' : '4';
	if( curr < b[j] ) { ok = 0; break; }
	if( curr > b[j] ) break;
      }

      if( ok ) {
	for( int j = 0; j < n; ++j ) {
	  char curr = ( ( i >> ( n-j-1 ) ) & 1 ) ? '7' : '4';
	  putchar( curr );
	}
	putchar( '\n' );
	return 0;
      }
    }
    ++n;
  }

  ++n;

  for( int i = 0; i < n/2; ++i )
    putchar( '4' );
  
  for( int i = 0; i < n/2; ++i )
    putchar( '7' );
  
  putchar( '\n' );

  return 0;
}