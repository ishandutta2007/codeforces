#include <cmath>
#include <cstdio>
#include <cstring>

const double eps = 1e-4;

bool lt( double a, double b ) { return a + eps < b; }
bool gt( double a, double b ) { return lt( b, a ); }
bool eq( double a, double b ) { return !lt( a, b ) && !lt( b, a ); }

bool is_int( double d ) {
  int x = d;
  for( int i = x-1; i <= x+1; ++i )
    if( eq( i, d ) ) return 1;
  return 0;
}

double x[ 3 ];
double y[ 3 ];
double a[ 3 ];

int main( void )
{
  for( int i = 0; i < 3; ++i )
    scanf( "%lf%lf", x+i, y+i );

  double a0 = x[0]-x[1];
  double b0 = y[0]-y[1];
  double c0 = 0.5*( a0*( x[0] + x[1] ) + b0*( y[0] + y[1] ) );
  
  double a1 = x[1]-x[2];
  double b1 = y[1]-y[2];
  double c1 = 0.5*( a1*( x[1] + x[2] ) + b1*( y[1] + y[2] ) );

  double X = ( c0*b1 - c1*b0 ) / ( a0*b1 - a1*b0 );
  double Y = ( c0*a1 - c1*a0 ) / ( a1*b0 - a0*b1 );

  for( int i = 0; i < 3; ++i )
    x[i] -= X, y[i] -= Y;

  double r = sqrt( x[0]*x[0] + y[0]*y[0] );

  for( int i = 0; i < 3; ++i )
    x[i] /= r, y[i] /= r;

  for( int i = 0; i < 3; ++i ) 
    a[i] = acos( x[i]*x[(i+1)%3] + y[(i+1)%3]*y[i] );

  for( int i = 3; i <= 100; ++i ) {
    bool good = 1;
    
    for( int j = 0; j < 3; ++j )
      if( !is_int( a[j] / ( 2.0*M_PI / i ) ) ) good = 0;

    if( good ) {
      printf( "%.8lf\n", 0.5*i*r*r*sin( 2.0*M_PI / i ) );
      return 0;
    }
  }

  puts( "nowai" );

  return 0;
}