#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define N 303030
int n , k , ans;
vector< pair<pair<int,int>,int> > vv;
void init(){
  scanf( "%d%d" , &n , &k );
  for( int i = 0 ; i < n ; i ++ ){
    int li, ri; scanf( "%d%d" , &li , &ri );
    vv.push_back( { { li , ri } , i } );
  }
}
void output( set< pair<int,int> >& s ){
  printf( "%d\n" , ans );
  for( auto i : s )
    printf( "%d " , i.second + 1 );
  puts( "" );
  exit( 0 );
}
inline void find_ans( bool you_want_to_print_the_answer ){
  for( int iter = 0 ; iter < 2 ; iter ++ ){
    sort( vv.begin() , vv.end() );
    set< pair<int,int> > s;
    for( int i = 0 ; i < n ; i ++ ){
      s.insert( { vv[ i ].first.second , vv[ i ].second } );
      while( (int)s.size() > k )
        s.erase( s.begin() );
      if( (int)s.size() < k ) continue;
      int tans = s.begin()->first - vv[ i ].first.first + 1;
      if( you_want_to_print_the_answer && tans == ans )
        output( s );
      ans = max( ans , tans );
    }
    for( auto& i : vv ){
      i.first.first = -i.first.first;
      i.first.second = -i.first.second;
      swap( i.first.first , i.first.second );
    }
  }
}
void solve(){
  find_ans( 0 );
  if( ans == 0 ){
    printf( "%d\n" , 0 );
    for( int i = 1 ; i <= k ; i ++ )
      printf( "%d%c" , i , " \n"[ i == k ] );
    exit( 0 );
  }
  find_ans( 1 );
}
int main(){
  init();
  solve();
}