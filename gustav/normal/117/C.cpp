#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX 5005

int N;
char m[ MAX ][ MAX ];

int got[ MAX ];
int low[ MAX ];
int dis[ MAX ], now;
int stk[ MAX ], top;

void dfs( int n ) {
  dis[n] = low[n] = ++now;
  got[stk[top++] = n] = 1;

  for( int i = 0; i < N; ++i ) {
    if( m[n][i] == '0' ) continue;
    if( dis[i] && got[i] ) low[n] = min( low[n], dis[i] );
    else if( !dis[i] ) {
      dfs( i );
      low[n] = min( low[n], low[i] );
    }
  }

  if( low[n] != dis[n] ) return;

  int ntop = top-1;
  while( stk[ntop] != n ) --ntop;

  for( int i = ntop; i < top; ++i )
    got[stk[i]] = 0;

  if( top - ntop < 3 ) { top = ntop; return; }

  for( int i = ntop+1; i < top; ++i ) {
    for( int j = ntop+1; j < top; ++j ) {
      if( i == j ) continue;
      if( m[n][stk[i]] == '1' && m[stk[i]][stk[j]] == '1' && m[stk[j]][n] == '1' ) {
	printf( "%d %d %d\n", n+1, stk[i]+1, stk[j]+1 );
	exit( 0 );
      }
    }
  }
  
  top = ntop;
}

int main( void )
{
  scanf( "%d", &N );

  for( int i = 0; i < N; ++i )
    scanf( "%s", m[i] );

  for( int i = 0; i < N; ++i )
    if( !dis[i] ) dfs( i );

  printf( "-1\n" );

  return 0;
}