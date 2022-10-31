#include <bits/stdc++.h>
using namespace std;
#define N 1021
typedef long long LL;
LL n , dp[ N ];
char k[ N ];
int main(){
  scanf( "%lld" , &n );
  scanf( "%s" , k + 1 );
  int len = strlen( k + 1 );
  for( int i = 1 ; i <= len ; i ++ ){
    dp[ i ] = 2e18;
    LL num = 0 , bs = 1;
    for( int j = i ; j >= 1 ; j -- ){
      num += bs * ( k[ j ] - '0' );
      bs *= 10;
      if( num >= n || bs > 1e10 ) break;
      if( ( (LL)(2e18) - num + n - 1 ) / n < dp[ j - 1 ] ) continue;
      if( k[ j ] == '0' && i != j ) continue;
      dp[ i ] = min( dp[ i ] , dp[ j - 1 ] * n + num );
    }
  }
  printf( "%lld\n" , dp[ len ] );
}