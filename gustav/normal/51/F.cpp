#include <cstdio>
#include <cstring>

#include <set>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 2005

int N, M;
int a, b;
int now;

int dis[ MAXN ];
int low[ MAXN ];
int dad[ MAXN ];
int tdad[ MAXN ];

int dp[ MAXN ];
int wei[ MAXN ];
int cnt[ MAXN ];
int lfs[ MAXN ];

int ntdad[ MAXN ];

int s[ MAXN ], top, tot;
int z[ MAXN ], ztop;

int Sol, add;

vector< int > G[ MAXN ];
vector< int > T[ MAXN ];

vector< int > nodes;

inline void pop_bridges( int n ) {
  nodes.push_back( n );
  
  cnt[n] = 0;
  wei[n] = 1;
  dp[n] = 0;

  multiset< int > S;

  while( top && dis[s[top-1]] > dis[n] ) {
    T[n].push_back( s[top-1] );
    T[s[top-1]].push_back( n );

    tdad[s[top-1]] = n;

    cnt[n] += wei[s[top-1]]-1;
    wei[n] += wei[s[top-1]];
    dp[n] += cnt[s[top-1]];

    S.insert( dp[s[top-1]] - cnt[s[top-1]] );
    while( S.size() > 1 ) S.erase( --S.end() );

    --top; ++tot;
  }

  cnt[n] += ( wei[n] > 1 );

  while( ztop && dis[z[ztop-1]] >= dis[n] ) { ++add; ++Sol; --ztop;  }

  --Sol;
  --add;
    
  while( !S.empty() ) {
    dp[n] += *S.begin();
    S.erase( S.begin() );
  }

  s[top++] = n;
}


void build( int n ) {
  z[ztop++] = n;
  dis[n] = low[n] = ++now;


  for( int i = 0; i < G[n].size(); ++i ) {
    if( G[n][i] == dad[n] ) continue;

    if( dis[G[n][i]] ) low[n] = min( low[n], dis[G[n][i]] );
    else {
      dad[G[n][i]] = n;

      build( G[n][i] );
      low[n] = min( low[n], low[G[n][i]] );

      if( low[G[n][i]] > dis[n] ) pop_bridges( G[n][i] );
    }
  }
}

/*

int calc( int n, int cnt_up, int wei_up ) { 
  int ret = cnt_up;
  int rret = 1000000000;

  multiset< int > S;

  int ncnt_up = max( 0, wei_up-1 );
  int nwei_up = wei_up+1;

  for( int i = 0; i < T[n].size(); ++i ) {
    if( T[n][i] == tdad[n] ) continue;
    ret += cnt[T[n][i]];

    ncnt_up += wei[T[n][i]]-1;
    nwei_up += wei[T[n][i]];

    S.insert( dp[ T[n][i] ] - cnt[T[n][i]] );
    while( S.size() > 2 ) S.erase( --S.end() );
  }

  for( int i = 0; i < T[n].size(); ++i ) {
    if( T[n][i] == tdad[n] ) continue;

    nwei_up -= wei[T[n][i]];
    ncnt_up -= wei[T[n][i]]-1;
    ncnt_up += ( nwei_up > 1 );

    rret = min( rret, calc( T[n][i], ncnt_up, nwei_up ) );

    nwei_up += wei[T[n][i]];
    ncnt_up += wei[T[n][i]]-1;
    ncnt_up -= ( nwei_up > 1 );
  }
    
  while( !S.empty() ) {
    ret += *S.begin();
    S.erase( S.begin() );
  }

  return min( ret, rret );
}
*/

int root;

void brute_calc( int n ) {
  dp[n] = 0;
  wei[n] = 1;
  cnt[n] = 0;
  lfs[n] = ( T[n].size() == 1 && n != root );
  
  multiset< int > S;

  for( int i = 0; i < T[n].size(); ++i ) {
    if( T[n][i] == dad[n] ) continue;

    dad[T[n][i]] = n;

    brute_calc( T[n][i] );
    dp[n] += wei[T[n][i]] - lfs[T[n][i]];
    wei[n] += wei[T[n][i]];
    cnt[n] += wei[T[n][i]]-1;

    lfs[n] += lfs[T[n][i]];

    S.insert( dp[T[n][i]] - wei[T[n][i]] + lfs[T[n][i]] );
    while( S.size() > 1 ) S.erase( --S.end() );
  }

  while( !S.empty() ) {
    dp[n] += *S.begin();
    S.erase( S.begin() );
  }
}

inline int brute() {
  int ret = 1000000000;

  for( int i = 0; i < nodes.size(); ++i ) {
    dad[nodes[i]] = 0;
    root = nodes[i];
    brute_calc( nodes[i] );
    ret = min( ret, dp[nodes[i]] );
  }

  return ret;
}

inline int solve( int n ) {
  tot = 1;
  nodes.clear();
  build( n ); pop_bridges( n );
  return brute() + 1;
}

int main( void )
{
  scanf( "%d%d", &N, &M );

  for( int i = 0; i < M; ++i ) {
    scanf( "%d%d", &a, &b );
    G[a].push_back( b );
    G[b].push_back( a );
  }

  for( int i = 1; i <= N; ++i ) {
    if( dis[i] ) continue;
    Sol += solve( i );
  }

  printf( "%d\n", Sol-1 );

  return 0;
}