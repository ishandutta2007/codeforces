#include <bits/stdc++.h>
using namespace std;
#define N 101010
int n , l[ N ] , d[ N ] , c[ N ];
void init(){
  scanf( "%d" , &n );
  for( int i = 0 ; i < n ; i ++ )
    scanf( "%d" , &l[ i ] );
  for( int i = 0 ; i < n ; i ++ )
    scanf( "%d" , &d[ i ] );
}
int b[ N ];
void solve(){
  vector< pair<int,int> > v;
  for( int i = 0 ; i < n ; i ++ )
    v.push_back( { l[ i ] , d[ i ] } );
  sort( v.begin() , v.end() );
  for( int i = n - 1 ; i >= 0 ; i -- )
    b[ i ] = b[ i + 1 ] + v[ i ].second;
  int ans = b[ 0 ];
  for( int f = 0 , r = 0 ; f < n ; f = r ){
    while( r < n && v[ f ].first == v[ r ].first ) r ++;
    int nd = f - ( ( r - f ) - 1 );
    int sum = 0;
    for( int i = 1 ; nd > 0 ; i ++ ){
      int gt = min( nd , c[ i ] );
      sum += gt * i;
      nd -= gt;
    }
    ans = min( ans , sum + b[ r ] );
    for( int i = f ; i < r ; i ++ )
      c[ v[ i ].second ] ++;
  }
  printf( "%d\n" , ans );
}
int main(){
  init();
  solve();
}