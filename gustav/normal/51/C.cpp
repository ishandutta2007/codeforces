#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 200005

int N, x[ MAXN ];

inline int check( int mid, int print ) {
  int start = 0;
  for( int i = 0; i < 3; ++i ) {
    int nstart = start;
    while( nstart+1 < N && x[nstart+1] - x[start] <= mid ) ++nstart;
    if( print ) printf( "%.6lf ", 0.5*( x[nstart] + x[start] ) );
    start = min( N, nstart+1 );
  }
  if( print ) putchar( '\n' );
  return start;
}

int main( void )
{
  scanf( "%d", &N );

  for( int i = 0; i < N; ++i )
    scanf( "%d", x+i );

  sort( x, x + N );

  int lo = 0, hi = 1000000000, mid;

  while( lo < hi ) {
    mid = ( lo + hi ) >> 1;
    if( check( mid, 0 ) == N ) hi = mid;
    else lo = mid+1;
  }

  printf( "%.6lf\n", 0.5*lo );
  check( lo, 1 );

  return 0;
}