#include <cstdio>
#include <cstring>

#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 100005

int N, V;
int T, P;

int p[ 2 ][ MAXN ];
int s[ 2 ][ MAXN ];
int f[ 2 ][ MAXN ];
int idx[ 2 ][ MAXN ];
int cnt[ 2 ];

inline bool cmpf0( int a, int b ) {
  return ( p[0][a] > p[0][b] );
}
inline bool cmpf1( int a, int b ) {
  return ( p[1][a] > p[1][b] );
}

inline int get( int s[ MAXN ], int p ) {
  if( p == 0 ) return 0;
  return s[p-1];
}

int main( void )
{
  scanf( "%d%d", &N, &V );

  for( int i = 0; i < N; ++i ) {
    scanf( "%d%d", &T, &P ); --T;
    p[T][cnt[T]++] = P;
    f[T][cnt[T]-1] = cnt[T]-1;
    idx[T][cnt[T]-1] = i;
  }

  sort( f[0], f[0] + cnt[0], cmpf0 );
  sort( f[1], f[1] + cnt[1], cmpf1 );
  int g0 = 0, g1 = 0;

  for( int i = 0; i < 2; ++i ) {
    s[i][0] = p[i][f[i][0]];
    for( int j = 1; j < cnt[i]; ++j )
      s[i][j] = s[i][j-1] + p[i][f[i][j]];
  }

  int Sol = 0;

  for( int i = 0; i <= cnt[1]; ++i ) {
    if( V - 2*i < 0 ) continue;
    int j = min( V - 2*i, cnt[0] );
    if( Sol < get( s[1], i ) + get( s[0], j ) ) {
      Sol = get( s[1], i ) + get( s[0], j );
      g1 = i; g0 = j;
    }
  }

  printf( "%d\n", Sol );

  for( int i = 0; i < g0; ++i )
    printf( "%d ", idx[0][f[0][i]]+1 );
  
  for( int i = 0; i < g1; ++i )
    printf( "%d ", idx[1][f[1][i]]+1 );

  putchar( '\n' );

  return 0;
}