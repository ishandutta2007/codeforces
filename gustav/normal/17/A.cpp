#include <cstdio>
#include <cstring>

int n, k;
int np[ 1024 ];
int ps[ 1024 ], c;

int main( void )
{
   for( int i = 2; i <= 1000; ++i ) {
      if( np[i] ) continue;
      ps[c++] = i;
      for( int j = 2*i; j <= 1000; j += i )
	 np[j] = 1;
   }
   scanf( "%d%d", &n, &k );
   
   int cnt = 0;
   for( int i = 2; i <= n; ++i ) {
      if( np[i] ) continue;
      for( int j = 0; j+1 < c; ++j ) {
	 if( ps[j]+ps[j+1]+1 > i ) break;
	 if( ps[j]+ps[j+1]+1 == i ) ++cnt;
      }
   }

   printf( ( cnt >= k ) ? "YES\n" : "NO\n" );

   return 0;
}