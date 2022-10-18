#include <cstdio>
#include <cstring>

#include <vector>
#include <string>
#include <sstream>

using namespace std;

const char s[2][3][10] = {
  { "lios", "etr", "initis" },
  { "liala", "etra", "inites" }
};

bool suf( string p, int a, int b ) {
  int n = strlen( s[a][b] );
  if( n > p.size() ) return 0;
  return ( string( s[a][b] ) == p.substr( p.size()-n, n ) );
}

vector< int > r;
vector< string > v;
char buff[ 1000005 ];
string sb;

int main( void )
{
  gets( buff );
  sb = string( buff );

  istringstream sin( sb );
  string in;

  while( sin >> in ) v.push_back( in );

  if( v.size() == 1 ) {
    int gen = -1, type = -1;

    for( int i = 0; i < 2; ++i )
      for( int j = 0; j < 3; ++j )
	if( suf( v[0], i, j ) ) gen = i, type = j;

    if( gen != -1 ) puts( "YES" );
    else puts( "NO" );

    return 0;
  }

  int lgen = -1, last = -1;

  for( int i = 0; i < v.size(); ++i ) {
    int gen = -1, type = -1;

    for( int j = 0; j < 2; ++j )
      for( int k = 0; k < 3; ++k )
	if( suf( v[i], j, k ) ) gen = j, type = k;

    if( gen == -1 ) {
      puts( "NO" );
      return 0;
    }

    if( lgen != -1 && gen != lgen ) {
      puts( "NO" );
      return 0;
    }

    r.push_back( type );

    lgen = gen; last = type;
  }

  int pos = 0;

  while( pos < r.size() && r[pos] != 1 ) ++pos;

  if( pos == r.size() ) {
    puts( "NO" );
    return 0;
  }

  for( int i = 0; i < pos; ++i )
    if( r[i] != 0 ) {
      puts( "NO" );
      return 0;
    }
  
  for( int i = pos+1; i < r.size(); ++i )
    if( r[i] != 2 ) {
      puts( "NO" );
      return 0;
    }

  puts( "YES" );

  return 0;
}