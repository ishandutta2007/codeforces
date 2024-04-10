#include <cstdio>
#include <cstring>

#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef pair< string, int > psi;
typedef pair< string, string > ps;

#define MAX 1000005

char buff[ 1000 ];

map< char, int > val;
map< psi, int > id;

int ficnt[ MAX ];
int focnt[ MAX ];

int file[ MAX ];
int folder[ MAX ];

vector< int > t[ MAX ];

inline void dfs( int n ) {
   ficnt[n] = file[n];
   focnt[n] = folder[n];
   for( int i = 0; i < t[n].size(); ++i ) {
      dfs( t[n][i] );
      ficnt[n] += ficnt[t[n][i]];
      focnt[n] += focnt[t[n][i]];
   }
}

int main( void )
{
   val['C'] = 0;
   val['D'] = 1;
   val['E'] = 2;
   val['F'] = 3;
   val['G'] = 4;

   int next = 5;

   while( scanf( "%s", buff ) != EOF ) {
      int n = strlen( buff );
      int dad = val[buff[0]];

      for( int i = 2, j; i < n; i = j ) {
	 for( j = i+1; j < n && buff[j] != '\\'; ++j );
	 string fn = "";
	 for( int k = i+1; k < j; ++k ) fn += buff[k];
	 if( buff[j] == '\\' ) { 
	    int ndad;
	    if( !id.count( psi( fn, dad ) ) ) { 
	       id[ psi( fn, dad ) ] = next++;
	       ndad = id[ psi( fn, dad ) ];
	       t[ dad ].push_back( ndad );
	    }
	    ndad = id[ psi( fn, dad ) ];
	    folder[ ndad ] = 1;
	    dad = ndad;
	 }
	 else { 
	    int ndad;
	    if( !id.count( psi( fn, dad ) ) ) {
	       id[ psi( fn, dad ) ] = next++;
	       ndad = id[ psi( fn, dad ) ];
	       t[ dad ].push_back( ndad );
	    }
	    ndad = id[ psi( fn, dad ) ];
	    file[ ndad ] = 1;
	    dad = ndad;
	 }
      }

   }

   int SolFi = 0;
   int SolFo = 0;

   for( int i = 0; i < 5; ++i ) {
      for( int j = 0; j < t[i].size(); ++j ) {
	 dfs( t[i][j] );
	 SolFi = max( SolFi, ficnt[t[i][j]] );
	 SolFo = max( SolFo, focnt[t[i][j]] );
      }
   }

   printf( "%d %d\n", SolFo-1, SolFi );

   return 0;
}