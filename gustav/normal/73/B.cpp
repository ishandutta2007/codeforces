#include <cstdio>
#include <cstring>

#include <set>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define MAXN 100005

int N, M;
char nick[ 25 ], vnick[ 25 ];
int a[ MAXN ];
int b[ MAXN ];

set< pair< int, string > > s, S;
multiset< int > B;

set< pair< int, string > > :: iterator it;
multiset< int > :: iterator jt;

int main( void )
{
  scanf( "%d", &N );

  for( int i = 0; i < N; ++i ) {
    scanf( "%s %d", nick, a+i );
    s.insert( make_pair( -a[i], string( nick ) ) );
  }

  scanf( "%d", &M );

  for( int i = 0; i < M; ++i )
    scanf( "%d", b+i );

  scanf( "%s", vnick );

  sort( b, b + M );

  S = s;

  for( it = S.begin(); it != S.end(); ++it ) {
    if( it->second == string( vnick ) ) {
      pair< int, string > p = *it;
      S.erase( it );
      p.first -= b[M-1];
      S.insert( p );
    }
  }

  int hi = 0;

  while( S.begin()->second != string( vnick ) )
    S.erase( S.begin() ), ++hi;

  pair< int, string > best = *S.begin();
  S.erase( S.begin() );

  for( int i = M-hi-2; i >= 0; --i ) {
    it = --S.end();
    if( make_pair( it->first-b[i], it->second ) < best ) ++hi;
    S.erase( it );
  }

  printf( "%d ", hi+1 );

  S = s;
  
  for( it = S.begin(); it != S.end(); ++it ) {
    if( it->second == string( vnick ) ) {
      pair< int, string > p = *it;
      S.erase( it );
      p.first -= ( N == M ) ? b[0] : 0;
      S.insert( p );
    }
  }

  int lo = 0;
  
  while( S.begin()->second != string( vnick ) ) 
    S.erase( S.begin() ), ++lo;

  for( int i = M-1; i >= ( N == M ); --i )
    B.insert( b[i] );
  
  pair< int, string > worst = *S.begin();
  S.erase( S.begin() );

  for( it = S.begin(); it != S.end(); ++it ) {
    jt = ( it->second < string( vnick ) ) ?
      B.lower_bound( -worst.first + it->first ) :
      B.upper_bound( -worst.first + it->first );

    if( jt != B.end() ) {
      B.erase( jt );
      ++lo;
    }
  }

  printf( "%d\n", lo+1 );

  return 0;
}