#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX 10005

int N, n; char buff[ MAX ];
int memo[ MAX ];

int solve( int pos ) {
   if( pos == n ) return 0;
   int &ref = memo[pos];
   if( ref >= 0 ) return ref;

   ref = MAX;

   if( buff[pos] == ' ' ) return ref = solve( pos+1 );

   for( int i = pos; i < pos+N; ++i ) {
      if( buff[i] == '.' || buff[i] == '?' || buff[i] == '!' )
	 ref = min( ref, solve( i+1 )+1 );
   }

   return ref;
}

int main( void )
{
   scanf( "%d\n", &N );
   gets( buff ); n = strlen( buff );

   memset( memo, -1, sizeof memo );
   if( solve( 0 ) == MAX ) printf( "Impossible\n" );
   else printf( "%d\n", solve( 0 ) );

   return 0;
}