#include <cstdio>
#include <cstring>

#include <vector>
#include <algorithm>

using namespace std;
const int P0 = 10007;
const int P1 = 37;

vector< pair< int, int > > v;

char s[ 5000 ];
char a[ 5000 ];
char b[ 5000 ];

int h0[ 5000 ];
int h1[ 5000 ];

int p0[ 5000 ];
int p1[ 5000 ];

pair< int, int > hf( int x, int l ) {
  int ret0 = h0[x+l-1];
  int ret1 = h1[x+l-1];
  if( x ) ret0 -= p0[l]*h0[x-1], ret1 -= p1[l]*h1[x-1];
  return make_pair( ret0, ret1 );
}

int main( void )
{
  scanf( "%s", s );
  scanf( "%s", a );
  scanf( "%s", b );

  int n = strlen( s );
  int na = strlen( a );
  int nb = strlen( b );

  p0[0] = p1[0] = 1;
  h0[0] = h1[0] = s[0];
  for( int i = 1; i < n; ++i ) {
    p0[i] = p0[i-1]*P0;
    h0[i] = h0[i-1]*P0+s[i];
    p1[i] = p1[i-1]*P1;
    h1[i] = h1[i-1]*P1+s[i];
  }

  int ha0 = 0;
  int ha1 = 0;
  for( int i = 0; i < na; ++i ) {
    ha0 = ha0*P0+a[i];
    ha1 = ha1*P1+a[i];
  }
  
  int hb0 = 0;
  int hb1 = 0;
  for( int i = 0; i < nb; ++i ) {
    hb0 = hb0*P0+b[i];
    hb1 = hb1*P1+b[i];
  }

  pair< int, int > ha( ha0, ha1 ), hb( hb0, hb1 );

  for( int i = 0; i < n; ++i ) {
    for( int j = i; j < n; ++j ) {
      if( j-i+1 < max( na, nb ) ) continue;

      if( hf( i, na ) == ha && hf( j-nb+1, nb ) == hb ) {
	v.push_back( hf( i, j-i+1 ) );
      }
    }
  }

  sort( v.begin(), v.end() );
  v.resize( unique( v.begin(), v.end() ) - v.begin() );

  printf( "%d\n", (int)v.size() );

  return 0;
}