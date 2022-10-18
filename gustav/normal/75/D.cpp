#include <cstdio>
#include <cstring>

#include <vector>
#include <algorithm>

using namespace std;
typedef long long llint;

#define MAXN 55

int N, M, l, x;
llint mps[ MAXN ];
llint mxps[ MAXN ];
llint cps[ MAXN ];
llint best[ MAXN ];
llint cbest[ MAXN ];

int main( void )
{
  scanf( "%d%d", &N, &M );

  for( int i = 0; i < N; ++i ) {
    scanf( "%d", &l );

    cps[i] = 0;
    mxps[i] = -1000000000000000LL;
    best[i] = -1000000000000000LL;
    cbest[i] = -1000000000000000LL;

    for( int j = 0; j < l; ++j ) {
      scanf( "%d", &x ); cps[i] += x;

      if( cbest[i] < 0 ) cbest[i] = x;
      else cbest[i] += x;

      mxps[i] = max( mxps[i], cps[i] );
      best[i] = max( best[i], cbest[i] );
    }
  }

  llint Sol = -1000000000000000000LL;
  llint CS = 0;

  for( int i = 0; i < M; ++i ) {
    scanf( "%d", &x ); --x;
    Sol = max( Sol, CS+mxps[x] );
    CS = max( CS + cps[x], cbest[x] );
    Sol = max( Sol, max( CS, best[x] ) );
  }

  printf( "%I64d\n", Sol );

  return 0;
}