#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, cnt[ 3 ];

int main( void )
{
  scanf( "%d", &n );

  for( int i = 0; i < n; ++i ) {
    int x; scanf( "%d", &x );
    ++cnt[ x % 3 ];
  }

  printf( "%d\n", cnt[0] / 2 + min( cnt[1], cnt[2] ) );

  return 0;
}