#include <cstdio>
#include <cstring>

int gl, gr, bl, br;

int main( void )
{
   scanf( "%d%d", &gl, &gr );
   scanf( "%d%d", &bl, &br );

   if( bl >= gr-1 && bl <= 2*gr + 2 ) printf( "YES\n" );
   else if( br >= gl-1 && br <= 2*gl + 2 ) printf( "YES\n" );
   else printf( "NO\n" );
   
   return 0;
}