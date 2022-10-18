#include <cstdio>
#include <cstring>

int N;
int a[ 105 ];

int main( void )
{
  scanf( "%d", &N );

  for( int i = 0; i < N; ++i )
    scanf( "%d", a+i );

  int pos = 0;
  int cnt = 0;

  for( int i = 1; i <= N; ++i ) {
    while( pos < N && a[pos] != i ) ++pos;
    if( pos == N || a[pos] != i ) break;
    a[pos] = 1000000;
    ++cnt;
    ++pos;
  }

  printf( "%d\n", cnt );

  for( int i = 0; i < N; ++i )
    if( a[i] == 1000000 ) printf( "%d ", 2001+i );

  putchar( '\n' );

  return 0;
}