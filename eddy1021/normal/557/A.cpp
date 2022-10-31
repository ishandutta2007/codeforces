#include <bits/stdc++.h>
using namespace std;
int n;
int mn[ 3 ] , mx[ 3 ];
int main(){
  scanf( "%d" , &n );
  for( int i = 0 ; i < 3 ; i ++ )
    scanf( "%d%d" , &mn[ i ] , &mx[ i ] );
  for( int i = 0 ; i < 3 ; i ++ ){
    int mmn = 0 , mmx = 0;
    for( int j = i + 1 ; j < 3 ; j ++ )
      mmn += mn[ j ] , mmx += mx[ j ];
    for( int j = mx[ i ] ; j >= mn[ i ] ; j -- )
      if( j + mmn <= n && n <= j + mmx ){
        printf( "%d%c" , j , " \n"[ i == 2 ] );
        n -= j;
        break;
      }
  }
}