#include <bits/stdc++.h>
using namespace std;
#define N 1021
int n , k , a[ N ];
bool out[ N ];
int next( int x ){
  x ++;
  if( x > n ) x = 1;
  while( out[ x ] ){
    x ++;
    if( x > n ) x = 1;
  }
  return x;
}
int main(){
  scanf( "%d%d" , &n , &k );
  for( int i = 0 ; i < k ; i ++ )
    scanf( "%d" , &a[ i ] );
  int now = 0;
  for( int i = 0 ; i < k ; i ++ ){
    now = next( now );
    a[ i ] %= ( n - i );
    while( a[ i ] -- )
      now = next( now );
    out[ now ] = true;
    printf( "%d%c" , now , " \n"[ i + 1 == k ] );
  }
}