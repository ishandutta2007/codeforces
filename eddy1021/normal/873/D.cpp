#include <bits/stdc++.h>
using namespace std;
#define N 101010
int n , k , a[ N ] , ptr;
void go( int l , int r ){
  if( k == 0 or l + 1 == r ){
    for( int i = l ; i < r ; i ++ )
      a[ i ] = ++ ptr;
    return;
  }
  if( k >= 2 ){
    int mid = (l + r) >> 1;
    k -= 2;
    go( mid , r );
    go( l , mid );
  }
}
int main(){
  cin >> n >> k;
  k --;
  go( 0 , n );
  if( k ){
    puts( "-1" );
  }else{
    for( int i = 0 ; i < n ; i ++ )
      printf( "%d%c" , a[ i ] , " \n"[ i + 1 == n ] );
  }
}