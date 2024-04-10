#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL inf = 1000000000000000LL;
#define N 5140
int n , m , x[ N ];
pair<int,int> h[ N ];
LL dp[ 2 ][ N ] , cst[ N ];
int main(){
  scanf( "%d%d" , &n , &m );
  for( int i = 1 ; i <= n ; i ++ )
    scanf( "%d" , &x[ i ] );
  for( int i = 0 ; i < m ; i ++ )
    scanf( "%d%d" , &h[ i ].first , &h[ i ].second );
  sort( x + 1 , x + n + 1 );
  sort( h , h + m );
  LL sc = 0;
  for( int i = 1 ; i <= n ; i ++ ){
    sc += abs( x[ i ] - h[ 0 ].first );
    dp[ 0 ][ i ] = i <= h[ 0 ].second ? sc : inf;
  }
  for( int i = 1 ; i < m ; i ++ ){
    int now = i & 1 , pre = 1 - now;
    for( int j = 1 ; j <= n ; j ++ )
      cst[ j ] = cst[ j - 1 ] + abs( x[ j ] - h[ i ].first );
    deque< pair<int,LL> > dq;
    dq.push_back( { 0 , dp[ pre ][ 0 ] } );
    for( int j = 1 ; j <= n ; j ++ ){
      while( dq.size() and j - dq.front().first > h[ i ].second )
        dq.pop_front();
      dp[ now ][ j ] = min( dp[ pre ][ j ] ,
                            dq.front().second + cst[ j ] );
      while( dq.size() and dp[ pre ][ j ] - cst[ j ] < dq.back().second )
        dq.pop_back();
      dq.push_back( { j , dp[ pre ][ j ] - cst[ j ] } );
    }
  }
  LL ans = dp[ ( m - 1 ) & 1 ][ n ];
  ans = ( ans >= inf ? -1 : ans );
  printf( "%lld\n" , ans );
}