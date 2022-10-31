#include <bits/stdc++.h>
using namespace std;
string s;
int n , k , l[ 26 ] , r[ 26 ];
int main(){
  cin >> n >> k >> s;
  int len = s.length();
  for( int i = 0 ; i < 26 ; i ++ )
    r[ i ] = -1;
  for( int i = 0 ; i < len ; i ++ )
    r[ s[ i ] - 'A' ] = i;
  for( int i = len - 1 ; i >= 0 ; i -- )
    l[ s[ i ] - 'A' ] = i;
  vector< pair<int,int> > v;
  for( int i = 0 ; i < 26 ; i ++ ){
    if( r[ i ] == -1 ) continue;
    v.push_back( { l[ i ]     , +1 } );
    v.push_back( { r[ i ] + 1 , -1 } );
  }
  sort( v.begin() , v.end() );
  for( size_t il = 0 , ir = 0 ; il < v.size() ; il = ir ){
    while( ir < v.size() and v[ il ].first == v[ ir ].first ) ir ++;
    for( size_t i = il ; i < ir ; i ++ )
      k -= v[ i ].second;
    if( k < 0 ){
      puts( "YES" );
      exit(0);
    }
  }
  puts( "NO" );
}