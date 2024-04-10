#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
typedef unsigned long long llint;

int N, M;
int a, b;

int deg[ 701 ];
int m[ 701 ][ 701 ];
int cnt[ 701 ][ 701 ];

int main( void )
{
  scanf( "%d%d", &N, &M );

  for( int i = 0; i < M; ++i ) {
    scanf( "%d%d", &a, &b ); --a; --b;
    ++deg[a]; ++deg[b];
    m[a][b] = 1;
    m[b][a] = 1;
  }

  llint Sol0 = 0;
  llint Sol1 = 0;

  for( int k = 0; k < N; ++k ) {
    for( int i = 0; i < N; ++i ) {
      if( i == k ) continue;
      if( !m[k][i] ) continue;

      for( int j = 0; j < N; ++j ) {
	if( !m[k][j] ) continue;
	if( i == j || k == j ) continue;

	cnt[i][j] += 1;

	if( m[i][j] ) Sol0 += deg[i]+deg[j]+deg[k]-6;
      }
    }
  }

  Sol0 /= 3;

  for( int i = 0; i < N; ++i ) {
    for( int j = 0; j < N; ++j ) {
      if( i == j ) continue;
      if( !m[i][j] ) continue;

      for( int k = 0; k < N; ++k ) {
	if( i == k || j == k ) continue;
	Sol1 += ( llint( cnt[i][k] - m[j][k] ) * llint( cnt[k][j] - m[i][k] ) );
      }
    }
  }

  cout << ( Sol1 - Sol0 ) / 10 << "\n";
  
  return 0;
}