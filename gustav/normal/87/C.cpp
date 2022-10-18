#include <cstdio>
#include <cstring>

#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 100005

int N;
vector< int > v;

int b[ MAXN ];
int dp[ MAXN ];
int sgx[ MAXN ];

inline int get_sg( int a, int b ) {
  int ret = sgx[b];
  if( a ) ret ^= sgx[a-1];
  return ret;
}

int main( void )
{
  scanf( "%d", &N );

  for( int i = 1; i <= N; ++i ) {
    v.clear();

    for( int k = 2; k*( k + 1 )/2 <= i; ++k ) {
      int B = ( i - k*( k + 1 )/2 );
      if( B % k != 0 ) continue;
      B /= k;

      b[get_sg( B+1, B+k )] = 1;
      v.push_back( get_sg( B+1, B+k ) );
    }

    int mex = 0;
    while( b[mex] ) ++mex;

    dp[i] = mex;

    for( int j = 0; j < v.size(); ++j )
      b[v[j]] = 0;

    sgx[i] = sgx[i-1]^dp[i];
  }

  if( dp[N] == 0 ) printf( "-1\n" );
  else {
    for( int k = 2; k*( k + 1 )/2 <= N; ++k ) {
      int B = ( N - k*( k + 1 )/2 );
      if( B % k != 0 ) continue;
      B /= k;

      if( get_sg( B+1, B+k ) == 0 ) {
	printf( "%d\n", k );
	return 0;
      }
    }
  }

  return 0;
}