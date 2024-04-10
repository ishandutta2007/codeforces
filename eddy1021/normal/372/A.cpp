// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 505050
LL n , a[ N ];
bool okay( LL x ){
  for( LL i = 1 , j = n - x + 1 ; i <= x ; i ++ , j ++ )
    if( a[ i ] + a[ i ] > a[ j ] )
      return false;
  return true;
}
int main(){
  scanf( "%lld" , &n );
  for( LL i = 1 ; i <= n ; i ++ )
    scanf( "%lld" , &a[ i ] );
  sort( a + 1 , a + n + 1 );
  LL bl = 1 , br = n / 2 , ans = 0;
  while( bl <= br ){
    LL mid = ( bl + br ) >> 1;
    if( okay( mid ) ) ans = mid , bl = mid + 1;
    else br = mid - 1;
  }
  printf( "%lld\n" , n - ans );
}