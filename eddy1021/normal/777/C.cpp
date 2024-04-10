#include <bits/stdc++.h>
using namespace std;
#define N 101010
vector< vector<int> > a;
int n , m , q , ans[ N ];
vector< pair<int,int> > qry[ N ];
void init(){
  scanf( "%d%d" , &n , &m );
  a.resize( n );
  for( int i = 0 ; i < n ; i ++ ){
    a[ i ].resize( m );
    for( int j = 0 ; j < m ; j ++ )
      scanf( "%d" , &a[ i ][ j ] );
  }
  scanf( "%d" , &q );
  for( int i = 0 ; i < q ; i ++ ){
    int li , ri; scanf( "%d%d" , &li , &ri );
    qry[ ri - 1 ].push_back( { li - 1 , i } );
  }
}
int o[ N ];
void solve(){
  multiset<int> S;
  for( int i = 0 ; i < m ; i ++ )
    S.insert( 0 );
  for( int i = 0 ; i < n ; i ++ ){
    if( i ){
      for( int j = 0 ; j < m ; j ++ )
        if( a[ i ][ j ] < a[ i - 1 ][ j ] ){
          S.erase( S.find( o[ j ] ) );
          o[ j ] = i;
          S.insert( i );
        }
    }
    int bst = *S.begin();
    for( auto j : qry[ i ] )
      if( j.first >= bst )
        ans[ j.second ] = 1;
  }
  for( int i = 0 ; i < q ; i ++ )
    puts( ans[ i ] ? "Yes" : "No" );
}
int main(){
  init();
  solve();
}