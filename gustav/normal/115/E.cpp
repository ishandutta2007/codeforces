#include <cstdio>
#include <cstring>

#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;
typedef long long llint;
const int off = ( 1 << 18 );

#define mid ( ( x + y ) >> 1 )
#define L(x) ( ( x ) << ( 1 ) )
#define R(x) ( L( x ) | ( 1 ) )

#define MAX 200005

int N, M, lb, ub;
int r[ MAX ], val;

llint dp[ MAX ];

vector< pair< int, int > > v[ MAX ];

llint t[ off << 1 ];
llint p[ off << 1 ];
int lo, hi;

void prop( int n ) {
  if( !p[n] ) return;
  t[L(n)] += p[n]; p[L(n)] += p[n];
  t[R(n)] += p[n]; p[R(n)] += p[n];
  p[n] = 0;
}

void update( int x, int y, int n, llint v ) {
  if( x >= hi || y <= lo ) return;
  if( x >= lo && y <= hi ) {
    t[n] += v;
    p[n] += v;
    return;
  }
  prop( n );
  update( x, mid, L(n), v );
  update( mid, y, R(n), v );
  t[n] = max( t[L(n)], t[R(n)] );
}

llint query( int x, int y, int n ) {
  if( x >= hi || y <= lo ) return 0;
  if( x >= lo && y <= hi ) return t[n];
  prop( n );
  return max( query( x, mid, L(n) ), query( mid, y, R(n) ) );
}

void Update( int x, int y, llint v ) {
  lo = x; hi = y+1;
  update( 0, off, 1, v );
}

llint Query( int x, int y ) {
  lo = x; hi = y+1;
  return query( 0, off, 1 );
}

int main( void )
{
  scanf( "%d%d", &N, &M );

  for( int i = 0; i < N; ++i ) 
    scanf( "%d", r+i );

  for( int i = 0; i < M; ++i ) {
    scanf( "%d%d%d", &lb, &ub, &val ); --lb; --ub;
    v[lb].push_back( make_pair( ub, val ) );
  }

  dp[N] = 0;
  
  for( int i = N-1; i >= 0; --i ) {
    dp[i] = dp[i+1];

    Update( i+1, N, -r[i] );
    for( int j = 0; j < v[i].size(); ++j ) 
      Update( v[i][j].first+1, N, +v[i][j].second );

    dp[i] = max( dp[i], Query( i+1, N ) );
    Update( i, i, dp[i] );
  }

  cout << dp[0] << "\n";

  return 0;
}