#include <bits/stdc++.h>
using namespace std;
int n , x , s , ans;
vector<int> v;
int main(){
  scanf( "%d%d" , &n , &s );
  for( int i = 0 ; i < n ; i ++ ){
    scanf( "%d" , &x );
    v.push_back( x );
  }
  sort( v.begin(), v.end() );
  if( n == 1 ){
    puts( "0" );
    exit( 0 );
  }
  int ans1 = v[ n - 2 ] - v[ 0 ] + min( abs( s - v[ 0 ] ) , abs( s - v[ n - 2 ] ) );
  int ans2 = v[ n - 1 ] - v[ 1 ] + min( abs( s - v[ 1 ] ) , abs( s - v[ n - 1 ] ) );
  printf( "%d\n" , min( ans1 , ans2 ) );
}