#include <cstdio>
#include <cstring>

int N;
char num[ 1001 ][ 5 ];
int dp[ 2012 ][ 1001 ];

int calc( int last, int n ) {
   if( n == N ) return 1;
   int &ref = dp[last][n];
   if( ref >= 0 ) return ref;

   ref = 0;

   int p10 = 1000;
   int now; sscanf( num[n], "%d", &now );

   for( int i = 0; i < 4; ++i ) {
      int curr = (num[n][i]-'0')*p10;
      for( int j = ( i == 0 ); j < 10; ++j ) {
	 now -= curr;
	 now += j*p10;
	 if( now >= last && now >= 1000 && now <= 2011 && calc( now, n+1 ) )
	    return ref = 1;
	 now -= j*p10;
	 now += curr;
      }
      p10 /= 10;
   }

   return ref;
}

void recon( int last, int n ) {
   if( n == N ) return;

   int p10 = 1000;
   int now; sscanf( num[n], "%d", &now );

   for( int i = 0; i < 4; ++i ) {
      int curr = (num[n][i]-'0')*p10;
      for( int j = ( i == 0 ); j < 10; ++j ) {
	 now -= curr;
	 now += j*p10;
	 if( now >= last && now >= 1000 && now <= 2011 && calc( now, n+1 ) ) {
	    printf( "%d\n", now );
	    recon( now, n+1 );
	    return;
	 }
	 now -= j*p10;
	 now += curr;
      }
      p10 /= 10;
   }
}

int main( void )
{
   scanf( "%d", &N );

   for( int i = 0; i < N; ++i )
      scanf( "%s", num[i] );

   memset( dp, -1, sizeof dp );

   if( !calc( 0, 0 ) ) printf( "No solution\n" );
   else recon( 0, 0 );

   return 0;
}