#include <cstdio>
#include <cstring>

#include <vector>
#include <algorithm>

using namespace std;
typedef long long llint;

#define MAXN 100005

int N, root;
int a, b;

llint k[ MAXN ];
llint Sol[ MAXN ];

int dad[ MAXN ], piv;
vector< int > T[ MAXN ];

bool cmpfSol( int a, int b ) {
  if( a == dad[piv] ) return 0;
  if( b == dad[piv] ) return 1;
  return ( Sol[a] > Sol[b] );
}

void solve( int n ) {
  if( n != root ) { --k[n]; ++Sol[n]; }

  for( int i = 0; i < T[n].size(); ++i ) {
    if( T[n][i] == dad[n] ) continue;
    dad[T[n][i]] = n;
    solve( T[n][i] );
  }

  piv = n;
  sort( T[n].begin(), T[n].end(), cmpfSol );

  llint Sum = 0;

  for( int i = 0; i < T[n].size()-1+(n==root); ++i ) {
    if( k[n] ) { --k[n]; Sol[n] += Sol[T[n][i]]+1; }
    Sum += k[T[n][i]];
  }

  Sum = min( Sum, k[n] );
  k[n] -= Sum;

  Sol[n] += 2*Sum;
}

int main( void )
{
  scanf( "%d", &N );

  for( int i = 0; i < N; ++i )
    scanf( "%I64d", k+i );

  for( int i = 0; i < N-1; ++i ) {
    scanf( "%d%d", &a, &b ); --a; --b;
    T[a].push_back( b );
    T[b].push_back( a );
  }

  scanf( "%d", &root ); --root; dad[root] = -1;
  solve( root );

  printf( "%I64d\n", Sol[ root ] );

  return 0;
}