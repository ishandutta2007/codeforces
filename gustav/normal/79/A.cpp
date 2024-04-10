#include <cstdio>
#include <cstring>

int main( void )
{
  int turn = 0;
  int x, y;

  scanf( "%d%d", &x, &y );

  for( ; ; ) {
    if( turn == 0 ) {
      if( x >= 2 && y >= 2 ) {
	x -= 2; y -= 2;
      }
      else if( x >= 1 && y >= 12 ) {
	x -= 1; y -= 12;
      }
      else if( y >= 22 ) {
	y -= 22;
      }
      else {
	printf( "Hanako\n" );
	return 0;
      }
    }
    else {
      if( y >= 22 ) {
	y -= 22;
      }
      else if( x >= 1 && y >= 12 ) {
	x -= 1; y -= 12;
      }
      else if( x >= 2 && y >= 2 ) {
	x -= 2; y -= 2;
      }
      else {
	printf( "Ciel\n" );
	return 0;
      }
    }
    turn ^= 1;
  }

  return 0;
}