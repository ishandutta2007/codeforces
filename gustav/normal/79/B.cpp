#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long llint;


#define MAXK 1005

int N, M;
int K, T;
int a, b;
int p[ MAXK ], cnt;

int main( void )
{
  scanf( "%d%d%d%d", &N, &M, &K, &T );

  for( int i = 0; i < K; ++i ) {
    scanf( "%d%d", &a, &b ); --a; --b;
    p[cnt++] = a*M + b;
  }

  sort( p, p + cnt );

  for( int i = 0; i < T; ++i ) {
    scanf( "%d%d", &a, &b ); --a; --b; 
    if( binary_search( p, p + cnt, a*M + b ) ) printf( "Waste\n" );
    else {
      int lb = lower_bound( p, p + cnt, a*M + b )-p;
      int mod = ( ( a*M + b - lb )%3 );
      if( mod == 0 ) puts( "Carrots" );
      if( mod == 1 ) puts( "Kiwis" );
      if( mod == 2 ) puts( "Grapes" );
    }
  }

  return 0;
}