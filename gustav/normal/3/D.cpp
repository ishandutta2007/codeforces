#include <cstdio>
#include <cstring>

#include <set>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long llint;

#define MAXN 50005

int n, a, b;
char s[ MAXN ];

set< pair< int, int > > pq;

int main( void )
{
  scanf( "%s", s ); n = strlen( s );

  int delta = 0;
  llint Sol = 0;

  for( int i = 0; i < n; ++i ) {
    if( s[i] == '(' ) ++delta;
    if( s[i] == ')' ) --delta;
    if( s[i] == '?' ) {
      scanf( "%d%d", &a, &b );
      pq.insert( make_pair( a-b, i ) );
      s[i] = ')';
      Sol += b;
      --delta;
    }

    if( delta < 0 && !pq.empty() ) {
      s[pq.begin()->second] = '(';
      Sol += pq.begin()->first;
      pq.erase( pq.begin() );
      delta += 2;
    }

    if( delta < 0 ) { puts( "-1" ); return 0; }
  }

  if( delta != 0 ) { puts( "-1" ); return 0; };

  printf( "%I64d\n", Sol );
  puts( s );

  return 0;
}