#include <cstdio>
#include <cstring>

int N, a, b, d[ 200 ];

int main( void )
{
   scanf( "%d", &N );

   for( int i = 1; i <= N-1; ++i )
      scanf( "%d", d+i );

   scanf( "%d%d", &a, &b );

   int Sol = 0;

   for( int i = a; i < b; ++i )
      Sol += d[i];

   printf( "%d\n", Sol );

   return 0;
}