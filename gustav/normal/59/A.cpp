#include <cstdio>
#include <cctype>
#include <cstring>

char buff[ 101 ];

int main( void )
{
   scanf( "%s", buff ); int n = strlen( buff );
   int cnt = 0;
   for( int i = 0; i < n; ++i ) cnt += ( toupper( buff[i] ) == buff[i] );
   for( int i = 0; i < n; ++i ) 
      buff[i] = ( cnt*2 > n ) ? toupper( buff[i] ) : tolower( buff[i] );

   printf( "%s\n", buff );

   return 0;
}