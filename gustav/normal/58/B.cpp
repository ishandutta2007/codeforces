#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 1000005

int N;
int dp[ MAXN ];

int main( void )
{
  scanf( "%d", &N );

  for( int i = 1; i <= N; ++i ) {
    dp[i] = max( 1, dp[i] );
    for( int j = 2*i; j <= N; j += i )
      dp[j] = max( dp[j], dp[i]+1 );
  }

  int curr = N;

  for( ; ; ) {
    printf( "%d ", curr );
    if( curr == 1 ) break;
    for( int i = curr-1; i >= 1; --i ) 
      if( curr % i == 0 && dp[i] == dp[curr]-1 ) { curr = i; break; }
  }

  putchar( '\n' );


  return 0;
}