#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int N, a[ 1001 ];

int main( void )
{
   scanf( "%d", &N );

   for( int i = 0; i < N; ++i ) 
      scanf( "%d", a+i );

   int Sol = 0, Cnt = 0;

   sort( a, a + N );

   for( int i = 0, j; i < N; i = j ) {
      for( j = i+1; a[i] == a[j] && j < N; ++j );
      Sol = max( Sol, j-i );
      ++Cnt;
   }

   printf( "%d %d\n", Sol, Cnt );

   return 0;
}