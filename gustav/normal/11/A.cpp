#include <cstdio>
#include <cstring>

int n, d;
int b[ 2005 ];

int main( void )
{
  scanf( "%d%d", &n, &d );

  for( int i = 0; i < n; ++i )
    scanf( "%d", b+i );

  int Sol = 0;

  for( int i = 1; i < n; ++i ) {
    if( b[i-1] < b[i] ) continue;

    int times = ( b[i-1] - b[i] ) / d + 1;

    Sol += times;
    b[i] += times*d;
  }

  printf( "%d\n", Sol );

  return 0;
}