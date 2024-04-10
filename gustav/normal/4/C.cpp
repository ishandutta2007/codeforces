#include <sstream>
#include <iostream>
#include <string>
#include <map>

using namespace std;

int N; string s;
map< string, int > mapa;

int main( void )
{
   cin >> N;
   for( int i = 0; i < N; ++i ) {
      cin >> s;
      if( mapa[s] ) {
         ostringstream sout; sout << mapa[s];
         ++mapa[s]; s += sout.str();
         cout << s << "\n";
      }
      else cout << "OK\n", ++mapa[s];
   }
   
   return 0;
}