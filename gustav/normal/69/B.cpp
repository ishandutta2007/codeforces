#include <cstdio>
#include <cstring>

#define MAXN 105
#define MAXM 105

int N, M;
int l, r, t;

int c[ MAXM ];
int win[ MAXN ];
int best[ MAXN ];

int main( void )
{
  scanf( "%d%d", &N, &M );

  memset( win, -1, sizeof win );
  memset( best, 0x3f, sizeof best );

  for( int i = 0; i < M; ++i ) {
    scanf( "%d%d%d%d", &l, &r, &t, &c[i] ); --l; --r;

    for( int j = l; j <= r; ++j ) {
      if( t < best[j] ) { best[j] = t; win[j] = i; }
    }
  }

  int Sol = 0;

  for( int i = 0; i < N; ++i )
    if( win[i] != -1 ) Sol += c[win[i]];

  printf( "%d\n", Sol );

  return 0;
}