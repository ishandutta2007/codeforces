#include <stdio.h>
char c[ 202020 ];
int main(){
  int n, ans = 0;
  scanf( "%d%s" , &n , c );
  int lr = 0 , ud = 0;
  for( int i = 0 ; i < n ; i ++ ){
    int dir = 0;
    if( c[ i ] == 'L' ) dir = 1;
    if( c[ i ] == 'R' ) dir = 2;
    if( c[ i ] == 'U' ) dir = 3;
    if( c[ i ] == 'D' ) dir = 4;
    if( dir < 3 ){
      if( lr && dir != lr ){
        ans ++; ud = 0;
      }
      lr = dir;
    }else{
      if( ud && dir != ud ){
        ans ++; lr = 0;
      }
      ud = dir;
    }
  }
  if( lr || ud ) ans ++;
  printf( "%d\n" , ans );
}