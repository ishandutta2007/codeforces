#include <cstdio>
#include <cstring>

#include <map>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 100005

map< int, int > val;

int N;
int a[ MAXN ];
int b[ MAXN ];
int l[ MAXN ];
int bio[ MAXN ];
int inv[ MAXN ];

vector< pair< int, int > > v;

bool lucky( int x ) {
  while( x ) {
    if( x % 10 != 4 && x % 10 != 7 ) return 0;
    x /= 10;
  }
  return 1;
}

void swapaj( int x, int y ) {
  swap( a[x], a[y] );
  v.push_back( make_pair( x, y ) );
}

int main( void )
{
  scanf( "%d", &N );

  for( int i = 0; i < N; ++i ) {
    scanf( "%d", a+i );
    b[i] = a[i];
  }

  sort( b, b + N );

  bool good = 1;

  for( int i = 0; i < N; ++i )
    if( a[i] != b[i] ) good = 0;

  if( good ) {
    printf( "0\n" );
    return 0;
  }

  for( int i = 0; i < N; ++i ) {
    if( lucky( b[i] ) ) l[i] = 1, good = 1;
    if( val.count( b[i] ) ) continue;
    val[b[i]] = i; // mapa!
  }

  if( !good ) {
    puts( "-1" );
    return 0;
  }

  for( int i = 0; i < N; ++i ) {
    int cb = a[i];
    a[i] = val[a[i]];
    val[cb] = val[cb] + 1;
  }

  int pos = -1;

  for( int i = 0; i < N; ++i )
    if( l[a[i]] ) pos = i;

  bio[pos] = 1;
  for( int i = a[pos]; i != pos; i = a[i] )
    bio[i] = 1;

  for( int i = 0; i < N; ++i ) {
    if( bio[i] ) continue;

    bio[i] = 1;
    for( int j = a[i]; j != i; j = a[j] )
      bio[j] = 1;
    
    swapaj( i, pos ); pos = i;
  }

  for( int i = 0; i < N; ++i )
    inv[a[i]] = i;

  for( int i = 0; i < N-1; ++i ) {
    swapaj( pos, inv[pos] );
    pos = inv[pos];
  }

  printf( "%d\n", v.size() );

  for( int i = 0; i < v.size(); ++i )
    printf( "%d %d\n", v[i].first+1, v[i].second+1 );

  return 0;
}