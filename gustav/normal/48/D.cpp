#include <cstdio>
#include <cstring>

#include <vector>
#include <algorithm>

using namespace std;

#define MAX 100005

int n;
int a[ MAX ];
int Sol[ MAX ];
vector< int > v[ MAX ];


int main( void )
{
  scanf( "%d", &n );

  for( int i = 0; i < n; ++i ) {
    scanf( "%d", a+i );
    v[a[i]].push_back( i );
  }

  for( int i = 1; i < MAX-1; ++i ) {
    if( v[i].size() < v[i+1].size() ) {
      printf( "-1\n" );
      return 0;
    }
  }

  int curr = 1;

  while( v[1].size() ) {
    int sz = v[1].size();
    for( int i = 1; i < MAX && v[i].size() == sz; ++i ) {
      Sol[v[i].back()] = curr;
      v[i].pop_back();
    }
    ++curr;
  }

  printf( "%d\n", curr-1 );

  for( int i = 0; i < n; ++i )
    printf( "%d ", Sol[i] );

  putchar( '\n' );

  return 0;
}