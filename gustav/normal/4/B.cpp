#include <cstdio>

int lo[ 32 ];
int hi[ 32 ];
int d, sum;

int dp[ 32 ][ 300 ];

int main( void )
{
   scanf( "%d%d", &d, &sum );
   for( int i = 0; i < d; ++i )
      scanf( "%d%d", lo+i, hi+i );
   
   for( int i = d; i >= 0; --i )
   for( int j = 0; j <= sum; ++j ) {
      if( i == d ) { dp[i][j] = ( j == 0 ); continue; }
      for( int k = lo[i]; k <= hi[i]; ++k )
         if( j >= k ) dp[i][j] |= dp[i+1][j-k];
   }

   printf( dp[0][sum] ? "YES\n" : "NO\n" );   
   if( dp[0][sum] ) {
      int cd = 0;
      for( ; ; ) {
         if( cd == d ) break;
         for( int i = lo[cd]; i <= hi[cd]; ++i )
            if( dp[cd+1][sum-i] == 1 ) { printf( "%d ", i ); sum -= i; ++cd; break; }
      }
      putchar( '\n' );
   }

   return 0;
}