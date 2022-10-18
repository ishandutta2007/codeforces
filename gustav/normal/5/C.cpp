#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n; char s[ 1000005 ];
int st[ 1000005 ], top;

int main( void )
{
  scanf( "%s", s ); n = strlen( s );

  int Sol = 0, Cnt = 1;

  for( int i = 0; i < n; ++i ) {
    if( s[i] == '(' ) st[top++] = 1;
    if( s[i] == ')' ) {
      if( top >= 1 && st[top-1] == 1 ) {
	++st[top-1];
	
	while( top >= 2 && st[top-2] > 1 ) {
	  st[top-2] += st[top-1];
	  --top;
	}
	
	if( Sol < st[top-1] ) { Cnt = 0; Sol = st[top-1]; }
	if( Sol == st[top-1] ) ++Cnt;
      }
      else if( top >= 2 && st[top-2] == 1 ) {
	st[top-2] += st[top-1] + 1;
	--top;

	while( top >= 2 && st[top-2] > 1 ) {
	  st[top-2] += st[top-1];
	  --top;
	}

	if( Sol < st[top-1] ) { Cnt = 0; Sol = st[top-1]; }
	if( Sol == st[top-1] ) ++Cnt;
      }
      else top = 0;
    }
  }

  printf( "%d %d\n", Sol, Cnt );

  return 0;
}