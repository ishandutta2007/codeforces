#include <cstdio>
#include <cstring>

int main( void )
{
   int N; scanf( "%d", &N );

   int pos = 0;

   for( int i = 0; i < N-1; ++i ) {
      pos += ( i+1 );
      pos %= N;
      printf( "%d ", pos+1 );
   }

   return 0;
}