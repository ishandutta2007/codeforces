#include <cmath>
#include <cstdio>
#include <cstring>

#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;
char buff[ 105 ];
int val;

set< string > got;
vector< pair< string, int > > Sol;

int main( void )
{
  scanf( "%d%d 0.%d", &N, &M, &K );

  for( int i = 0; i < N; ++i ) {
    scanf( "%s %d", buff, &val );
    if( (K*val/100) < 100 ) continue;
    Sol.push_back( make_pair( string( buff ), K*val/100 ) );
    got.insert( string( buff ) );
  }

  for( int i = 0; i < M; ++i ) {
    scanf( "%s", buff );
    if( got.find( string( buff ) ) != got.end() ) continue;
    Sol.push_back( make_pair( string( buff ), 0 ) );
  }

  sort( Sol.begin(), Sol.end() );
  
  printf( "%d\n", Sol.size() );

  for( int i = 0; i < Sol.size(); ++i )
    printf( "%s %d\n", Sol[i].first.c_str(), Sol[i].second );

  return 0;
}