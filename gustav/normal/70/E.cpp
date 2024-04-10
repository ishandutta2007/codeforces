#include <cstdio>
#include <cstring>

#include <vector>
#include <algorithm>

using namespace std;
typedef long long llint;
const llint inf = 1000000000000LL;

#define MAXN 185

int N, K;
int a, b;

llint d[ 2*MAXN ];

llint m0[ MAXN ][ 2*MAXN ];
llint m1[ MAXN ][ 2*MAXN ][ 2*MAXN ];

llint dp0( int n, int gore );
llint dp1( int n, int gore, int dole );

int dad[ MAXN ];
vector< int > G[ MAXN ];

inline void dfs( int n ) {
  for( int i = 0; i < G[n].size(); ++i ) {
    if( G[n][i] == dad[n] ) continue;
    dad[G[n][i]] = n;
    dfs( G[n][i] );
  }
}

llint dp0( int n, int gore ) {
  llint &ref = m0[n][gore];
  if( ref >= 0 ) return ref;

  ref = dp1( n, gore, N-1 );

  llint sum = d[gore];

  for( int i = 0; i < G[n].size(); ++i ) {
    if( G[n][i] == dad[n] ) continue;
    dad[G[n][i]] = n;
    sum += dp0( G[n][i], gore+1 );
  }

  return ref = min( ref, sum );
}

llint dp1( int n, int gore, int dole ) {
  llint &ref = m1[n][gore][dole];
  if( ref >= 0 ) return ref;

  if( dole == 0 ) {
    ref = d[0] + K;

    for( int i = 0; i < G[n].size(); ++i ) {
      if( G[n][i] == dad[n] ) continue;
      dad[G[n][i]] = n;
      ref += dp0( G[n][i], 1 );
    }

    return ref;
  }
  else {
    ref = dp1( n, gore, dole-1 );

    llint sum = 0;
    llint mrs = inf;

    for( int i = 0; i < G[n].size(); ++i ) {
      if( G[n][i] == dad[n] ) continue;
      dad[G[n][i]] = n;
      sum += dp0( G[n][i], min( gore, dole )+1 );
      mrs = min( mrs, dp1( G[n][i], gore+1, dole-1 ) - dp0( G[n][i], min( gore, dole )+1 ) );
    }

    return ref = min( ref, sum + mrs + d[ min( gore, dole ) ] );
  }
}

int Sol[ MAXN ];
int FSol[ MAXN ];
int SDis[ MAXN ];

void recon0( int n, int gore );
void recon1( int n, int gore, int dole );

void recon0( int n, int gore ) {
  if( dp0( n, gore ) == dp1( n, gore, N-1 ) ) {
    recon1( n, gore, N-1 );
    return;
  }

  for( int i = 0; i < G[n].size(); ++i ) {
    if( G[n][i] == dad[n] ) continue;
    dad[G[n][i]] = n;
    recon0( G[n][i], gore+1 );
  }
}

void recon1( int n, int gore, int dole ) {
  if( dole == 0 ) {
    Sol[n] = 1;

    for( int i = 0; i < G[n].size(); ++i ) {
      if( G[n][i] == dad[n] ) continue;
      dad[G[n][i]] = n;
      recon0( G[n][i], 1 );
    }
  }
  else {
    if( dp1( n, gore, dole ) == dp1( n, gore, dole-1 ) )  {
      recon1( n, gore, dole-1 );
      return;
    }

    llint sum = 0;

    for( int i = 0; i < G[n].size(); ++i ) {
      if( G[n][i] == dad[n] ) continue;
      dad[G[n][i]] = n;
      sum += dp0( G[n][i], min( gore, dole )+1 );
    }

    int best = -1;
    
    for( int i = 0; i < G[n].size(); ++i ) {
      if( G[n][i] == dad[n] ) continue;
      dad[G[n][i]] = n;
      if( dp1( n, gore, dole ) == sum + dp1( G[n][i], gore+1, dole-1 ) - dp0( G[n][i], min( gore, dole )+1 ) + d[ min( gore, dole ) ] ) {
	best = i;
	break;
      }
    }

    for( int i = 0; i < G[n].size(); ++i ) {
      if( G[n][i] == dad[n] ) continue;
      dad[G[n][i]] = n;

      if( i == best ) recon1( G[n][i], gore+1, dole-1 );
      else recon0( G[n][i], min( gore, dole )+1 );
    }
  }
}

int bio[ MAXN ], cookie;

void dfs1( int start, int n, int dist ) {
  bio[n] = cookie;
  if( Sol[n] && SDis[start] > dist ) {
    SDis[start] = dist;
    FSol[start] = n;
  }

  for( int i = 0; i < G[n].size(); ++i ) {
    if( bio[G[n][i]] == cookie ) continue;
    dfs1( start, G[n][i], dist+1 );
  }
}

int main( void )
{
  scanf( "%d%d", &N, &K );

  if( N == 1 ) {
    printf( "%d\n%d\n", K, 1 );
    return 0;
  }

  for( int i = 1; i <= N-1; ++i )
    scanf( "%lld", d+i );

  for( int i = N; i <= 2*N; ++i )
    d[i] = inf;

  for( int i = 0; i < N-1; ++i ) {
    scanf( "%d%d", &a, &b );
    G[a].push_back( b );
    G[b].push_back( a );
  }

  memset( m0, -1, sizeof m0 );
  memset( m1, -1, sizeof m1 );

  dfs( 1 );

  printf( "%lld\n", dp0( 1, N-1 ) );

  recon0( 1, N-1 );
  
  for( int i = 1; i <= N; ++i )
    SDis[i] = N;

  for( int i = 1; i <= N; ++i ) {
    ++cookie; dfs1( i, i, 0 );
  }

  for( int i = 1; i <= N; ++i )
    printf( "%d ", FSol[i] );

  putchar( '\n' );
  /*
  d[0] = K;

  llint chk = 0;

  for( int i = 1; i <= N; ++i )
    chk += d[SDis[i]];

  if( chk != dp0( 1, N-1 ) )
    fprintf( stderr, "greska\n" );
  else fprintf( stderr, "ac\n" );
  */


  return 0;
}