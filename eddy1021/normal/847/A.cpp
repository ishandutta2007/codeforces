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
int n , l[ N ] , r[ N ];
vector<int> w;
bool vst[ N ];
int main(){
#ifdef ONLINE_JUDGE
  //freopen( "" , "r" , stdin );
  //freopen( "" , "w" , stdout );
#endif
  cin >> n;
  for( int i = 1 ; i <= n ; i ++ )
    cin >> l[ i ] >> r[ i ];
  for( int i = 1 ; i <= n ; i ++ )
    if( not vst[ i ] and l[ i ] == 0 ){
      w.push_back( i );
      int now = i;
      while( not vst[ now ] ){
        vst[ now ] = true;
        if( !r[ now ] ){
          w.push_back( now );
          break;
        }
        now = r[ now ];
      }
    }
  for( size_t i = 2 ; i < w.size() ; i += 2 ){
    r[ w[ i - 1 ] ] = w[ i ];
    l[ w[ i ] ] = w[ i - 1 ];
  }
  for( int i = 1 ; i <= n ; i ++ )
    cout << l[ i ] << " " << r[ i ] << endl;
}