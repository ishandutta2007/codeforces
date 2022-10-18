#include <cstdio>
#include <cstring>

#include <vector>
#include <algorithm>

using namespace std;

#define MAXM 45
#define MAXN 1005

int N, M;
int a[ MAXM ];

vector< int > v;

int main( void )
{
  scanf( "%d%d", &N, &M );

  for( int i = 0; i < M; ++i ) 
    scanf( "%d", a+i );

  if( M == 2 ) {
    int h = min( a[0], a[1] );
    if( N % 2 == 0 && 2*h >= N ) {
      for( int i = 0; i < N/2; ++i )
	printf( "1 2 " );
      putchar( '\n' );
    }
    else printf( "-1\n" );
    return 0;
  }

  v.push_back( 1 ); --a[0];
  v.push_back( 2 ); --a[1];

  for( int i = 2; i < N; ++i ) {
    for( int j = 0; j < M; ++j ) {
      if( a[j] == 0 ) continue;

      bool done = 0;

      for( int k = 0; k < i && !done; ++k ) {
	int n = ( k + 1 ) % i;
	if( v[k] != j+1 && v[n] != j+1 ) {
	  v.insert( v.begin()+n, j+1 );
	  done = 1;
	}
      }

      if( done ) { --a[j]; break; }
    }

    if( v.size() != i+1 ) break;
  }

  if( v.size() != N ) printf( "-1\n" );
  else
  for( int i = 0; i < N; ++i )
    printf( "%d ", v[i] );

  putchar( '\n' );

  return 0;
}