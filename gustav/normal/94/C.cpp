#include <cstdio>
#include <cstring>

int n, m, a, b;

int main( void )
{
  scanf( "%d%d", &n, &m );
  scanf( "%d%d", &a, &b ); --a; --b;

  int ra = a / m;
  int rb = b / m;
  int pa = a % m;
  int pb = b % m;

  if( ra == rb || pa == 0 && pb == m-1 || pa == 0 && b == n-1 ) {
    printf( "1\n" );
    return 0;
  }

  if( pa == 0 ) {
    printf( "2\n" );
    return 0;
  }

  if( pb == m-1 ) {
    printf( "2\n" );
    return 0;
  }

  if( pb == pa-1 ) {
    printf( "2\n" );
    return 0;
  }

  if( rb - ra == 1 ) {
    printf( "2\n" );
    return 0;
  }

  if( b == n-1 ) {
    printf( "2\n" );
    return 0;
  }

  printf( "3\n" );

  return 0;
}