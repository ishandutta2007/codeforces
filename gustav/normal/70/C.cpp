#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long llint;

#define MAX 100005

typedef long double ldouble;
const ldouble eps = 1e-11;

int maxy, maxx, w;

inline int rev( int x ) {
   int ret = 0;
   while( x ) {
      ret = ret*10+x%10;
      x /= 10;
   }
   return ret;
}

ldouble f[ MAX ];
int v[ MAX ];

inline bool lt( ldouble a, ldouble b ) {
   return ( ( a + eps ) < b );
}

inline bool lte( ldouble a, ldouble b ) {
   return lt( a, b ) || !lt( b, a );
}

inline bool cmpf( int a, int b ) {
   if( !lt( f[a], f[b] ) && !lt( f[b], f[a] ) ) return ( a < b );
   return lt( f[a], f[b] );
}

inline bool cmpf0( int a, int b ) {
   return lt( f[a], f[b] );
}

inline int lb( int x ) {
   int lo = 0, hi = MAX-2, mid;
   while( lo < hi ) {
      mid = ( lo + hi ) >> 1;
      if( lte( 1.0/f[x], f[v[mid]] ) ) hi = mid;
      else lo = mid+1;
   }
   return lo;
}

inline int ub( int x ) {
   int lo = 0, hi = MAX-2, mid;
   while( lo < hi ) {
      mid = ( lo + hi ) >> 1;
      if( lte( f[v[mid]], 1.0/f[x] ) ) lo = mid+1;
      else hi = mid;
   }
   return lo;
}

inline int calc( int y, int x ) {
   // koliko ima brojeva do x sa istim f kao y
   int lo = lb( y );
   int hi = ub( y );
   int l0 = lo;
   int mid;

   while( lo < hi ) {
      mid = ( lo + hi ) >> 1;
      if( v[mid] <= x ) lo = mid+1;
      else hi = mid;
   }
   /*

   int ret = 0;

   for( int i = 0; i < MAX-1; ++i )
      if( !lt( f[v[i]], 1.0/f[y] ) && !lt( 1.0/f[y], f[v[i]] ) && v[i] <= x ) ++ret;

   return ret;
   */

   return lo - l0;
}

int main( void )
{
   for( int i = 1; i < MAX; ++i ) {
      f[i] = ldouble( i ) / ldouble( rev( i ) );
      v[i-1] = i;
   }


   sort( v, v + MAX - 1, cmpf );
   /*

   printf( "%d %d\n", ub( 4 ), lb( 4 ) );

   for( int i = 0; i < MAX; ++i )
      printf( "%d :: %d : %.3lf\n", i, v[i], f[v[i]] );
      */

   scanf( "%d%d%d", &maxx, &maxy, &w );
   bool sw = 0;
   if( maxx < maxy ) swap( maxx, maxy ), sw = 1;

   bool solved = 0;

   llint tot = 1, solx = MAX, soly = MAX;
   for( llint x = 1, y = 1; x <= maxx; ++x ) {
      while( y < min( x, (llint)maxy ) && tot < w ) {
	 // prosiri
	 ++y; tot += calc( y, x );
      }
      while( y > 1 && tot-calc( y, x ) >= w ) { tot -= calc( y, x ); --y; }
      if( tot >= w ) {
	 solved = 1;
	 if( x*y < solx*soly ) { solx = x; soly = y; }
      }
      tot += calc( x+1, y );
   }

   if( !solved ) printf( "-1\n" );
   else {
      if( sw ) swap( solx, soly );
      printf( "%d %d\n", (int)solx, (int)soly );
   }

   return 0;
}