#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 202020
LL n , a[ N ];
int main(){
  scanf( "%lld" , &n );
  for( LL i = 1 ; i <= n ; i ++ )
    scanf( "%lld" , &a[ i ] );
  LL sum = accumulate( a , a + n + 1 , 0LL ) , ts = 0;
  for( LL i = 1 ; i <= n ; i ++ ){
    ts += a[ i ];
    if( ts + ts >= sum ){
      printf( "%lld\n" , i );
      exit(0);
    }
  }
}