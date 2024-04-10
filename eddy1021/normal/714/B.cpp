#include <bits/stdc++.h>
using namespace std;
int n , x;
vector<int> v;
inline bool okay(){
  sort( v.begin() , v.end() );
  v.resize( unique( v.begin() , v.end() ) - v.begin() );
  if( (int)v.size() <= 2 ) return true;
  if( (int)v.size() > 3 ) return false;
  return v[ 2 ] - v[ 1 ] == v[ 1 ] - v[ 0 ];
}
int main(){
  scanf( "%d" , &n ); while( n -- ){
    scanf( "%d" , &x );
    v.push_back( x );
  }
  puts( okay() ? "YES" : "NO" );
}