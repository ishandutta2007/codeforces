#include <cstdio>
#include <cstring>

char p0[ 3 ];
char p1[ 3 ];
char Sol[ 100 ][ 3 ];
int cnt;

int main( void )
{
  scanf( "%s", p0 );
  scanf( "%s", p1 );

  int x0 = p0[0]-'a', y0 = p0[1]-'1';
  int x1 = p1[0]-'a', y1 = p1[1]-'1';
  int dx, dy; char xc, yc;

  if( x0 <= x1 ) dx = +1, xc = 'R'; else dx = -1, xc = 'L';
  if( y0 <= y1 ) dy = +1, yc = 'U'; else dy = -1, yc = 'D';

  while( x0 != x1 && y0 != y1 ) {
    Sol[cnt][0] = xc;
    Sol[cnt][1] = yc;
    x0 += dx;
    y0 += dy;
    ++cnt;
  }

  while( x0 != x1 ) {
    Sol[cnt][0] = xc;
    x0 += dx;
    ++cnt;
  }
  
  while( y0 != y1 ) {
    Sol[cnt][0] = yc;
    y0 += dy;
    ++cnt;
  }

  printf( "%d\n", cnt );

  for( int i = 0; i < cnt; ++i )
    puts( Sol[i] );

  return 0;
}