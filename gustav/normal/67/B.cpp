#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int N, K;
int b[ 1005 ];
int a[ 1005 ];
int ab[ 1005 ];
int alive[ 1005 ];

int main( void )
{
  scanf( "%d%d", &N, &K );

  for( int i = 0; i < N; ++i )
    scanf( "%d", b+i+1 );

  for( int i = 1; i <= N; ++i ) 
    alive[i] = 1;

  for( int i = 0; i < N; ++i ) {
    int take = -1;

    for( int j = 1; j <= N; ++j ) {
      if( !alive[j] ) continue;
      if( ab[j] != b[j] ) continue;

      bool good = 1;

      for( int k = 1; k <= j-K; ++k ) {
	if( !alive[k] ) continue;
	if( ab[k]+1 > b[k] ) { good = 0; break; }
      }

      if( good ) { take = j; break; }
    }

    if( take == -1 ) break;

    alive[take] = 0;
    for( int j = 1; j <= take-K; ++j ) 
      if( alive[j] ) ++ab[j];

    a[i] = take;
  }

  for( int i = 0; i < N; ++i )
    printf( "%d ", a[i] );

  putchar( '\n' );

  return 0;
}