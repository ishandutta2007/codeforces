#include <cstdio>
#include <cstring>

#include <map>
#include <set>
#include <algorithm>

using namespace std;

#define MAXN 100005

int N, K;
int a[ MAXN ];

map< int, int > cnt;
set< int > s;

int main( void )
{
  scanf( "%d%d", &N, &K );

  for( int i = 0; i < N; ++i )
    scanf( "%d", a+i );

  for( int i = 0; i < K; ++i ) {
    if( ++cnt[a[i]] == 1 ) s.insert( a[i] );
    else s.erase( a[i] );
  }

  if( s.empty() ) printf( "Nothing\n" );
  else printf( "%d\n", *s.rbegin() );

  int l = 0, r = K-1;

  while( r+1 < N ) {
    ++r;
    if( ++cnt[a[r]] == 1 ) s.insert( a[r] );
    else s.erase( a[r] );
    
    if( --cnt[a[l]] == 1 ) s.insert( a[l] );
    else s.erase( a[l] );

    ++l;

    if( s.empty() ) printf( "Nothing\n" );
    else printf( "%d\n", *s.rbegin() );
  }

  return 0;
}