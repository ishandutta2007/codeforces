#include <bits/stdc++.h>
using namespace std;
vector< int > v[ 2 ];
int n , k;
int main(){
  scanf( "%d" , &n ); while( n -- ){
    scanf( "%d" , &k );
    v[ k % 2 ].push_back( k );
  }
  sort( v[ 0 ].begin() , v[ 0 ].end() );
  sort( v[ 1 ].begin() , v[ 1 ].end() );
  if( v[ 1 ].empty() ) puts( "0" );
  else{
    int ans = accumulate( v[ 0 ].begin() , v[ 0 ].end() , 0 ) +
              accumulate( v[ 1 ].begin() , v[ 1 ].end() , 0 );
    if( (int)v[ 1 ].size() % 2 == 0 )
      ans -= v[ 1 ][ 0 ];
    printf( "%d\n" , ans );
  }
}