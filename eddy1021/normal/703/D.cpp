#include <bits/stdc++.h>
using namespace std;
#define N 1010101
int st[ N << 2 ];
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
#define mid ((l+r)>>1)
void modify( int no, int l, int r, int p, int x ){
  st[ no ] ^= x;
  if( l == r ) return;
  if( p <= mid ) modify( L( no ), l, mid, p, x );
  else modify( R( no ), mid+1, r, p, x );
}
int query( int no, int l, int r, int ql, int qr ){
  if( r < ql || l > qr || ql > qr ) return 0;
  if( ql <= l && r <= qr ) return st[ no ];
  return query( L( no ), l, mid, ql, qr ) ^
         query( R( no ), mid+1, r, ql, qr );
}
int n , a[ N ];
int m , ans[ N ];
vector< pair<int,int> > qry[ N ];
void init(){
  scanf( "%d" , &n );
  for( int i = 1 ; i <= n ; i ++ )
    scanf( "%d" , &a[ i ] );
  scanf( "%d" , &m );
  for( int i = 0 ; i < m ; i ++ ){
    int ql, qr; scanf( "%d%d" , &ql , &qr );
    qry[ qr ].push_back( { ql , i } );
  }
}
map<int,int> pre;
void solve(){
  for( int i = 1 ; i <= n ; i ++ ){
    if( pre.count( a[ i ] ) )
      modify( 1, 1, n, pre[ a[ i ] ], a[ i ] );
    pre[ a[ i ] ] = i;
    for( auto tp : qry[ i ] )
      ans[ tp.second ] = query( 1, 1, n, tp.first, i );
  }
  for( int i = 0 ; i < m ; i ++ )
    printf( "%d\n" , ans[ i ] );
}
int main(){
  init();
  solve();
}