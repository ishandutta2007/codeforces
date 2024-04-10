#include <cstdio>
#include <cstring>

#include <vector>
#include <algorithm>

using namespace std;
typedef long long llint;

#define MAXN 100005

int N, a, b, w;

struct edge {
  int b, w;
  edge( int B, int W ) { b = B; w = W; }
};

int dad[ MAXN ];
vector< edge > T[ MAXN ];

int longest( int n ) {
  int ret = 0;
  for( int i = 0; i < T[n].size(); ++i ) {
    if( T[n][i].b == dad[n] ) continue;
    dad[T[n][i].b] = n;
    ret = max( ret, longest( T[n][i].b ) + T[n][i].w );
  }
  return ret;
}

int main( void )
{
  scanf( "%d", &N );

  llint Sol = 0;

  for( int i = 0; i < N-1; ++i ) {
    scanf( "%d%d%d", &a, &b, &w );
    T[a].push_back( edge( b, w ) );
    T[b].push_back( edge( a, w ) );
    Sol += 2*w;
  }

  Sol -= longest( 1 );

  printf( "%I64d\n", Sol );

  return 0;
}