#include <cstdio>
#include <cstring>
#include <cstdlib>

int N, a[ 101 ];

int main( void )
{
   scanf( "%d", &N );

   for( int i = 0; i < N; ++i )
      scanf( "%d", a+i );

   int best = 1000000, Sol = 0;

   for( int i = 0; i < N; ++i ) {
      int j = ( i+1 )%N;
      if( abs( a[i]-a[j] ) < best ) best = abs( a[i]-a[j] ), Sol = i;
   }

   printf( "%d %d\n", Sol+1, (Sol+1)%N+1 );

   return 0;
}