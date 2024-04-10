#include <cstdio>
#include <cstring>

#include <vector>
#include <algorithm>

#define MAXN 100005

using namespace std;


int n, p, a, b, d;
int F[ MAXN ];
int D[ MAXN ];
int in[ MAXN ];

vector< pair< int, pair< int, int > > > Sol;

int main( void )
{
  scanf( "%d%d", &n, &p );

  for( int i = 0; i < p; ++i ) {
    scanf( "%d%d%d", &a, &b, &d );
    F[a] = b;
    D[a] = d;
    ++in[b];
  }

  for( int i = 1; i <= n; ++i ) {
    if( in[i] != 0 || !F[i] ) continue;

    int maks = 1000000000;
    int it = i;

    while( F[it] ) { maks = min( maks, D[it] ); it = F[it]; }

    Sol.push_back( make_pair( i, make_pair( it, maks ) ) );
  }

  sort( Sol.begin(), Sol.end() );

  printf( "%d\n", Sol.size() );

  for( int i = 0; i < Sol.size(); ++i )
    printf( "%d %d %d\n", Sol[i].first, Sol[i].second.first, Sol[i].second.second );

  return 0;
}