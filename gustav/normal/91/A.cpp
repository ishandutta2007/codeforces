#include <cstdio>
#include <cstring>

char s1[ 10005 ];
char s2[ 1000005 ];

int now[ 26 ];
int link[ 10005 ][ 26 ];

int main( void )
{
  scanf( "%s", s1 ); int n = strlen( s1 );
  scanf( "%s", s2 ); int m = strlen( s2 );

  memset( now, -1, sizeof now );

  for( int i = n-1; i >= 0; --i ) {
    for( int j = 0; j < 26; ++j )
      link[i][j] = now[j];
    now[s1[i]-'a'] = i;
  }

  int pos = 0, Sol = 1;

  for( int i = 0; i < m; ++i ) {
    if( pos == n ) { pos = 0; ++Sol; }
    if( s2[i] != s1[pos] ) {
      pos = link[pos][s2[i]-'a'];
      if( pos == -1 ) pos = 0, ++Sol;
      if( s2[i] != s1[pos] ) {
	pos = link[pos][s2[i]-'a'];
	if( pos == -1 ) { printf( "-1\n" ); return 0; }
      }
    }
    ++pos;
  }

  printf( "%d\n", Sol );


  return 0;
}