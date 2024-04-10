#include <bits/stdc++.h>
using namespace std;
#define N 1021
int n , m , q , v[ N ][ N ];
typedef pair<int,int> PII;
PII r[ N ][ N ], d[ N ][ N ];
void init(){
  scanf( "%d%d%d" , &n , &m , &q );
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 1 ; j <= m ; j ++ )
      scanf( "%d" , &v[ i ][ j ] );
  for( int i = 0 ; i <= n + 1 ; i ++ )
    for( int j = 0 ; j <= m + 1 ; j ++ ){
      r[ i ][ j ] = { i , j + 1 };
      d[ i ][ j ] = { i + 1 , j };
    }
}
#define X first
#define Y second
inline void print(){
  PII sp = { 1 , 0 };
  sp = r[ sp.X ][ sp.Y ];
  for( int i = 1 ; i <= n ; i ++ ){
    PII tp = sp;
    for( int j = 1 ; j <= m ; j ++ ){
      printf( "%d%c" , v[ tp.X ][ tp.Y ] , " \n"[ j == m ] );
      tp = r[ tp.X ][ tp.Y ];
    }
    sp = d[ sp.X ][ sp.Y ];
  }
}
inline PII go( int a , int b ){
  PII tp = { 0 , 0 };
  while( b -- ) tp = r[ tp.X ][ tp.Y ];
  while( a -- ) tp = d[ tp.X ][ tp.Y ];
  return tp;
}
void solve(){
  while( q -- ){
    int a, b, c, e, h, w;
    scanf( "%d%d%d%d%d%d" , &a , &b , &c , &e , &h , &w );
    PII a1 = go( a , b - 1 ), a2 = go( c , e - 1 );
    PII b1 = go( a , b + w - 1 ), b2 = go( c , e + w - 1 );
    PII c1 = go( a - 1 , b ), c2 = go( c - 1 , e );
    PII d1 = go( a + h - 1 , b ), d2 = go( c + h - 1 , e );
    for( int i = 0 ; i < h ; i ++ ){
      swap( r[ a1.X ][ a1.Y ] , r[ a2.X ][ a2.Y ] );
      a1 = d[ a1.X ][ a1.Y ];
      a2 = d[ a2.X ][ a2.Y ];
    }
    for( int i = 0 ; i < h ; i ++ ){
      swap( r[ b1.X ][ b1.Y ] , r[ b2.X ][ b2.Y ] );
      b1 = d[ b1.X ][ b1.Y ];
      b2 = d[ b2.X ][ b2.Y ];
    }
    for( int i = 0 ; i < w ; i ++ ){
      swap( d[ c1.X ][ c1.Y ] , d[ c2.X ][ c2.Y ] );
      c1 = r[ c1.X ][ c1.Y ];
      c2 = r[ c2.X ][ c2.Y ];
    }
    for( int i = 0 ; i < w ; i ++ ){
      swap( d[ d1.X ][ d1.Y ] , d[ d2.X ][ d2.Y ] );
      d1 = r[ d1.X ][ d1.Y ];
      d2 = r[ d2.X ][ d2.Y ];
    }
  }
  print();
}
int main(){
  init();
  solve();
}