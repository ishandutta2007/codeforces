#include <cstdio>
#include <cstring>

#include <vector>
#include <algorithm>

using namespace std;
typedef long long llint;

const int mod = 12345;

llint N; int C;
char c; int mu;
int tot;

int p[ 26 ];
int lcm[ 26 ];
vector< int > d[ 26 ];

inline void unpack( int rank ) {
  for( int i = 0; i < 26; ++i ) {
    p[i] = rank % lcm[i];
    rank /= lcm[i];
  }
}

inline int repack() {
  int ret = p[25]%lcm[25];

  for( int i = 24; i >= 0; --i )
    ret = ret * lcm[i] + ( p[i] % lcm[i] );

  return ret;
}

llint m[ 124 ][ 124 ];
llint r[ 124 ][ 124 ];
llint t[ 124 ][ 124 ];

inline void mult( llint a[124][124], llint b[124][124] ) {
  memset( t, 0, sizeof t );

  for( int i = 0; i < tot; ++i )
    for( int j = 0; j < tot; ++j )
      for( int k = 0; k < tot; ++k )
	t[i][j] = ( t[i][j] + a[i][k] * b[k][j] ) % mod;

  memcpy( a, t, sizeof t );
}

int main( void )
{
  scanf( "%I64d%d", &N, &C );

  for( int i = 0; i < C; ++i ) {
    scanf( " %c%d", &c, &mu );
    d[c-'A'].push_back( mu );
  }

  tot = 1;

  for( int i = 0; i < 26; ++i ) {
    lcm[i] = 1;

    for( int j = 0; j < d[i].size(); ++j )
      lcm[i] = ( lcm[i] / __gcd( lcm[i], d[i][j] ) ) * d[i][j];

    tot *= lcm[i];
  }

  for( int i = 0; i < tot; ++i ) {
    unpack( i );
    
    for( int j = 0; j < 26; ++j ) {
      if( d[j].empty() ) continue;
      ++p[j]; 
      ++m[repack()][i];
      --p[j];
    }

    r[i][i] = 1;
  }

  for( int i = 0; ( 1LL << i ) <= N; ++i ) {
    if( ( ( N >> i )&1 ) == 1 ) mult( r, m );
    mult( m, m );
  }

  llint Sol = 0;
  
  for( int i = 0; i < tot; ++i ) {
    unpack( i );

    bool good = 1;
    for( int j = 0; j < 26; ++j ) {
      if( d[j].empty() ) continue;
      bool ok = 0;

      for( int k = 0; k < d[j].size(); ++k )
	if( p[j] % d[j][k] == 0 ) ok = 1;

      good = good && ok;
    }

    if( good ) Sol = ( Sol + r[i][0] ) % mod;
  }

  printf( "%d\n", (int)Sol );

  return 0;
}