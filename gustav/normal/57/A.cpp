#include <cstdio>
#include <algorithm>

using namespace std;

int main( void )
{
  int n, x1, x2, y1, y2;
  scanf( "%d%d%d%d%d", &n, &x1, &y1, &x2, &y2 );

  if( x1 == x2 && ( x1 == 0 || x1 == n ) ) printf( "%d\n", abs( y1 - y2 ) );
  else if( y1 == y2 && ( y1 == 0 || y1 == n ) ) printf( "%d\n", abs( x1 - x2 ) );
  else {
    int ret = 1000000;
    for( int i = 0; i < 2; ++i ) {
      for( int j = 0; j < 2; ++j ) {
	ret = min( ret, abs( x1-i*n ) + abs( y1-j*n ) + abs( x2-i*n ) + abs( y2-j*n ) );
      }
    }
    printf( "%d\n", ret );
  }

  return 0;
}