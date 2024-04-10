#include <cstdio>
#include <cstring>

#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map< int, int > cnt;

struct cmp {
  bool operator()( int a, int b ) {
    if( cnt[a] == cnt[b] ) return ( a < b );
    return ( cnt[a] > cnt[b] );
  }
};

set< int, cmp > s;
int N, r[ 100005 ];
vector< vector< int > > Sol;

int main( void ) 
{
  scanf( "%d", &N );

  for( int i = 0; i < N; ++i ) {
    scanf( "%d", &r[i] ); 
    ++cnt[r[i]];
  }

  for( int i = 0; i < N; ++i ) {
    if( s.find( r[i] ) == s.end() ) s.insert( r[i] );
  }

  while( s.size() >= 3 ) {
    vector< int > v;

    for( int i = 0; i < 3; ++i ) {
      v.push_back( *s.begin() );
      s.erase( s.begin() );
      --cnt[v.back()];
    }
    for( int i = 0; i < 3; ++i )
      if( cnt[v[i]] ) s.insert( v[i] );

    sort( v.rbegin(), v.rend() );
    Sol.push_back( v );
  }

  printf( "%d\n", (int)Sol.size() );

  for( int i = 0; i < Sol.size(); ++i ) {
    for( int j = 0; j < 3; ++j ) {
      printf( "%d ", Sol[i][j] );
    }
    putchar( '\n' );
  }

  return 0;
}