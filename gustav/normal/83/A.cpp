#include <cstdio>
#include <cstring>

typedef long long llint;

int a[ 200005 ];

int main( void )
{
  int N; scanf( "%d", &N );

  llint Sol = 0;

  for( int i = 0; i < N; ++i )
    scanf( "%d", a+i );

  for( int i = 0, j; i < N; i = j ) {
    for( j = i+1; j < N && a[i] == a[j]; ++j );
    llint d = j - i;

    Sol += d*( d + 1 )/2LL;
  }

  printf( "%I64d\n", Sol );

  return 0;
}