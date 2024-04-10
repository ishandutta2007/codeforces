#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char a[ 200 ];
char b[ 200 ];

int main( void )
{
   scanf( "%s", a ); int n = strlen( a );

   reverse( a, a + n );
   scanf( "%s", b ); int m = strlen( b );

   if( n != m ) { printf( "NO\n" ); return 0; }

   for( int i = 0; i < n; ++i )
      if( a[i] != b[i] ) { printf( "NO\n" ); return 0; }

   printf( "YES\n" );

   return 0;
}