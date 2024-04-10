#include <cstdio>
#include <cstring>

#include <queue>
#include <iostream>

using namespace std;
typedef long long llint;

int N; llint K;
llint q[ 200005 ];
queue< int > Q;

int main( void )
{
  cin >> N >> K;

  llint tot = 0;

  for( int i = 0; i < N; ++i ) {
    cin >> q[i];
    tot += q[i];
  }

  if( tot < K ) { printf( "-1\n" ); return 0; }

  llint lo = 0, hi = 1000000000, mid;

  while( lo < hi ) {
    mid = ( lo + hi + 1 ) >> 1;

    llint sum = 0;

    for( int i = 0; i < N; ++i )
      sum += min( mid, q[i] );

    if( sum <= K ) lo = mid;
    else hi = mid-1;
  }

  llint lsum = 0;

  for( int i = 0; i < N; ++i )
    lsum += min( lo, q[i] );

  for( int i = 0; i < N; ++i ) {
    if( q[i] <= lo ) continue;
    q[i] -= lo;
    Q.push( i );
  }

  K -= lsum;

  for( int i = 0; i < K; ++i ) {
    int c = Q.front(); Q.pop();
    --q[c];
    if( !q[c] ) continue;
    Q.push( c );
  }

  while( !Q.empty() ) {
    printf( "%d ", Q.front()+1 ); Q.pop();
  }

  putchar( '\n' );

  return 0;
}