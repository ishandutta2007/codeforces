#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>

const double eps = 1e-9;

bool lt( double a, double b ) { return a + eps < b; }
bool gt( double a, double b ) { return lt( b, a ); }
bool eq( double a, double b ) { return !lt( a, b ) && !lt( b, a ); }

double sq( double d ) { return d * d; }

double dist( double xa, double ya, double xb, double yb ) {
  return sqrt( sq( xa - xb ) + sq( ya - yb ) );
}

int x[ 3 ], y[ 3 ], r[ 3 ];

void prep( int p, int q, double *a, double *b, double *c, double *d ) {
  a[ q - 1 ] = sq( r[q] ) - sq( r[p] );
  b[ q - 1 ] = -2.0 * ( x[p] * sq( r[q] ) - x[q] * sq( r[p] ) );
  c[ q - 1 ] = -2.0 * ( y[p] * sq( r[q] ) - y[q] * sq( r[p] ) );
  d[ q - 1 ] = sq( r[q] ) * ( sq( x[p] ) + sq( y[p] ) ) - sq( r[p] ) * ( sq( x[q] ) + sq( y[q] ) );
}

void cut_lines( double *a, double *b, double *c ) {
  if( eq( a[0] * b[1] - a[1] * b[0], 0.0 ) ) exit( 0 );
  double X = ( - c[0] * b[1] + c[1] * b[0] ) / ( a[0] * b[1] - a[1] * b[0] );
  double Y = ( - c[0] * a[1] + c[1] * a[0] ) / ( a[1] * b[0] - a[0] * b[1] );
  printf( "%lf %lf\n", X, Y );
  exit( 0 );
}

void do_y( double Y, int p, double *a, double *b, double *c, double *d ) {
  double A = a[p];
  double B = b[p];
  double C = a[p] * Y * Y + c[p] * Y + d[p];

  double D = sq( B ) - 4.0 * A * C;

  if( lt( D, 0.0 ) ) exit( 0 );

  double xa = ( -B + sqrt( D ) ) / ( 2.0 * A );
  double xb = ( -B - sqrt( D ) ) / ( 2.0 * A );

  double ta = dist( xa, Y, x[0], y[0] ) / r[0];
  double tb = dist( xb, Y, x[0], y[0] ) / r[0];

  if( lt( ta, tb ) ) printf( "%lf %lf\n", xa, Y );
  else printf( "%lf %lf\n", xb, Y );

  exit( 0 );
}

void do_x( double X, int p, double *a, double *b, double *c, double *d ) {
  double A = a[p];
  double B = c[p];
  double C = a[p] * X * X + b[p] * X + d[p];

  double D = sq( B ) - 4.0 * A * C;

  if( lt( D, 0.0 ) ) exit( 0 );

  double ya = ( -B + sqrt( D ) ) / ( 2.0 * A );
  double yb = ( -B - sqrt( D ) ) / ( 2.0 * A );

  double ta = dist( X, ya, x[0], y[0] ) / r[0];
  double tb = dist( X, yb, x[0], y[0] ) / r[0];

  if( lt( ta, tb ) ) printf( "%lf %lf\n", X, ya );
  else printf( "%lf %lf\n", X, yb );

  exit( 0 );
}

void last_try( double k, double l, int p, double *a, double *b, double *c, double *d ) {
  double A = a[p] + a[p] * sq( k );
  double B = c[p] + 2.0 * k * l * a[p] + b[p] * k;
  double C = d[p] + a[p] * sq( l ) + b[p] * l;

  double D = sq( B ) - 4.0 * A * C;

  if( lt( D, 0.0 ) ) exit( 0 );
  
  double ya = ( -B + sqrt( D ) ) / ( 2.0 * A );
  double yb = ( -B - sqrt( D ) ) / ( 2.0 * A );
  double xa = k * ya + l;
  double xb = k * yb + l;

  double ta = dist( xa, ya, x[0], y[0] ) / r[0];
  double tb = dist( xb, yb, x[0], y[0] ) / r[0];
  
  if( lt( ta, tb ) ) printf( "%lf %lf\n", xa, ya );
  else printf( "%lf %lf\n", xb, yb );

  exit( 0 );
}

void cut( int p, int q, double *a, double *b, double *c, double *d ) {
  double A = b[p];
  double B = c[p];
  double C = d[p];
  
  if( eq( A, 0.0 ) && eq( B, 0.0 ) ) exit( 0 );
  if( eq( A, 0.0 ) ) do_y( -C / B, q, a, b, c, d );
  if( eq( B, 0.0 ) ) do_x( -C / A, q, a, b, c, d );
  
  last_try( -B / A, -C / A, q, a, b, c, d );
}


int main( void )
{
  for( int i = 0; i < 3; ++i )
    scanf( "%d%d%d", x+i, y+i, r+i );

  double a[2], b[2], c[2], d[2];

  prep( 0, 1, a, b, c, d );
  prep( 0, 2, a, b, c, d );

  if( eq( a[0], 0.0 ) && eq( a[1], 0.0 ) ) cut_lines( b, c, d );
  if( eq( a[0], 0.0 ) ) cut( 0, 1, a, b, c, d ); // sa exit( 0 ) zavri
  if( eq( a[1], 0.0 ) ) cut( 1, 0, a, b, c, d );

  double A = b[0] * a[1] - b[1] * a[0];
  double B = c[0] * a[1] - c[1] * a[0];
  double C = d[0] * a[1] - d[1] * a[0];


  if( eq( A, 0.0 ) && eq( B, 0.0 ) ) return 0;
  if( eq( A, 0.0 ) ) do_y( -C / B, 0, a, b, c, d );
  if( eq( B, 0.0 ) ) do_x( -C / A, 0, a, b, c, d );
  
  last_try( -B / A, -C / A, 0, a, b, c, d );

  return 0;
}