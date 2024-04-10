#include <cstdio>
#include <cstring>

char m[ 3 ][ 4 ];

bool won( char c ) {
  for( int i = 0; i < 3; ++i ) {
    int ccnt = 0;
    for( int j = 0; j < 3; ++j )
      if( m[i][j] == c ) ++ccnt;
    if( ccnt == 3 ) return 1;
  }
  for( int i = 0; i < 3; ++i ) {
    int ccnt = 0;
    for( int j = 0; j < 3; ++j )
      if( m[j][i] == c ) ++ccnt;
    if( ccnt == 3 ) return 1;
  }
  if( m[0][0] == c && m[1][1] == c && m[2][2] == c ) return 1;
  if( m[0][2] == c && m[1][1] == c && m[2][0] == c ) return 1;
  return 0;
}

int cnt( char c ) {
  int ccnt = 0;
  for( int i = 0; i < 3; ++i ) 
    for( int j = 0; j < 3; ++j )
      if( m[i][j] == c ) ++ccnt;
  return ccnt;
}

int main( void )
{
  for( int i = 0; i < 3; ++i ) 
    scanf( "%s", m[i] );

  if( won( 'X' ) && won( '0' ) ) puts( "illegal" );
  else if( cnt( 'X' ) < cnt( '0' ) || cnt( 'X' ) - cnt( '0' ) > 1 ) puts( "illegal" );
  else if( won( 'X' ) && cnt( 'X' )-1 == cnt( '0' ) ) puts( "the first player won" );
  else if( won( '0' ) && cnt( 'X' ) == cnt( '0' ) ) puts( "the second player won" );
  else if( won( 'X' ) || won( '0' ) ) puts( "illegal" );
  else if( cnt( 'X' ) + cnt( '0' ) == 9 ) puts( "draw" );
  else if( cnt( 'X' ) > cnt( '0' ) ) puts( "second" );
  else puts( "first" );

  return 0;
}