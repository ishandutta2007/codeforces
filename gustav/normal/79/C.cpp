#include <cstdio>
#include <cstring>

#include <set>
#include <vector>
#include <algorithm>

using namespace std;

char buff[ 100005 ];
char b[ 15 ];
int N;

vector< int > out[ 100005 ];
multiset< int > s;

int main( void )
{
  scanf( "%s", buff );
  int n = strlen( buff );

  scanf( "%d", &N );

  for( int i = 0; i < N; ++i ) {
    scanf( "%s", b );
    int m = strlen( b );

    for( int j = 0; j+m <= n; ++j ) {
      bool match = 1;

      for( int k = 0; k < m; ++k )
	if( b[k] != buff[j+k] ) match = 0;

      if( match ) {
	out[ j + 1 ].push_back( j + m );
	s.insert( j + m );
      }
    }
  }

  s.insert( n+1 );

  int Sol = 0, Pos = 0;

  for( int i = 0; i < n; ++i ) {
    for( int j = 0; j < out[i].size(); ++j )
      s.erase( s.find( out[i][j] ) );

    if( Sol < *s.begin() - i - 1 ) {
      Sol = *s.begin() - i - 1;
      Pos = i;
    }
  }

  printf( "%d %d\n", Sol, Pos );

  return 0;
}