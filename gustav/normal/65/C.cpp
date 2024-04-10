#include <cmath>
#include <cstdio>
#include <cstring>

const double eps = 1e-9;

#define MAXN 100005

inline bool lt( double a, double b ) { return (a + eps < b); }
inline bool gt( double a, double b ) { return lt( b, a ); }
inline bool eq( double a, double b ) { return !lt( a, b ) && !lt( b, a ); }
inline bool lte( double a, double b ) { return eq( a, b ) || lt( a, b ); }
inline bool gte( double a, double b ) { return eq( a, b ) || gt( a, b ); }

struct point {
   double x, y, z;
   point() { x = y = z = 0.0; }
   point( double X, double Y, double Z ) { x = X; y = Y; z = Z; }
};

point operator-( point a, point b ) {
   return point( a.x-b.x, a.y-b.y, a.z-b.z );
}
point operator+( point a, point b ) {
   return point( a.x+b.x, a.y+b.y, a.z+b.z );
}

inline point operator*( double d, point p ) {
   return point( p.x*d, p.y*d, p.z*d );
}

inline double sq( double x ) { return x*x; }

inline double len( point p ) {
   return sqrt( sq( p.x ) + sq( p.y ) + sq( p.z ) );
}

inline point unit( point p ) {
   double l = len( p );
   p.x /= l; p.y /= l; p.z /= l;
   return p;
}

int N, x, y, z;
double vp, vs;
point p[ MAXN ], ph;

int main( void )
{
   scanf( "%d", &N ); ++N;

   for( int i = 0; i < N; ++i ) {
      scanf( "%d%d%d", &x, &y, &z );
      p[i] = point( x, y, z );
   }

   scanf( "%lf%lf", &vp, &vs );
   scanf( "%d%d%d", &x, &y, &z );
   ph = point( x, y, z );

   double Sol = 1e21;
   double t0 = 0.0;
   point Spos;

   for( int i = 0; i < N-1; ++i ) {
      point Vs = unit( p[i+1]-p[i] );
      double lo = 0.0, hi = len( p[i+1]-p[i] ), mid;
      for( int j = 0; j < 100; ++j ) {
	 mid = 0.5*( lo + hi );
	 point pos = p[i]+mid*Vs;
	 if( lt( len( pos-ph ), vp*( t0 + mid/vs ) ) ) hi = mid;
	 else lo = mid;
      }
      point pos = p[i]+lo*Vs;
      if( lte( len( pos-ph ), vp*( t0 + lo/vs ) ) && lt( t0 + lo/vs, Sol ) ) {
	 Sol = t0+lo/vs;
	 Spos = pos;
      }
      t0 += len( p[i+1]-p[i] )/vs;
   }

   if( eq( Sol, 1e21 ) ) printf( "NO\n" );
   else {
      printf( "YES\n" );
      printf( "%.8lf\n", Sol );
      printf( "%.8lf %.8lf %.8lf\n", Spos.x, Spos.y, Spos.z );
   }

   return 0;
}