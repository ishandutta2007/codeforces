#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int p[ 2005 ];

int main( void )
{
  scanf( "%d", &N );

  for( int i = 0; i < N; ++i ) {
    scanf( "%d", p+i ); --p[i];
  }

  int Sol = 0;
  for( int i = 0; i < N; ++i ) {
    int cnt = 0;
    for( int j = i; j != -2; j = p[j] ) ++cnt;
    Sol = max( Sol, cnt );
  }

  printf( "%d\n", Sol );

  return 0;
}