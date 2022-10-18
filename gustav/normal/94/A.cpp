#include <cstdio>
#include <cstring>

int val[ 2000 ];
char s[ 2000 ];
char b[ 2000 ];

int main( void )
{
  memset( val, -1, sizeof val );

  scanf( "%s", s );

  for( int i = 0; i < 10; ++i ) {
    scanf( "%s", b ); 

    int v = 0;

    for( int j = 0; j < 10; ++j )
      v = v*2+b[j]-'0';

    val[v] = i;
  }

  for( int i = 0; i < 8; ++i ) {
    int v = 0;

    for( int j = i*10; j < (i+1)*10; ++j )
      v = v*2+s[j]-'0';

    printf( "%d", val[v] );
  }
  
  putchar( '\n' );


  return 0;
}