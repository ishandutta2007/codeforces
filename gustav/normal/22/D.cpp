#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 1005

int N;
int l[ MAXN ];
int r[ MAXN ];
int f[ MAXN ];
int Sol[ MAXN ];

inline bool cmpf( int a, int b ) { return ( r[a] < r[b] ); }

int main( void )
{
  scanf( "%d", &N );

  for( int i = 0; i < N; ++i ) {
    scanf( "%d%d", l+i, r+i );
    if( l[i] > r[i] ) swap( l[i], r[i] );
    f[i] = i;
  }

  sort( f, f + N, cmpf );

  int cnail = -100000, cnt = 0;

  for( int i = 0; i < N; ++i ) {
    if( cnail >= l[f[i]] ) continue;
    cnail = Sol[cnt++] = r[f[i]];
  }

  printf( "%d\n", cnt );

  for( int i = 0; i < cnt; ++i )
    printf( "%d ", Sol[i] );

  putchar( '\n' );

  return 0;
}