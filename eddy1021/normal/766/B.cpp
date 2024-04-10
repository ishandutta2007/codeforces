#include <bits/stdc++.h>
using namespace std;
int n , a[ 101010 ];
int main(){
  scanf( "%d" , &n );
  for( int i = 0 ; i < n ; i ++ )
    scanf( "%d" , &a[ i ] );
  sort( a , a + n );
  bool ok = false;
  for( int i = 2 ; i < n ; i ++ )
    if( a[ i - 1 ] + a[ i - 2 ] > a[ i ] )
      ok = true;
  puts( ok ? "YES" : "NO" );
}