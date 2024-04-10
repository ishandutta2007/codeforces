#include <cstdio>
#include <cstring>

#include <queue>
#include <algorithm>

using namespace std;

const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, 1, 0, -1 };

#define MAX 205

char buff[ 200 ];

queue< int > qx, qy;

int d[ MAX ][ MAX ];
int bio[ MAX ][ MAX ];

int main( void )
{
  scanf( "%s", buff );
  int n = strlen( buff );

  int x = 100;
  int y = 100;

  bio[x][y] = 1;

  bool ok = 1;

  for( int i = 0; i < n; ++i ) {
    if( buff[i] == 'D' ) ++x;
    if( buff[i] == 'R' ) ++y;
    if( buff[i] == 'U' ) --x;
    if( buff[i] == 'L' ) --y;

    if( ++bio[x][y] > 1 ) ok = 0;
  }

  qx.push( 100 );
  qy.push( 100 );
  d[100][100] = 1;

  while( qx.size() ) {
    int cx = qx.front(); qx.pop();
    int cy = qy.front(); qy.pop();

    for( int i = 0; i < 4; ++i ) {
      int nx = cx + dx[i];
      int ny = cy + dy[i];

      if( nx < 0 || nx == MAX ) continue;
      if( ny < 0 || ny == MAX ) continue;
      if( !bio[nx][ny] ) continue;
      if( d[nx][ny] ) continue;

      d[nx][ny] = d[cx][cy]+1;
      qx.push( nx );
      qy.push( ny );
    }
  }

  if( d[x][y]-1 != n ) ok = 0;

  printf( ok ? "OK\n" : "BUG\n" );

  return 0;
}