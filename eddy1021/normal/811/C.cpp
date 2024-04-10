#include <bits/stdc++.h>
using namespace std;
#define N 5050
int n , a[ N ] , l[ N ] , r[ N ];
int dp[ N ] , tag[ N ];
int main(){
  cin >> n;
  for( int i = 1 ; i <= n ; i ++ ){
    cin >> a[ i ];
    r[ a[ i ] ] = i;
    if( !l[ a[ i ] ] )
      l[ a[ i ] ] = i;
  }
  for( int i = 1 ; i <= n ; i ++ ){
    dp[ i ] = dp[ i - 1 ];
    for( int j = i , lft = i , rgt = i , vl = 0 ; j >= 1 ; j -- ){
      lft = min( lft , l[ a[ j ] ] );
      rgt = max( rgt , r[ a[ j ] ] );
      if( rgt > i ) break;
      if( tag[ a[ j ] ] != i ){
        tag[ a[ j ] ] = i;
        vl ^= a[ j ];
      }
      if( lft == j )
        dp[ i ] = max( dp[ i ] , dp[ j - 1 ] + vl );
    }
  }
  printf( "%d\n" , dp[ n ] );
}