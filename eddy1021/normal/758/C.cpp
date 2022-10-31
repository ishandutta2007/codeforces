#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 111
LL cnt[ N ][ N ];
LL n , m , k , x , y;
int main(){
  cin >> n >> m >> k >> x >> y;
  LL bs = n + max( 0ll , n - 2 );
  LL tms = k / ( bs * m ); k %= ( bs * m );
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 1 ; j <= m ; j ++ )
      cnt[ i ][ j ] = ( i == 1 || i == n ? tms : tms + tms );
  for( int i = 1 ; i <= n && k > 0 ; i ++ )
    for( int j = 1 ; j <= m && k > 0 ; j ++ ){
      cnt[ i ][ j ] ++;
      k --;
    }
  for( int i = n - 1 ; i >= 1 && k > 0 ; i -- )
    for( int j = 1 ; j <= m && k > 0 ; j ++ ){
      cnt[ i ][ j ] ++;
      k --;
    }
  LL mx = -1e18 , mn = 1e18 , mk = cnt[ x ][ y ];
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 1 ; j <= m ; j ++ ){
      mx = max( mx , cnt[ i ][ j ] );
      mn = min( mn , cnt[ i ][ j ] );
    }
  cout << mx << " ";
  cout << mn << " ";
  cout << mk << "\n";
}