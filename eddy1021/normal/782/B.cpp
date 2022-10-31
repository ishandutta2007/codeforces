#include <bits/stdc++.h>
using namespace std;
#define N 101010
int n , x[ N ] , v[ N ];
void init(){
  scanf( "%d" , &n );
  for( int i = 0 ; i < n ; i ++ )
    scanf( "%d" , &x[ i ] );
  for( int i = 0 ; i < n ; i ++ )
    scanf( "%d" , &v[ i ] );
}
bool okay( double t ){
  double lb = -1e9 , rb = 1e9;
  for( int i = 0 ; i < n and lb < rb ; i ++ ){
    lb = max( lb , x[ i ] - v[ i ] * t );
    rb = min( rb , x[ i ] + v[ i ] * t );
  }
  return lb < rb;
}
void solve(){
  double l = 0 , r = 1e9;
  for( int i = 0 ; i < 80 ; i ++ ){
    double m = ( l + r ) * 0.5;
    if( okay( m ) ) r = m;
    else l = m;
  }
  printf( "%.12f\n" , ( l + r ) * 0.5 );
}
int main(){
  init();
  solve();
}