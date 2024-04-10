#include <cstdio>
#include <cstring>

#include <vector>
#include <algorithm>

using namespace std;

double Sol;

int N, K, A;
int lvl[ 10 ];
int l[ 10 ];

double calc() {
  double Sol = 0.0;

  for( int i = 0; i < ( 1 << N ); ++i ) {
    double v_prob = 1.0;

    for( int j = 0; j < N; ++j ) {
      if( ( ( i >> j )&1 ) == 1 ) v_prob *= double( min( 100, l[j] ) )/100.0;
      else v_prob *= ( 1.0 - double( min( 100, l[j] ) )/100.0 );
    }

    int pc = __builtin_popcount( i );

    if( pc*2 > N ) Sol += v_prob;
    else {
      int B = 0;
      for( int j = 0; j < N; ++j ) {
	if( ( ( i >> j )&1 ) == 0 ) B += lvl[j];
      }
      Sol += v_prob * double( A ) / double( A + B );
    }
  }

  return Sol;
}

void gen( int pos, int left ) {
  if( pos == N ) {
    Sol = max( Sol, calc() );
    return;
  }

  if( left ) {
    l[pos] += 10;
    gen( pos, left-1 );
    l[pos] -= 10;
  }

  gen( pos+1, left );
}

int main( void )
{
  scanf( "%d%d%d", &N, &K, &A );

  for( int i = 0; i < N; ++i )
    scanf( "%d%d", lvl+i, l+i );

  Sol = .0; gen( 0, K );

  printf( "%.8lf\n", Sol );

  return 0;
}