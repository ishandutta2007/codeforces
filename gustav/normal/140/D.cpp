#include <cstdio>
#include <cstring>

#include <vector>
#include <algorithm>

using namespace std;

int N, a[ 105 ];

int main( void )
{
  scanf( "%d", &N );

  for( int i = 0; i < N; ++i )
    scanf( "%d", a+i );

  sort( a, a + N );

  int ct = 0;
  int cnt = 0;
  int pen = 0;

  for( int i = 0; i < N && ct < 710; ++i ) {
    if( ct + a[i] > 710 ) break;
    ++cnt; if( ct + a[i] > 350 ) pen += ( ct + a[i] ) - 350;
    ct += a[i];
  }

  printf( "%d %d\n", cnt, pen );

  return 0;
}