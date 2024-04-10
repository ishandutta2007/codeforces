#include <cstdio>
#include <cstring>

#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 1005
#define MAXL 1005

int N, l;

struct node {
  int comp;
  node *l, *r, *d;
  node() { comp = 0; l = r = d = 0; }
  node( node *D ) { comp = 0; l = r = 0; d = D; }
};

struct length {
  int l, id;
  length( int L, int ID ) { l = L; id = ID; }
};

inline bool operator<( length a, length b ) {
  return ( a.l < b.l );
}

vector< length > L;

node *root;
char Sol[ MAXN ][ MAXL ];

inline int complete( node *n ) { return ( n == 0 ) ? -1 : n->comp; }

inline bool build( int l, int idx ) {
  node *it = root;

  int pos = 0;

  for( int i = l; i > 0; --i ) {
    if( complete( it ) >= i ) return 0;
    if( it->l == 0 || complete( it->l ) < i-1 && i != 1 ) {
      if( it->l == 0 ) it->l = new node( it );
      Sol[idx][pos++] = '0';
      it = it->l;
    }
    else {
      if( it->r == 0 ) it->r = new node( it );
      Sol[idx][pos++] = '1';
      it = it->r;
    }
  }

  while( it != 0 ) {
    it->comp = min( complete( it->l ), complete( it->r ) ) + 1;
    it = it->d;
  }

  return 1;
}

int main( void )
{
  scanf( "%d", &N );
  root = new node();

  bool ok = 1;

  for( int i = 0; i < N; ++i ) {
    scanf( "%d", &l );
    L.push_back( length( l, i ) );
  }

  sort( L.begin(), L.end() );

  for( int i = L.size()-1; i >= 0; --i )
    if( ( ok = build( L[i].l, L[i].id ) ) == 0 ) break;

  if( !ok ) printf( "NO\n" );
  else {
    printf( "YES\n" );
    for( int i = 0; i < N; ++i )
      puts( Sol[i] );
  }

  return 0;
}