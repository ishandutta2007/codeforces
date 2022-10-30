#include <bits/stdc++.h>
using namespace std;
int n , m , p[ 10101 ] , l , r , x;
int main(){
  cin >> n >> m;
  for( int i = 1 ; i <= n ; i ++ )
    cin >> p[ i ];
  while( m -- ){
    cin >> l >> r >> x;
    int s = 0;
    for( int i = l ; i <= r ; i ++ )
      if( p[ i ] < p[ x ] ) s ++;
    puts( l + s == x ? "Yes" : "No" );
  }
}