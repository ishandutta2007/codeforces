#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M;
int dp[ 16 ][ 16 ][ 1 << 16 ];

inline int add( int mask, int v ) {
   if( ( mask>>v )&1 ) return mask;
   return ( mask ^ ( 1 << v ) );
}
inline int remove( int mask, int v ) {
   if( !( mask>>v )&1 ) return mask;
   return ( mask ^ ( 1 << v ) );
}

int calc( int r, int c, int mask ) {
   if( r == N ) return 0;
   if( c == M ) return calc( r+1, 0, mask );

   int &ref = dp[r][c][mask];
   if( ref >= 0 ) return ref;

   ref = 0;

   if( c+1 < M && !( (mask>>c)&1 ) && !( (mask>>(c+1))&1 ) )
      ref = max( ref, calc( r, c+2, mask )+1 );

   if( r+1 < N && !( (mask>>c)&1 ) )
      ref = max( ref, calc( r, c+1, add( mask, c ) )+1 );

   ref = max( ref, calc( r, c+1, remove( mask, c ) ) );

   return ref;
}

int main( void )
{
   scanf( "%d%d", &N, &M );
   memset( dp, -1, sizeof dp );
   printf( "%d\n", calc( 0, 0, 0 ) );

   return 0;
}