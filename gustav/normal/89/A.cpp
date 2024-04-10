#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, k;
int a[ 1000005 ];

int main( void )
{
  scanf( "%d%d%d", &n, &m, &k );

  for( int i = 0; i < n; ++i )
    scanf( "%d", a+i );

  if( n == 1 ) {
    printf( "%d\n", (int)min( (long long)m*k, (long long)a[0] ) );
  }
  else if( n % 2 == 0 ) {
    printf( "0\n" );
  }
  else if( n % 2 == 1 ) {
    int M = 1000000;

    for( int i = 0; i < n; i += 2 )
      M = min( M, a[i] );

    int times = m / ( ( n + 1 ) / 2 );
    printf( "%d\n", (int)min( (long long)times*k, (long long)M ) );
  }

  return 0;
}