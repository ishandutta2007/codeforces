#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long llint;

int main( void )
{
  int x, y, z, k;
  scanf( "%d%d%d%d", &x, &y, &z, &k );

  llint v = min( 2000000, k / 3 );

  llint a = v, b = v, c = v;
  if( k % 3 == 2 ) ++a, ++b;
  if( k % 3 == 1 ) ++a;

  while( a+1 > x ) { 
    --a; 
    if( b+2 <= y && ( c+2 > z || c > b ) ) ++b;
    else ++c;
  }
  while( b+1 > y ) { 
    --b; 
    if( a+2 <= x && ( c+2 > z || c > a ) ) ++a;
    else ++c;
  }
  while( c+1 > z ) { 
    --c; 
    if( a+2 <= x && ( b+2 > y || b > a ) ) ++a;
    else ++b;
  }
  
  ++a; ++b; ++c;

  a = min( a, (llint)x );
  b = min( b, (llint)y );
  c = min( c, (llint)z );

  llint Sol = min( (llint)x*(llint)y*(llint)z, a*b*c );

  printf( "%I64d\n", Sol );

  return 0;
}