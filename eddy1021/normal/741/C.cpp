#include <bits/stdc++.h>
using namespace std;
#define N 202020
vector<int> v[ N ];
int n , clr[ N ] , a[ N ] , b[ N ];
void init(){
  scanf( "%d" , &n );
  for( int i = 1 ; i <= n ; i ++ ){
    scanf( "%d%d" , &a[ i ] , &b[ i ] );
    v[ a[ i ] ].push_back( b[ i ] );
    v[ b[ i ] ].push_back( a[ i ] );
  }
  for( int i = 1 ; i <= n ; i ++ ){
    v[ i * 2 ].push_back( i * 2 - 1 );
    v[ i * 2 - 1 ].push_back( i * 2 );
  }
}
void go( int now , int tclr ){
  clr[ now ] = tclr;
  for( int nxt : v[ now ] )
    if( !clr[ nxt ] )
      go( nxt , tclr ^ 3 );
}
void solve(){
  for( int i = 1 ; i <= n + n ; i ++ )
    if( !clr[ i ] )
      go( i , 1 );
  for( int i = 1 ; i <= n ; i ++ )
    printf( "%d %d\n" , clr[ a[ i ] ] , clr[ b[ i ] ] );
}  
int main(){
  init();
  solve();
}