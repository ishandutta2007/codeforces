#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M, K;
char dir[ 20 ];
char buff[ 500 ];

int main( void )
{
  scanf( "%d%d%d", &N, &M, &K ); --M; --K;
  scanf( "%*s%s", dir );
  scanf( "%s", buff ); int n = strlen( buff );

  int d = ( dir[0] == 'h' ? -1 : +1 );
  if( K == 0 && d == +1 || K == N-1 && d == -1 ) d *= -1;

  for( int i = 0; i < n; ++i ) {
    if( buff[i] == '0' ) {
      if( K < M ) M = min( N-1, M+1 );
      else M = max( 0, M-1 );

      if( K == N-1 || K == 0 ) d *= -1;
      K += d;
      
      if( K == M ) {
	printf( "Controller %d\n", i+1 );
	return 0;
      }
    }
    else {
      if( K == N-1 || K == 0 ) d *= -1;
      K += d;
      
      if( d == -1 ) M = N-1;
      if( d == +1 ) M = 0;
    }
  }

  printf( "Stowaway\n" );

  return 0;
}