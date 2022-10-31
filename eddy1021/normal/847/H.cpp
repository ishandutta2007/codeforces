/*********************************************/
/*            _     _       _  ___ ____  _   */
/*    ___  __| | __| |_   _/ |/ _ \___ \/ |  */
/*   / _ \/ _` |/ _` | | | | | | | |__) | |  */
/*  |  __/ (_| | (_| | |_| | | |_| / __/| |  */
/*   \___|\__,_|\__,_|\__, |_|\___/_____|_|  */
/*                    |___/                  */
/*                                           */
/*********************************************/
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 101010
LL n , a[ N ] , dp[ N ] , aa[ N ];
int main(){
#ifdef ONLINE_JUDGE
  //freopen( "" , "r" , stdin );
  //freopen( "" , "w" , stdout );
#endif
  cin >> n;
  for( int i = 1 ; i <= n ; i ++ )
    cin >> a[ i ];
  dp[ n ] = 0;
  aa[ n ] = a[ n ];
  for( int i = n - 1 ; i >= 1 ; i -- ){
    aa[ i ] = max( a[ i ] , aa[ i + 1 ] + 1 );
    dp[ i ] = dp[ i + 1 ] + aa[ i ] - a[ i ];
  }
  LL ans = dp[ 1 ];
  LL ldp = 0 , la = -1;
  for( int i = 1 ; i <= n ; i ++ ){
    la = max( la + 1 , a[ i ] );
    ldp += la - a[ i ];
    if( i < n ){
      LL tans = ldp + dp[ i + 1 ];
      if( la == aa[ i + 1 ] )
        tans ++;
      ans = min( ans , tans );
    }
  }
  ans = min( ans , ldp );
  cout << ans << endl;
}