#include <cstdio>
#include <cstring>

typedef long double ld;

int n, m, h;
int s[ 1005 ];

int main( void )
{
  scanf( "%d%d%d", &n, &m, &h ); --h;
  int tot = 0;

  for( int i = 0; i < m; ++i ) {
    scanf( "%d", s+i );
    tot += s[i];
  }

  if( tot < n ) {
    puts( "-1.0" );
    return 0;
  }

  --tot; --s[h]; --n;

  if( n == 0 ) {
    puts( "0.0" );
    return 0;
  }

  ld Sol = 0.0;

  for( int i = 1; i <= s[h]; ++i ) {
    if( tot-s[h] < n-i || n < i ) continue;

    ld now = 1.0;

    for( int j = tot-n+1; j <= tot; ++j )
      now = now * ld( j-tot+n ) / ld( j );
    
    for( int j = tot-s[h]-n+i+1; j <= tot-s[h]; ++j )
      now = now * ld( j ) / ld( j-tot+s[h]+n-i );

    for( int j = s[h]-i+1; j <= s[h]; ++j )
      now = now * ld( j ) / ld( j-s[h]+i );

    Sol = Sol + now;
  }

  printf( "%.8lf\n", (double)Sol );

  return 0;
}