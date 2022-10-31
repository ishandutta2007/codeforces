#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
  scanf( "%d" , &n );
  if( n < 6 ){
    puts( "-1" );
  }else{
    printf( "%d %d\n" , 1 , 2 );
    printf( "%d %d\n" , 2 , 3 );
    printf( "%d %d\n" , 2 , 4 );
    for( int i = 5 ; i <= n ; i ++ )
      printf( "%d %d\n" , 1 , i );
  }
  for( int i = 2 ; i <= n ; i ++ )
    printf( "%d %d\n" , i - 1 , i );
}