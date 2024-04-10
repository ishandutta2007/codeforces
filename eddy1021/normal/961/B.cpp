#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 101010
int n , k , a[ N ] , t[ N ] , ans;
int main(){
  scanf( "%d%d" , &n , &k );
  for( int i = 1 ; i <= n ; i ++ )
    scanf( "%d" , &a[ i ] );
  for( int i = 1 ; i <= n ; i ++ )
    scanf( "%d" , &t[ i ] );
  for( int i = 1 ; i <= n ; i ++ )
    if( t[ i ] ){
      ans += a[ i ];
      a[ i ] = 0;
    }
  for( int i = 2 ; i <= n ; i ++ )
    a[ i ] += a[ i - 1 ];
  int mst = 0;
  for( int i = k ; i <= n ; i ++ )
    mst = max( mst , a[ i ] - a[ i - k ] );
  cout << ans + mst << endl;
}