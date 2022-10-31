#include <bits/stdc++.h>
using namespace std;
#define N 1021
const int mod = 1000000007;
int n , a[ N ] , dp[ N ] , mxlen , dp2[ N ];
char c[ N ];
int main(){
  scanf( "%d" , &n );
  scanf( "%s" , c + 1 );
  for( int i = 0 ; i < 26 ; i ++ )
    scanf( "%d" , &a[ i ] );
  dp[ 0 ] = 1;
  for( int i = 1 ; i <= n ; i ++ ){
    int tmx = n;
    dp2[ i ] = i;
    for( int j = i ; j >= 1 ; j -- ){
      tmx = min( tmx , a[ c[ j ] - 'a' ] );
      if( i - j + 1 > tmx ) break;
      mxlen = max( mxlen , i - j + 1 );
      dp[ i ] = ( dp[ i ] + dp[ j - 1 ] ) % mod;
      dp2[ i ] = min( dp2[ i ] , dp2[ j - 1 ] + 1 );
    }
  }
  printf( "%d\n%d\n%d\n" , dp[ n ] , mxlen , dp2[ n ] );
}