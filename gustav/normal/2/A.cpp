#include <cstdio>
#include <cstring>

#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
const int inf = 0x3f3f3f3f;

int N;
int s[ 1005 ];
char name[ 1005 ][ 100 ];

map< string, int > m, n, t;

bool cmpf( string a, string b ) {
  return t[a] < t[b];
}

int main( void )
{
  scanf( "%d", &N );

  for( int i = 0; i < N; ++i ) {
    scanf( "%s%d", name[i], &s[i] );
    m[ string( name[i] ) ] += s[i];
  }

  int best = 0;
  vector< string > cand;

  for( map< string, int > :: iterator it = m.begin(); it != m.end(); ++it ) {
    if( it->second > best ) { best = it->second; cand.clear(); }
    if( it->second == best ) { cand.push_back( it->first ); }
  }


  for( int i = 0; i < N; ++i ) 
    t[ string( name[i] ) ] = inf;

  for( int i = 0; i < N; ++i ) {
    if( (n[ string( name[i] ) ] += s[i]) >= best && t[ string( name[i] ) ] == inf )
      t[ string( name[i] ) ] = i;
  }

  sort( cand.begin(), cand.end(), cmpf );
  puts( cand[0].c_str() );

  return 0;
}