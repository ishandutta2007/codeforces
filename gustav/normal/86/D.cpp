#include <cmath>
#include <cstdio>
#include <cstring>

#include <vector>
#include <algorithm>

using namespace std;
typedef long long llint;

#define MAXN 200005
#define MAXV 1000005

int N, Q;
int l, r;

llint sum;

int a[ MAXN ];
llint cnt[ MAXV ];
llint Sol[ MAXN ];

struct query {
  int l, r, b, id;
  query() { l = r = b = id = 0; }
  query( int L, int R, int B, int ID ) { l = L; r = R; b = B; id = ID; }
};

inline bool operator<( query a, query b ) {
  if( a.b != b.b ) return ( a.b < b.b );
  return ( a.r < b.r );
}

vector< query > q;

int main( void )
{
  scanf( "%d%d", &N, &Q );

  for( int i = 0; i < N; ++i )
    scanf( "%d", a+i );

  int bsz = 2*int( sqrt( N ) ) + 1;

  for( int i = 0; i < Q; ++i ) {
    scanf( "%d%d", &l, &r ); --l; --r;
    q.push_back( query( l, r, l / bsz, i ) );
  }

  sort( q.begin(), q.end() );

  int l = 0, r = 0;

  for( int i = 0, j; i < Q; i = j ) {
    for( j = i+1; j < Q && q[j].b == q[i].b; ++j );

    sum = 0;

    for( int k = q[i].l; k <= q[i].r; ++k ) {
      sum += 2LL*cnt[a[k]]*a[k] + a[k]; 
      ++cnt[a[k]];
    }

    Sol[q[i].id] = sum;

    l = q[i].l;
    r = q[i].r;

    for( int k = i+1; k < j; ++k ) {
      while( r < q[k].r ) { ++r; sum += 2LL*cnt[a[r]]*a[r] + a[r]; ++cnt[a[r]]; }
      while( l > q[k].l ) { --l; sum += 2LL*cnt[a[l]]*a[l] + a[l]; ++cnt[a[l]]; }
      while( l < q[k].l ) { sum -= 2LL*cnt[a[l]]*a[l] - a[l]; --cnt[a[l]]; ++l; }
      Sol[q[k].id] = sum;
    }

    for( int k = l; k <= r; ++k ) --cnt[a[k]];
  }

  for( int i = 0; i < Q; ++i )
    printf( "%I64d\n", Sol[i] );

  return 0;
}