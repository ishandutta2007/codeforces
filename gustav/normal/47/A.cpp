#include <cstdio>
#include <cmath>

int main( void )
{
   int N; scanf( "%d", &N );
   N *= 2;

   int v = int( round(sqrt( 1+4*N ))+0.1 );

   printf( v*v == 1+4*N && (v % 2) ? "YES\n" : "NO\n" );

   return 0;
}