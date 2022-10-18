#include <cstdio>
#include <cstring>

int N, f[ 3001 ];

int main( void )
{
   for( int i = 2; i <= 3000; ++i ) {
      if( f[i] ) continue;
      for( int j = i; j <= 3000; j += i )
	 f[j] = i;
   }

   scanf( "%d", &N );

   int Sol = 0;

   for( int i = 2; i <= N; ++i ) {
      int x = i;
      int p0 = f[x]; while( x % p0 == 0 ) x /= p0;
      if( x == 1 ) continue;
      int p1 = f[x]; while( x % p1 == 0 ) x /= p1;
      Sol += ( x == 1 );
   }

   printf( "%d\n", Sol );

   return 0;
}