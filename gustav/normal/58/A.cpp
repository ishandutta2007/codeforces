#include <cstdio>
#include <cstring>

const char p[] = "hello";

char b[ 200 ];

int main( void )
{
   scanf( "%s", b ); int n = strlen( b );

   int pp = 0, bp = 0;
   while( pp < 5 && bp < n ) {
      if( b[bp] == p[pp] ) ++bp, ++pp;
      else ++bp;
   }

   printf( ( pp == 5 ) ? "YES\n" : "NO\n" );

   return 0;
}