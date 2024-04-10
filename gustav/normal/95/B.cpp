#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char b[ 100005 ];
int n;

int main( void )
{
  scanf( "%s", b );
  n = strlen( b );

  int pos = 0;

  while( b[pos] == '7' || b[pos] == '4' && pos < n )  ++pos;

  if( pos < n ) {
    for( int i = pos+1; i < n; ++i ) b[i] = '4';
    while( pos > 0 ) {
      if( b[pos] > '7' ) {
	b[pos] = '4';
	++b[pos-1];
      }
      else if( b[pos] <= '4' ) b[pos] = '4';
      else b[pos] = '7';
      --pos;
    }
  }
  else {
    for( int i = 0; i < n; ++i ) {
      if( b[i] <= '4' ) b[i] = '4';
      else b[i] = '7';
    }
  }

  if( n % 2 == 0 && b[0] > '7' ) ++n;
  if( b[0] <= '4' ) b[0] = '4';
  else if( b[0] <= '7' ) b[0] = '7';

  if( n % 2 == 0 ) {
    int cnt4 = 0;
    int cnt7 = 0;

    for( int i = 0; i < n; ++i ) {
      if( b[i] == '4' ) ++cnt4;
      if( b[i] == '7' ) ++cnt7;
    }

    if( cnt4 == cnt7 ) {
      puts( b );
      return 0;
    }

    bool done = 0;

    for( int i = n-1; i >= 0; --i ) {
      if( b[i] == '4' ) --cnt4;
      if( b[i] == '7' ) --cnt7;

      if( b[i] == '4' && max( cnt4, cnt7+1 ) <= n / 2 ) {
	done = 1;

	b[i] = '7';

	for( int j = i+1; j < n; ++j ) {
	  if( cnt4+1 <= n / 2 ) { b[j] = '4'; ++cnt4; }
	  else { b[j] = '7'; ++cnt7; }
	}

	break;
      }
    }

    if( !done ) ++n;
    else puts( b );
  }

  if( n % 2 == 1 ) {
    ++n;
    for( int i = 0; i < n / 2; ++i ) putchar( '4' );
    for( int i = 0; i < n / 2; ++i ) putchar( '7' );
    putchar( '\n' );
  }

  return 0;
}