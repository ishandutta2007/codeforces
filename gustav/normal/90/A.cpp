#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main( void )
{
  int r, g, b;
  scanf( "%d%d%d", &r, &g, &b ); 

  int Sol = 0;
  if( r ) Sol = max( Sol, ( r / 2 + r % 2 - 1 )*3 + 30 );
  if( g ) Sol = max( Sol, ( g / 2 + g % 2 - 1 )*3 + 31 );
  if( b ) Sol = max( Sol, ( b / 2 + b % 2 - 1 )*3 + 32 );

  printf( "%d\n", Sol );

  return 0;
}