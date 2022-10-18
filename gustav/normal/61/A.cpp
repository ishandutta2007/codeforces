#include <cstdio>
#include <cstring>

char a[ 200 ], b[ 200 ];

int main( void )
{
   scanf( "%s", a ); int n = strlen( a );
   scanf( "%s", b );

   for( int i = 0; i < n; ++i )
      putchar( ((a[i]-'0')^(b[i]-'0'))+'0' );

   putchar( '\n' );

   return 0;
}