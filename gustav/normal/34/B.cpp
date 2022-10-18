#include <cstdio>
#include <algorithm>

using namespace std;

int N, M, a[ 101 ];

int main( void )
{
   scanf( "%d%d", &N, &M );

   for( int i = 0; i < N; ++i ) scanf( "%d", a+i );
   sort( a, a + N );

   int Sol = 0;
   for( int i = 0; i < min( N, M ) && a[i] < 0; ++i ) Sol -= a[i];

   printf( "%d\n", Sol );

   return 0;
}