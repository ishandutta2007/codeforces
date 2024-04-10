#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char b[ 100005 ];
int cnt[ 26 ];
int f[ 26 ];
int n, k;

bool cmpf( int a, int b ) { return ( cnt[a] < cnt[b] ); }

int main( void )
{
  scanf( "%s", b );
  n = strlen( b );

  scanf( "%d", &k );

  for( int i = 0; i < n; ++i )
    ++cnt[ b[i] - 'a' ];

  for( int i = 0; i < 26; ++i )
    f[i] = i;

  sort( f, f + 26, cmpf );

  int Sol = 26;

  for( int i = 0; i < 26; ++i ) {
    if( k - cnt[f[i]] < 0 ) break;
    --Sol; k -= cnt[f[i]]; cnt[f[i]] = 0;
  }

  printf( "%d\n", Sol );

  for( int i = 0; i < n; ++i )
    if( cnt[ b[i] - 'a' ] ) putchar( b[i] );

  putchar( '\n' );

  return 0;
}