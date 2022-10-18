#include <cstdio>
#include <cstring>

#include <vector>
#include <algorithm>

using namespace std;
const int off = ( 1 << 17 );
typedef long long llint;

#define mid ( ( x + y ) >> 1 )
#define L( x ) ( ( x ) << ( 1 ) )
#define R( x ) ( L( x ) | ( 1 ) )

int N, Q;
int a, b;
int l, r, T;
int lo, hi;

struct line {
  llint k, l; int id;
  line() { k = l = 0; }
  line( llint K, llint L, int ID ) { k = K; l = L; id = ID; }
};

struct data {
  llint val; int id;
  data() { val = -1; id = 0; }
  data( llint V, int ID ) { val = V; id = ID; }
};

vector< line > t[ off << 1 ];
vector< line > tmp;

inline bool cmpf( line a, line b ) {
  if( a.k != b.k ) return ( a.k < b.k );
  return ( a.l < b.l );
}

inline llint ccw( line a, line b, line c ) {
  return ( a.k*( b.l - c.l ) + b.k*( c.l - a.l ) + c.k*( a.l - b.l ) );
}

inline void build_envelope( int n ) {
  sort( t[n].begin(), t[n].end(), cmpf );
  tmp.clear();

  for( int i = 0; i < t[n].size(); ++i ) {
    while( tmp.size() >= 2 && ccw( tmp[tmp.size()-2], tmp[tmp.size()-1], t[n][i] ) >= 0 )
      tmp.pop_back();
    tmp.push_back( t[n][i] );
  }

  t[n].clear();
  for( int i = 0; i < tmp.size(); ++i )
    t[n].push_back( tmp[i] );
}

inline void build( int n ) {
  if( n >= off ) return;

  build( L( n ) );
  build( R( n ) );

  int pa = 0;
  int pb = 0;

  for( int i = 0; i < t[L(n)].size(); ++i )
    t[n].push_back( t[L(n)][i] );
  
  for( int i = 0; i < t[R(n)].size(); ++i )
    t[n].push_back( t[R(n)][i] );

  build_envelope( n );
}

inline bool operator<( data a, data b ) {
  return ( a.val < b.val );
}

inline data query_node( int n, llint X ) {
  int lo = 0, hi = t[n].size()-1, m;
  while( lo < hi ) {
    m = ( lo + hi ) >> 1;
    if( t[n][m].k*X + t[n][m].l <= t[n][m+1].k*X + t[n][m+1].l ) lo = m+1;
    else hi = m;
  }
  return data( t[n][lo].k*X + t[n][lo].l, t[n][lo].id );
}

data _query( int x, int y, int n, llint X ) {
  if( x >= hi || y <= lo ) return data( -1, 0 );
  if( x >= lo && y <= hi ) return query_node( n, X );
  return max( _query( x, mid, L(n), X ), _query( mid, y, R(n), X ) );
}

inline llint query( int l, int r, llint X ) {
  lo = l; hi = r+1;
  return _query( 0, off, 1, X ).id;
}

int main( void )
{
  scanf( "%d%d", &N, &Q );

  for( int i = 0; i < N; ++i ) {
    scanf( "%d%d", &a, &b );
    t[i+off].push_back( line( b, a, i ) );
  }

  build( 1 );

  for( int i = 0; i < Q; ++i ) {
    scanf( "%d%d%d", &l, &r, &T ); --l; --r;
    printf( "%I64d\n", query( l, r, T )+1 ); ///paziiiiiiiiiiiiii
  }

  return 0;
}