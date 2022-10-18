#include <cstdio>

int x;

int main( void )
{
   scanf( "%d", &x );
   printf( ( x&1 ) == 0 && ( x >> 1 ) >= 2 ? "YES\n" : "NO\n" );
   return 0;
}