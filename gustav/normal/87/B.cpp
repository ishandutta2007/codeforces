#include <cstdio>
#include <cstring>

#include <map>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int N; string com, a, b;

map< string, string > def;

string get( string a ) {
  if( a == "void" ) return a;
  if( a == "errtype" ) return a;
  int pos = 0;
  string b = ""; 

  if( a[0] != '&' && a[a.size()-1] != '*' ) {
    if( def.count( a ) == 0 ) return "errtype";
    return get( def[a] );
  }

  while( pos < a.size() && a[pos] == '&' ) ++pos;
  while( pos < a.size() && a[pos] != '*' ) b += a[pos++];
  while( pos < a.size() && a[pos] == '*' ) ++pos;

  if( pos != a.size() ) return "errtype";

  if( b == "" ) return "errtype";
  if( b == "errtype" ) return b;
  else {
    string s = get( b );

    if( s == "errtype" ) return s;

    for( int j = 0; j < a.size() && a[j] == '&'; ++j )
      s = '&' + s;
    for( int j = a.size()-1; j >= 0 && a[j] == '*'; --j )
      s = s + '*';
    while( s[0] == '&' && s[s.size()-1] == '*' )
      s = s.substr( 1, s.size()-2 );

    if( s.size() > 4 && s.substr( s.size()-4, 4 ) == "void" )
      if( s.substr( 0, s.size()-4 ) == string( s.size()-4, '&' ) )
	return "errtype";

    return s;
  }

  return b;
}

int main( void )
{
  scanf( "%d", &N );

  for( int i = 0; i < N; ++i ) {
    cin >> com;

    if( com == "typedef" ) {
      cin >> a >> b;
      def[b] = get( a );
    }
    else {
      cin >> a;
      cout << get( a ) << "\n";
    }
  }

  return 0;
}