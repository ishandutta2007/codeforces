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
#define N 111
int n , a[ N ];
int main(){
#ifdef ONLINE_JUDGE
  //freopen( "" , "r" , stdin );
  //freopen( "" , "w" , stdout );
#endif
  cin >> n;
  for( int i = 0 ; i < n ; i ++ )
    cin >> a[ i ];
  a[ n ] = a[ n - 1 ];
  int d = a[ 1 ] - a[ 0 ];
  for( int i = 2 ; i <= n ; i ++ ){
    if( i == n ){
      a[ n ] = a[ n - 1 ] + d;
      break;
    }
    if( a[ i ] - a[ i - 1 ] != d ) break;
  }
  cout << a[ n ] << endl;
}