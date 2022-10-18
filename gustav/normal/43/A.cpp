#include <cstdio>

#include <map>
#include <string>

using namespace std;

map< string, int > m;
string s, Sol; int N, best; char buff[ 200 ];

int main( void )
{
   scanf( "%d", &N );

   for( int i = 0; i < N; ++i ) {
      scanf( "%s", buff );
      s = string( buff );
      if( ++m[s] > best ) { best = m[s]; Sol = s; }
   }

   printf( "%s\n", Sol.c_str() );

   return 0;
}