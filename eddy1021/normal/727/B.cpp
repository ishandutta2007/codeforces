#include <bits/stdc++.h>
using namespace std;
char c[ 1021 ];
int pr[ 1021 ];
inline int vl( int l , int r ){
  int ret = 0;
  for( int i = l ; i < r ; i ++ )
    ret = ret * 10 + c[ i ] - '0';
  return ret;
}
inline void go( int l , int r ){
  if( r - l > 3 && c[ r - 3 ] == '.' ){
    pr[ 0 ] += vl( r - 2 , r );
    r -= 3;
  }
  for( int rr = r , i = 1 ; l < rr ; rr -= 4 , i ++ )
    pr[ i ] += vl( max( l , rr - 3 ) , rr );
}
int main(){
  scanf( "%s" , c );
  int len = strlen( c );
  for( int i = 0 ; i < len ; ){
    if( isalpha( c[ i ] ) ) i ++;
    else{
      int j = i;
      while( j < len && !isalpha( c[ j ] ) ) j ++;
      go( i , j );
      i = j;
    }
  }
  if( pr[ 0 ] >= 100 ){
    pr[ 1 ] += pr[ 0 ] / 100;
    pr[ 0 ] %= 100;
  }
  for( int i = 1 ; i < 1000 ; i ++ ){
    pr[ i + 1 ] += pr[ i ] / 1000;
    pr[ i ] %= 1000;
  }
  int lst = 1000;
  while( lst > 1 && pr[ lst ] == 0 ) lst --;
  printf( "%d" , pr[ lst ] );
  for( int i = lst - 1 ; i >= 1 ; i -- )
    printf( ".%03d" , pr[ i ] );
  if( pr[ 0 ] ) printf( ".%02d" , pr[ 0 ] );
  puts( "" );
}