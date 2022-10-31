#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 1048576
int n , a[ N ] , p[ N ];
int main(){
  scanf( "%d" , &n );
  for( int i = 1 ; i <= n ; i ++ )
    scanf( "%d" , &a[ i ] );
  LL s = 0 , ans = 0;
  for( int i = 1 ; i <= n ; i ++ ){
    s += i - p[ a[ i ] ];
    p[ a[ i ] ] = i;
    ans += s;
  }
  ans = ans + ans - n;
  double fans = (double)ans / ( (LL)n * n );
  printf( "%.12f\n" , fans );
}