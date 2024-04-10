#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, X;
int a[ 105 ];
///

int main( void )
{
  freopen( "input.txt", "r", stdin );
  freopen( "output.txt", "w", stdout );

  scanf( "%d%d", &n, &X );

  for( int i = 0; i < n; ++i ) {
    int c; scanf( "%d", &c );
    a[i] = c * ( n - i );
  }

  sort( a, a + n );

  int Sol = 0;

  for( int i = 0; i < n; ++i ) 
    if( a[i] <= X ) ++Sol, X -= a[i];

  printf( "%d\n", Sol );

  return 0;
}