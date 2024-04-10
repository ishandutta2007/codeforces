// eddy1021
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
bitset<4096> g[2048];
#define M 505050
int n , m , a[ M ] , b[ M ];
void init(){
  scanf( "%d%d" , &n , &m );
  for( int i = 0 ; i < m ; i ++ ){
    scanf( "%d%d" , &a[ i ] , &b[ i ] );
    g[ a[ i ] ][ b[ i ] ] = 1;
  }
  for( int i = 1 ; i <= n ; i ++ )
    g[ i ][ i + n ] = 1;
}
void solve(){
  for( int r = 1 ; r <= n ; r ++ ){
    int rr = r;
    for( int ri = r ; ri <= n ; ri ++ )
      if( g[ ri ][ r ] ){
        rr = ri;
        break;
      }
    if( rr != r ) swap( g[ r ] , g[ rr ] );
    for( int he = 1 ; he <= n ; he ++ ){
      if( he == r ) continue;
      if( g[ he ][ r ] ) g[ he ] ^= g[ r ];
    }
  }
  for( int i = 0 ; i < m ; i ++ )
    puts( g[ b[ i ] ][ a[ i ] + n ] ? "NO" : "YES" );
}
int main(){
  init();
  solve();
}