#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int N, h[ 1001 ];

int main( void )
{
   scanf( "%d", &N );

   for( int i = 0; i < N; ++i ) 
      scanf( "%d", h+i );

   int Sol = 0;

   for( int i = 0; i < N; ++i ) {
      int l = i, r = i;
      while( l > 0 &&   h[l-1] <= h[l] ) --l;
      while( r < N-1 && h[r+1] <= h[r] ) ++r;
      Sol = max( Sol, r-l+1 );
   }

   printf( "%d\n", Sol );

   return 0;
}