#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char buff[ 20 ];
int N, M, v;

int main( void )
{
   scanf( "%d%d", &N, &M );

   int l = N+1, r = 0;

   for( int i = 0; i < M; ++i ) {
      scanf( "%*s %*s %s %*s %d", buff, &v );
      if( buff[0] == 'l' ) l = min( l, v );
      else r = max( r, v );
   }

   --l; ++r;

   printf( "%d\n", l >= r ? (l-r+1) : -1 );

   return 0;
}