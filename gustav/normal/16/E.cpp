#include <cstdio>
#include <cstring>

int N;
double a[ 18 ][ 18 ];

double sum[ 1 << 18 ][ 18 ];
double dp[ 1 << 18 ];
int clz[ 1 << 18 ];

int main( void )
{
   scanf( "%d", &N );

   for( int i = 0; i < N; ++i )
   for( int j = 0; j < N; ++j )
      scanf( "%lf", &a[i][j] );

   for( int i = 0; i < 18; ++i )
      clz[1<<i] = i;
      

   for( int i = 1; i < ( 1 << N ); ++i ) 
      for( int j = 0; j < N; ++j ) 
	 sum[i][j] = sum[i^(i&-i)][j]+a[clz[(i&-i)]][j];

   for( int x = 0; x < N; ++x ) {
      for( int i = 0; i < ( 1 << N ); ++i ) {
	 if( !( ( i >> x )&1 ) ) { continue; }
	 if( i == ( 1 << x ) ) { dp[i] = 1.0; continue; }
	 int p = __builtin_popcount( i );
	 p = p*(p-1)/2;
	 dp[i] = 0.0;
	 for( int j = 0; j < N; ++j )
	    if( j != x && ( ( i >> j )&1 ) ) dp[i] += sum[i][j]*dp[i^(1<<j)];
	 dp[i] /= p;
      }
      printf( "%.6lf ", dp[( 1 << N )-1] );
   }
   putchar( '\n' );

   return 0;
}