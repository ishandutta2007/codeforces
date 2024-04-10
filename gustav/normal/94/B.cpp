#include <cstdio>
#include <cstring>

int N, a, b;
int m[ 5 ][ 5 ];

int main( void )
{
  scanf( "%d", &N );

  for( int i = 0; i < N; ++i ) {
    scanf( "%d%d", &a, &b ); --a; --b;
    m[a][b] = m[b][a] = 1;
  }

  for( int i = 0; i < 5; ++i ) 
    for( int j = i+1; j < 5; ++j )
      for( int k = j+1; k < 5; ++k )
	if( m[i][j] && m[i][k] && m[k][j] || !m[i][j] && !m[i][k] && !m[k][j] ) {
	  puts( "WIN" );
	  return 0;
	}
  puts( "FAIL" );

  return 0;
}