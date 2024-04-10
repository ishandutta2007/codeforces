#include <cstdio>
#include <cstring>

#include <vector>
#include <algorithm>

using namespace std;

#define MAXK 1000005

int N, K;
char s[ MAXK ];
char c[ MAXK ];
vector< int > p[ 26 ];

int Sol[ 26 ][ MAXK*2 ];


int main( void )
{
   scanf( "%d%d", &N, &K );
   scanf( "%s", s );

   for( int i = 0; i < K; ++i )
      p[s[i]-'a'].push_back( i );

   for( int i = 0; i < 26; ++i ) {
      int pos = 0;
      for( int j = 0; j < 2*MAXK; ++j ) {
	 if( pos == p[i].size() ) Sol[i][j] = -1;
	 else {
	    while( pos+1 < p[i].size() && abs( p[i][pos+1]-j ) < abs( p[i][pos]-j ) ) ++pos; 
	    Sol[i][j] = abs( p[i][pos]-j );
	 }
      }
   }

   for( int i = 0; i < N; ++i ) {
      scanf( "%s", c ); int n = strlen( c );
      long long Ans = 0;
      for( int j = 0; j < n; ++j )
	 Ans += ( Sol[c[j]-'a'][j] == -1 ) ? n : Sol[c[j]-'a'][j];
      printf( "%I64d\n", Ans );
   }

   return 0;
}