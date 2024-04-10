#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
char b[ 1000005 ];

int main( void )
{
  scanf( "%s", b );
  n = strlen( b );

  int closed = 0;
  int opened = 0;

  for( int i = 0; i < n; ++i )
    if( b[i] == ')' ) ++closed;

  int Sol = 0;

  for( int i = 0; i < n; ++i ) {
    if( b[i] == '(' && closed >= opened+1 ) ++opened, ++Sol;
    if( b[i] == ')' ) --closed, opened = max( 0, opened-1 );
  }

  printf( "%d\n", 2*Sol );

  return 0;
}