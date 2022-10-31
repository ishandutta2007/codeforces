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
#define N 202020
vector<int> ans[ N ];
int n , a[ N ];
int main(){
#ifdef ONLINE_JUDGE
  //freopen( "" , "r" , stdin );
  //freopen( "" , "w" , stdout );
#endif
  cin >> n;
  for( int i = 1 ; i <= n ; i ++ )
    cin >> a[ i ];
  int at = 1;
  ans[ 0 ].push_back( a[ 1 ] );
  for( int i = 2 ; i <= n ; i ++ ){
    int bl = 0 , br = at - 1 , ba = at;
    while( bl <= br ){
      int bmid = (bl + br) >> 1;
      if( a[ i ] > ans[ bmid ].back() )
        ba = bmid , br = bmid - 1;
      else
        bl = bmid + 1;
    }
    ans[ ba ].push_back( a[ i ] );
    at = max( ba + 1 , at );
  }
  for( int i = 0 ; i < at ; i ++ )
    for( size_t j = 0 ; j < ans[ i ].size() ; j ++ )
      printf( "%d%c" , ans[ i ][ j ] , " \n"[ j + 1 == ans[ i ].size() ] );
}