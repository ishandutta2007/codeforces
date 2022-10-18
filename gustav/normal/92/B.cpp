#include <cstdio>
#include <cstring>

char buff[ 1000005 ];

int main( void )
{
  scanf( "%s", buff );
  int n = strlen( buff );

  int Sol = 0;

  for( int i = n-1, j; i >= 0; i = j ) {
    for( j = i-1; j >= 0 && buff[j] == buff[i]; --j );

    if( j == -1 && i == 0 ) break;

    if( buff[i] == '1' ) {
      Sol += 1 + i - j;
      if( j != -1 ) buff[j] = '1';
    }

    else Sol += i - j;
  }

  printf( "%d\n", Sol );

  return 0;
}