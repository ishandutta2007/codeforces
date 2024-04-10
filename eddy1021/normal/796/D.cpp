#include <bits/stdc++.h>
using namespace std;
#define N 303030
int n , k , d , p[ N ];
vector<int> v[ N ];
int ui[ N ] , vi[ N ] , cc[ N ];
int main(){
  scanf( "%d%d%d" , &n , &k , &d );
  while( k -- ){
    int ci; scanf( "%d" , &ci );
    cc[ ci ] = ci;
  }
  for( int i = 1 ; i < n ; i ++ ){
    scanf( "%d%d" , &ui[ i ] , &vi[ i ] );
    v[ ui[ i ] ].push_back( vi[ i ] );
    v[ vi[ i ] ].push_back( ui[ i ] );
  }
  queue< int > Q;
  for( int i = 1 ; i <= n ; i ++ )
    if( cc[ i ] )
      Q.push( i );
  while( Q.size() ){
    int tn = Q.front(); Q.pop();
    for( int nxt : v[ tn ] ){
      if( cc[ nxt ] ) continue;
      cc[ nxt ] = cc[ tn ];
      Q.push( nxt );
    }
  }
  vector< int > e;
  for( int i = 1 ; i < n ; i ++ )
    if( cc[ ui[ i ] ] != cc[ vi[ i ] ] )
      e.push_back( i );
  printf( "%d\n" , (int)e.size() );
  for( size_t i = 0 ; i < e.size() ; i ++ )
    printf( "%d%c" , e[ i ] , " \n"[ i + 1 == e.size() ] );
}