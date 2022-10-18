#include <cctype>
#include <cstdio>
#include <cstring>

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;
char buff[ 100 ];

vector< string > split() {
  int last = -1, n = strlen( buff );
  vector< string > ret;

  for( int i = 0; i < n; ++i ) {
    if( isdigit( buff[i] ) != last ) ret.push_back( "" );
    last = isdigit( buff[i] );
    ret.back() += buff[i];
  }

  return ret;
}

int main( void )
{
  scanf( "%d", &N );

  for( int i = 0; i < N; ++i ) {
    scanf( "%s", buff );
    vector< string > s = split();

    if( s.size() == 2 ) {
      int c = 1, p = 1;
      int rank = 0;

      for( int j = 0; j < s[0].size()-1; ++j ) c += ( p *= 26 );
      for( int j = 0; j < s[0].size(); ++j ) rank = rank*26+s[0][j]-'A';

      printf( "R%sC%d\n", s[1].c_str(), c+rank );
    }
    else {
      int c, p = 1, cnt = 1; sscanf( s[3].c_str(), "%d", &c ); --c;

      while( ( p *= 26 ) <= c ) ++cnt, c -= p;
      string m = "";

      for( int j = 0; j < cnt; ++j ) {
	buff[0] = 'A'+c%26; buff[1] = 0;
	m = string( buff ) + m;
	c /= 26;
      }

      printf( "%s%s\n", m.c_str(), s[1].c_str() );
    }
  }

  return 0;
}