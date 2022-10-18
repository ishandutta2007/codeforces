#include <cmath>
#include <cstdio>

int n, R, r;

int main( void )
{
  scanf( "%d%d%d", &n, &R, &r );

  if( n == 1 ) {
    if( r <= R ) puts( "YES" );
    else puts( "NO" );
    return 0;
  }

  if( n == 2 ) {
    if( 2*r <= R ) puts( "YES" );
    else puts( "NO" );
    return 0;
  }

  double a = M_PI / double( n );
  double r0 = R * sin( a ) / ( 1.0 + sin( a ) );

  if( !( r0 + 1e-9 < r ) ) puts( "YES" );
  else puts( "NO" );

  return 0;
}