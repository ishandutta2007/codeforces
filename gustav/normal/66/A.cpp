#include <cstdio>
#include <cstring>
#include <cctype>

typedef unsigned long long llint;

char buff[ 1000 ];

int main( void )
{
   gets( buff ); int n = strlen( buff );

   if( buff[0] != '-' ) {
      if( n >= 20 ) printf( "BigInteger\n" );
      else {
	 llint x = 0; int pos0 = 0;
	 for( int i = 0; i < n; ++i )
	    x = x*10+buff[i]-'0';
	 if( x <= 127 ) printf( "byte\n" );
	 else if( x <= 32767 ) printf( "short\n" );
	 else if( x <= 2147483647 ) printf( "int\n" );
	 else if( x <= 9223372036854775807LLU ) printf( "long\n" );
	 else printf( "BigInteger\n" );
      }
   }
   else {
      int pos0 = 1; while( !isdigit( buff[pos0] ) ) ++pos0;
      if( n-pos0+1 >= 21 ) printf( "BigInteger\n" );
      else {
	 llint x = 0; 
	 for( int i = pos0; i < n; ++i )
	    x = x*10+buff[i]-'0';
	 if( x <= 128 ) printf( "byte\n" );
	 else if( x <= 32768 ) printf( "short\n" );
	 else if( x <= 2147483648 ) printf( "int\n" );
	 else if( x <= 9223372036854775808LLU ) printf( "long\n" );
	 else printf( "BigInteger\n" );
      }
   }

   return 0;
}